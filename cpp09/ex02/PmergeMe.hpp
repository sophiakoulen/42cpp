/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:00:26 by skoulen           #+#    #+#             */
/*   Updated: 2023/08/17 11:43:38 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_H
# define PMERGE_ME_H

# include <algorithm>
# include <sys/time.h>
# include <iostream>

template<typename Container>
class PmergeMe : public Container
{
	private:
		typedef typename Container::iterator	It;
		typedef typename It::value_type			Val;

		unsigned int	_comparison_count;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& p);

		template<typename InputIt>
		PmergeMe(InputIt first, InputIt last);
		
		~PmergeMe();
		PmergeMe&	operator=(const PmergeMe& p);

		float			sort(void);
		void			recursive_sort(It begin, It end, size_t step);
		void			insert_range(It begin, It end, It pos);
		void			swap_range(It b1, It e1, It b2, It e2);
		It				binary_search(It begin, It end, size_t step, Val target);
		size_t			jacobstahl(size_t i) const;
		unsigned int	getComparisonCount() const;
};

template<typename Container>
std::ostream&	operator<<(std::ostream& o, const PmergeMe<Container>& p);

# include "PmergeMe.tpp"

#endif
