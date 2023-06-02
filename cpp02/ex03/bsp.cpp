/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:42:38 by skoulen           #+#    #+#             */
/*   Updated: 2023/04/03 09:48:20 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	area(Point const a, Point const b, Point const c);

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	a_total, a1, a2, a3;

	a_total = area(a, b, c);
	a1 = area(a, b, point);
	a2 = area(a, point, c);
	a3 = area(point, b, c);

	return (a1 != Fixed(0) && a2 != Fixed(0) && a3 != Fixed(0)
			&& a1 + a2 + a3 == a_total);
}

static Fixed	area(Point const a, Point const b, Point const c)
{
	return Fixed(0.5f) * Fixed::abs((a.getX() - c.getX()) * (b.getY() - a.getY())
		   - (a.getX() - b.getX()) * (c.getY() - a.getY()));
}

