/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:01:42 by skoulen           #+#    #+#             */
/*   Updated: 2023/03/31 11:19:27 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

using std::cout;
using std::endl;

int	main(void)
{
	Fixed	a;
	Fixed	b(a);
	Fixed	c;

	c = b;

	cout << a.getRawBits() << endl;
	cout << b.getRawBits() << endl;
	cout << c.getRawBits() << endl;

	a.setRawBits(15);
	cout << a.getRawBits() << endl;
	b = a;
	cout << b.getRawBits() << endl;

//	Fixed const truc;


	return (0);
}
