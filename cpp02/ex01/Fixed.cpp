/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:52:47 by skoulen           #+#    #+#             */
/*   Updated: 2023/03/31 11:13:20 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

using std::cout;
using std::endl;

Fixed::Fixed(void): _value(0)
{
	cout << "Default constructor called" << endl;
	return ;
}

Fixed::Fixed(const Fixed& f)
{
	cout << "Copy constructor called" << endl;
	*this = f;
	return ;
}

Fixed::Fixed(int const n): _value(n << Fixed::_float_bits)
{
	cout << "Int constructor called" << endl;
	return ;
}

Fixed::Fixed(float const f):
	_value(roundf(f * (1 << Fixed::_float_bits)))
{ 
	cout << "Float constructor called" << endl;
	return ;
}

Fixed::~Fixed(void)
{
	cout << "Destructor called" << endl;
	return ;
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
	cout << "Copy assignment operator called" << endl;
	this->_value = rhs.getRawBits();
	return (*this);
}

float	Fixed::toFloat(void) const
{
	return (((float)this->_value) /  (1 << Fixed::_float_bits)); 
}

int	Fixed::toInt(void) const
{
	return (roundf((float)this->_value / (1 << Fixed::_float_bits)));
}

int	Fixed::getRawBits(void) const
{
	cout << "getRawBits member function called" << endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	cout << "setRawBits member function called" << endl;
	this->_value = raw;
}

const int	Fixed::_float_bits = 8;

std::ostream & operator<<(std::ostream& o, const Fixed& rhs)
{
	o << rhs.toFloat() ;
	return (o);
}
