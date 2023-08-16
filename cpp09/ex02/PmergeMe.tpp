/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:01:24 by skoulen           #+#    #+#             */
/*   Updated: 2023/08/16 12:23:54 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename Container>
PmergeMe<Container>::PmergeMe()
{

}

template <typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe<Container>& p):
	Container(p)
{

}

template<typename Container>
template<typename InputIt>
PmergeMe<Container>::PmergeMe(InputIt first, InputIt last):
	Container(first, last)
{

}

template <typename Container>
PmergeMe<Container>::~PmergeMe()
{

}

template <typename Container>
PmergeMe<Container>&	PmergeMe<Container>::operator=(const PmergeMe<Container>& p)
{
	Container::operator=(p);
	return (*this);
}

template <typename Container>
float	PmergeMe<Container>::sort()
{
	struct timeval	tv1;
	struct timeval	tv2;

	gettimeofday(&tv1, 0);
	recursive_sort(Container::begin(), Container::end(), 1);
	std::cout << "FINISHED SORTING!" << std::endl;
	gettimeofday(&tv2, 0);
	return (tv2.tv_sec - tv1.tv_sec) * 1000000 + tv2.tv_usec - tv1.tv_usec;
}

template <typename Container>
void	PmergeMe<Container>::recursive_sort(It begin, It end, size_t step)
{
	std::cout << "Step = " << step << " begin: " << begin - Container::begin() << " end: " << end - Container::begin() << std::endl;

	if (step >= Container::size())
		return ;

	std::ptrdiff_t range = end - begin;

	/* for each pair of chunks, put the largest left */
	It	it;
	for (it = begin; it < end; it += 2 * step)
	{
		if (*it < *(it + step))
			swap_range(it, it + step, it + step, it + 2 * step);
	}

	/* sort the pairs */
	recursive_sort(begin, end, step * 2);

	std::cout << "End of recursive call; step = "<< step << std::endl;

	/* start inserting the chunks */
	for (std::ptrdiff_t i = 0; i < range; i += 2 * step)
	{
		It pos = binary_search(Container::begin(), Container::begin() + i, step, *(Container::begin() + i + step));
		std::cout << "pos: " << pos - Container::begin() << std::endl;
		insert_range(Container::begin() + i + step, Container::begin() + i + 2 * step, pos);
		std::cout << "[" << *this << "]" << std::endl;
	}

	std::cout << "Finished insertion: [" << *this << "]" << std::endl;
}

template <typename Container>
void	PmergeMe<Container>::insert_range(It begin, It end, It pos)
{
	if (pos >= begin && pos <= end)
		throw std::exception();

	Container tmp(begin, end);
	std::ptrdiff_t	offset = pos - Container::begin();
	if (begin < pos)
		offset -= end - begin;
	
	Container::erase(begin, end);
	Container::insert(Container::begin() + offset, tmp.begin(), tmp.end());
}

template <typename Container>
void	PmergeMe<Container>::swap_range(It b1, It e1, It b2, It e2)
{
	if (b2 >= b1 && b2 < e1)
		throw std::exception();

	(void) e2;
	for (unsigned int i = 0; i < std::distance(b1, e1); i++)
		std::swap(*(b1 + i), *(b2 + i));
}

template <typename Container>
typename PmergeMe<Container>::It	PmergeMe<Container>::binary_search(It begin, It end, size_t step, Val target)
{
	It min = begin;
	It max = end;
	It mid;

	std::cout << "binary_search offset min: " << begin - Container::begin() << " offset max: " << end - Container::begin() << " target: " << target << std::endl;
	while (min < max)
	{
		std::cout << "before: min: " << min - Container::begin() << " max: " <<max - Container::begin() << std::endl;
		mid = min + (((max - min) / 2) / step) * step;
		if (*mid > target)
			max = mid;
		else
			min = mid + step;
		std::cout << "after: min: " << min - Container::begin() << " max: " <<max - Container::begin() << std::endl;
	}
	if (min != end && *min <= target)
		min += step;
	return (min);
}

template <typename Container>
std::ostream&	operator<<(std::ostream& o, const PmergeMe<Container>& p)
{
	typename PmergeMe<Container>::const_iterator	it;
	for(it = p.begin(); it != p.end(); )
	{
		o << *it;
		if (++it != p.end())
		   o << " ";	
	}
	return (o);
}
