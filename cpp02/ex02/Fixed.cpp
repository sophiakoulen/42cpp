/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:52:47 by skoulen           #+#    #+#             */
/*   Updated: 2023/03/31 16:09:38 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

using std::cout;
using std::endl;

Fixed::Fixed(void): _value(0)
{
	//cout << "Default constructor called" << endl;
	return ;
}

Fixed::Fixed(const Fixed& f)
{
	//cout << "Copy constructor called" << endl;
	*this = f;
	return ;
}

Fixed::Fixed(int const n): _value(n << Fixed::_float_bits)
{
	//cout << "Int constructor called" << endl;
	return ;
}

Fixed::Fixed(float const f):
	_value(roundf(f * (1 << Fixed::_float_bits)))
{ 
	//cout << "Float constructor called" << endl;
	return ;
}

Fixed::~Fixed(void)
{
	//cout << "Destructor called" << endl;
	return ;
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
	//cout << "Copy assignment operator called" << endl;
	this->_value = rhs._value;
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
	//cout << "getRawBits member function called" << endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	//cout << "setRawBits member function called" << endl;
	this->_value = raw;
}

// comparison overloads

bool	Fixed::operator>(const Fixed& rhs) const
{
	return (this->_value > rhs._value);
}

bool	Fixed::operator<(const Fixed& rhs) const
{
	return (this->_value < rhs._value);
}

bool	Fixed::operator>=(const Fixed& rhs) const
{
	return (this->_value >= rhs._value);
}

bool	Fixed::operator<=(const Fixed& rhs) const
{
	return (this->_value <= rhs._value);
}

bool	Fixed::operator==(const Fixed& rhs) const
{
	return (this->_value == rhs._value);
}

bool	Fixed::operator!=(const Fixed& rhs) const
{
	return (this->_value != rhs._value);
}

// arithmetic overloads

Fixed	Fixed::operator+(const Fixed& rhs) const
{
	Fixed	new_f;

	new_f.setRawBits(this->_value + rhs._value);
	return (Fixed(new_f));
}


Fixed	Fixed::operator-(const Fixed& rhs) const
{
	Fixed	new_f;

	new_f.setRawBits(this->_value - rhs._value);
	return (Fixed(new_f));
}

Fixed	Fixed::operator*(const Fixed& rhs) const
{
	Fixed	new_f(this->toFloat() * rhs.toFloat());
	return (Fixed(new_f));
}

Fixed	Fixed::operator/(const Fixed& rhs) const
{
	Fixed	new_f(this->toFloat() / rhs.toFloat());
	return (Fixed(new_f));
}

Fixed&	Fixed::operator++()
{
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp;

	tmp = *this;
	this->_value++;
	return (tmp);
}

Fixed&	Fixed::operator--()
{
	this->_value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp;

	tmp = *this;
	this->_value--;
	return (*this);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b)?a:b;
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b)?a:b;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b)?a:b;
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b)?a:b;
}

const int	Fixed::_float_bits = 8;

std::ostream&	operator<<(std::ostream& o, const Fixed& rhs)
{
	o << rhs.toFloat() ;
	return (o);
}
