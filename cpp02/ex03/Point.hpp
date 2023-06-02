/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:22:42 by skoulen           #+#    #+#             */
/*   Updated: 2023/03/31 17:19:26 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

# include <iostream>
# include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(const Point& p);
		Point(const float x, const float y);
		Point& operator=(const Point& p);
		~Point();
		Fixed	getX(void) const;
		Fixed	getY(void) const;

	private:
		const Fixed	_x;
		const Fixed	_y;
};

std::ostream&	operator<<(std::ostream& o, const Point& p);

#endif
