/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:01:24 by skoulen           #+#    #+#             */
/*   Updated: 2023/08/17 15:18:00 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename Container>
PmergeMe<Container>::PmergeMe()
{
	_comparison_count = 0;
}

template <typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe<Container>& p):
	Container(p)
{
	_comparison_count = 0;
}

template<typename Container>
template<typename InputIt>
PmergeMe<Container>::PmergeMe(InputIt first, InputIt last):
	Container(first, last)
{
	_comparison_count = 0;
}

template <typename Container>
PmergeMe<Container>::~PmergeMe()
{

}

template <typename Container>
PmergeMe<Container>&	PmergeMe<Container>::operator=(const PmergeMe<Container>& p)
{
	Container::operator=(p);
	_comparison_count = p._comparison_count;
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
	if (2 * step > Container::size())
		return ;

	int range = end - begin;

	/* for each pair of chunks, put the largest left */
	It	it;
	for (it = begin; end - it >= 2 * (int)step; it += 2 * step)
	{
		if (*it < *(it + step))
			swap_range(it, it + step, it + step);
		_comparison_count++;
	}

	/* sort the pairs */
	recursive_sort(begin, end, step * 2);

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
	
	/* insert the chunks from pend_chain using jacobstahl order */
	unsigned int min_pos		= 0; /* what is the lowest position we havent inserted yet */
	unsigned int current_pos	= 0; /* current position we neeed to insert */
	unsigned int max_pos		= 0; /* what is the max position at which we have inserted an element? */
	unsigned int j				= 0; /* keep track of which jacobstahl number we need to retrieve */
	unsigned int inserted_count = 0; /* how many elements have we inserted yet? */
	while (current_pos * step < pend_chain.size())
	{
		max_pos = std::max(max_pos, current_pos);
		int i = current_pos * step;
		It pos = binary_search(main_chain.begin(), main_chain.begin() + i + inserted_count * step, step, pend_chain[i]);
		main_chain.insert(pos, pend_chain.begin() + i, pend_chain.begin() + i + step);
		if (current_pos == min_pos)
		{
			min_pos = max_pos + 1;
			current_pos = min_pos + jacobstahl(j++);
		}
		current_pos--;
		inserted_count++;
	}

	/* insert the remaining elements from pend_chain */
	current_pos = max_pos + 1;
	while (current_pos * step < pend_chain.size())
	{
		int i = current_pos * step;
		It pos = binary_search(main_chain.begin(), main_chain.end(), step, pend_chain[i]);
		main_chain.insert(pos, pend_chain.begin() + i, pend_chain.begin() + i + step);
		current_pos++;
	}

	Container::operator=(main_chain);
	Container::insert(Container::end(), stray_chain.begin(), stray_chain.end());
}

template <typename Container>
void	PmergeMe<Container>::swap_range(It b1, It e1, It b2)
{
	if (b2 >= b1 && b2 < e1)
		throw std::exception();

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
		mid = min + (((max - min) / 2) / step) * step;
		if (*mid > target)
			max = mid;
		else
			min = mid + step;

		_comparison_count++;
	}
	if (min != end)
	{
		if (*min <= target)
			min += step;
		_comparison_count++;
	}
	return (min);
}

template <typename Container>
std::ostream&	operator<<(std::ostream& o, const PmergeMe<Container>& p)
{
	typename PmergeMe<Container>::const_iterator	it;
	for(it = p.begin(); it != p.end() && it - p.begin() < 5; )
	{
		o << *it;
		if (++it != p.end())
		   o << "\t";	
	}
	if (it != p.end())
		o << "[...]";
	return (o);
}

template <typename Container>
size_t	PmergeMe<Container>::jacobstahl(size_t i) const
{
	const size_t numbers[] =
	{
        2u, 2u, 6u, 10u, 22u, 42u, 86u, 170u, 342u, 682u, 1366u,
        2730u, 5462u, 10922u, 21846u, 43690u, 87382u, 174762u, 349526u, 699050u,
        1398102u, 2796202u, 5592406u, 11184810u, 22369622u, 44739242u, 89478486u,
        178956970u, 357913942u, 715827882u, 1431655766u, 2863311530u, 5726623062u,
        11453246122u, 22906492246u, 45812984490u, 91625968982u, 183251937962u,
        366503875926u, 733007751850u, 1466015503702u, 2932031007402u, 5864062014806u,
        11728124029610u, 23456248059222u, 46912496118442u, 93824992236886u, 187649984473770u,
        375299968947542u, 750599937895082u, 1501199875790165u, 3002399751580331u,
        6004799503160661u, 12009599006321322u, 24019198012642644u, 48038396025285288u,
        96076792050570576u, 192153584101141152u, 384307168202282304u, 768614336404564608u,
        1537228672809129216u, 3074457345618258432u, 6148914691236516864u
    };
	return (numbers[i]);
}

template <typename Container>
unsigned int	PmergeMe<Container>::getComparisonCount() const
{
	return _comparison_count;
}
