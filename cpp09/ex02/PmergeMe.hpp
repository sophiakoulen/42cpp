/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:00:26 by skoulen           #+#    #+#             */
/*   Updated: 2023/08/13 11:40:17 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_H
# define PMERGE_ME_H

# include <algorithm>

template<typename Container>
class PmergeMe : public Container
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& p);

		template<typename InputIt>
		PmergeMe(InputIt first, InputIt last);
		
		~PmergeMe();
		PmergeMe&	operator=(const PmergeMe& p);

		float	sort(void);

	private:

};

# include "PmergeMe.tpp"

#endif