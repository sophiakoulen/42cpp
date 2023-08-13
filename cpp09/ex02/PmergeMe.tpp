/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:01:24 by skoulen           #+#    #+#             */
/*   Updated: 2023/08/13 11:38:01 by skoulen          ###   ########.fr       */
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
	std::sort(Container::begin(), Container::end());
	return (0);
}
