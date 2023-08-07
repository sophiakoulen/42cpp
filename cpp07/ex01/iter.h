/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausann>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:12:29 by skoulen           #+#    #+#             */
/*   Updated: 2023/08/07 15:19:29 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
# define ITER_H

template<typename T>
void	iter(T *arr, size_t size, T (*func)(T))
{
	for (unsigned int i = 0; i < size; i++)
	{
		arr[i] = func(arr[i]);
	}
}

#endif
