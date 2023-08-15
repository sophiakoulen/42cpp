/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:01:24 by skoulen           #+#    #+#             */
/*   Updated: 2023/08/15 14:21:24 by skoulen          ###   ########.fr       */
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
	gettimeofday(&tv2, 0);
	return (tv2.tv_sec - tv1.tv_sec) * 1000000 + tv2.tv_usec - tv1.tv_usec;
}

template <typename Container>
void	PmergeMe<Container>::recursive_sort(It begin, It end, size_t step)
{
	if (step + 1 >= Container::size())
		return ;

	/* for each pair of chunks, put the largest left */
	It	it;
	for (it = begin; it < end; it += 2 * step)
	{
		if (*it < *(it + step))
			swap_range(it, it + step, it + step + 1, it + 2 * step);
	}

	/* sort the pairs */
	recursive_sort(begin, end, step * 2);

	/* start inserting the chunks */
	for (it = begin; it < end; it +=  2 * step)
	{
		It pos = binary_search(begin, it, step, *(it + step));
		insert_range(it + step, it + 2 * step, pos);
	}
}

template <typename Container>
void	PmergeMe<Container>::insert_range(It begin, It end, It pos)
{
	if (pos >= begin && pos <= end)
		throw std::exception();

	Container tmp(begin, end);
	Container::erase(begin, end);
	
	std::ptrdiff_t	offset = pos - Container::begin();
	if (begin < pos)
		offset -= end - begin;
	Container::insert(Container::begin() + offset, tmp.begin(), tmp.end());
}

template <typename Container>
void	PmergeMe<Container>::swap_range(It b1, It e1, It b2, It e2)
{
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

	while (min != max)
	{
		mid = begin + (end - begin) / 2;
		if (*mid > target)
			max = max - step;
		else
			min = mid;
	}
	return (max);
}
