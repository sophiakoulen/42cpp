/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausann>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 12:18:55 by skoulen           #+#    #+#             */
/*   Updated: 2023/08/07 12:47:44 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void	*ptr)
{
	_i = 42;
	_f = 3.14;
	_weird.hello = ptr;
	_weird.world = "hello";
}

Data::~Data(){}

Data	&Data::operator=(const Data &rhs)
{
	_i = rhs._i;
	_f = rhs._f;
	_weird = rhs._weird;
	return (*this);
}
