/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausann>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:29:25 by skoulen           #+#    #+#             */
/*   Updated: 2023/08/09 11:10:47 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
# define EASYFIND_H

# include <algorithm>
# include <iostream>
# include <iterator>

template<typename Container>
typename Container::iterator	easyfind(Container& c, int target);

template<typename Container>
void	print_iterator(Container& c, typename Container::iterator&it);

# include "easyfind.tpp"

#endif
