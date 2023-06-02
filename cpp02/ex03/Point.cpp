/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:26:06 by skoulen           #+#    #+#             */
/*   Updated: 2023/04/03 09:51:20 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

using std::cerr;
using std::endl;

Point::Point(void): _x(0), _y(0) { };

Point::Point(const Point& p): _x(p._x), _y(p._y) { };

Point::Point(const float x, const float y): _x(x), _y(y) { };

Point&	Point::operator=(const Point& p)
{
	(void)p;
	cerr<<"Error: using assignment operator but point is constant"<<endl;
	return (*this);
}

Point::~Point(void) { };

Fixed	Point::getX(void) const
{
	return (_x);
}

Fixed	Point::getY(void) const
{
	return (_y);
}

std::ostream&	operator<<(std::ostream& o, const Point& p)
{
	o<<"{ "<<p.getX()<<" ; "<<p.getY()<<" }";
	return (o);
}
