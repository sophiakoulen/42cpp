/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:01:24 by skoulen           #+#    #+#             */
/*   Updated: 2023/08/16 17:44:07 by skoulen          ###   ########.fr       */
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

	if (2 * step > Container::size())
		return ;

	int range = end - begin;

	/* for each pair of chunks, put the largest left */
	It	it;
	for (it = begin; end - it >= 2 * (int)step; it += 2 * step)
	{
		if (*it < *(it + step))
			swap_range(it, it + step, it + step, it + 2 * step);
	}

	/* sort the pairs */
	recursive_sort(begin, end, step * 2);

	std::cout << "End of recursive call; step = "<< step << std::endl;

	/* divide the container into two chains:
	 * the main_chain of sorted elements
	 * the pend_chain of elements that need to be inserted into the main chain
	 * the stray_elements remain unsorted yet 
	 * */

	Container	main_chain;
	Container	pend_chain;
	Container	stray_chain;

	for (int i = 0; range - i >= 2 * (int)step; i += 2 * step)
	{
		std::cout << "i: " << i << std::endl;
		main_chain.insert(main_chain.end(), Container::begin() + i, Container::begin() + i + step);
		pend_chain.insert(pend_chain.end(), Container::begin() + i + step, Container::begin() + i + 2 * step);
	}

	if (range % (2 * step) >= step)
	{
		int i = (range / (2 * step)) * 2 * step;
		pend_chain.insert(pend_chain.end(), Container::begin() + i, Container::begin() + i + step); 
	}

	if (range % step != 0)
	{
		int i = (range / step) * step;
		stray_chain.insert(stray_chain.end(), Container::begin() + i, Container::end());
	}

	std::cout << "main_chain: ";
	for (size_t i = 0; i < main_chain.size(); i++)
		std::cout << main_chain[i] << " ";
	std::cout << std::endl;
	
	std::cout << "pend_chain: ";
	for (size_t i = 0; i < pend_chain.size(); i++)
		std::cout << pend_chain[i] << " ";
	std::cout << std::endl;

	std::cout << "stray_chain: ";
	for (size_t i = 0; i < stray_chain.size(); i++)
		std::cout << stray_chain[i] << " ";
	std::cout << std::endl;


	/* start inserting the chunks */
	for (unsigned int i = 0; i < pend_chain.size(); i += step)
	{
		It pos = binary_search(main_chain.begin(), main_chain.end(), step, pend_chain[i]);
		std::cout << "position to insert: " << pos - main_chain.begin() << std::endl;
		std::cout << "range to insert: [" << i << "; " << i + step << "]" << std::endl;
		main_chain.insert(pos, pend_chain.begin() + i, pend_chain.begin() + i + step);
	}

	
	std::cout << "Before operator=: [" << *this << "]" << std::endl;
	Container::operator=(main_chain);
	Container::insert(Container::end(), stray_chain.begin(), stray_chain.end());
	std::cout << "Finished insertion: [" << *this << "]" << std::endl;
}

template <typename Container>
void	PmergeMe<Container>::insert_range(It begin, It end, It pos)
{
	if (end <= begin || (pos > begin && pos <= end))
		throw std::exception();

	Container tmp(begin, end);
	std::ptrdiff_t	offset = pos - Container::begin();
	if (begin < pos)
		offset -= end - begin;

	std::cout << "sizeof range to insert: " << end - begin << std::endl;

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

	while (min < max)
	{
		std::cout << "before: min: " << min - begin << " max: " <<max - begin << std::endl;
		mid = min + (((max - min) / 2) / step) * step;
		if (*mid > target)
			max = mid;
		else
			min = mid + step;
		std::cout << "after: min: " << min - begin << " max: " <<max - begin << std::endl;
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
