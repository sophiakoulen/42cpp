/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausann>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:31:10 by skoulen           #+#    #+#             */
/*   Updated: 2023/08/07 13:58:21 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_H
# define WHATEVER_H

template <typename T>
void swap(T& a, T& b)
{
	T tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T const &	min(T const & a, T const & b)
{
	return (a <= b) ? a : b;
}

template <typename T>
T const &	max(T const & a, T const & b)
{
	return (a >= b) ? a : b;
}

#endif
