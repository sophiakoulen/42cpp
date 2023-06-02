/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:01:42 by skoulen           #+#    #+#             */
/*   Updated: 2023/03/30 19:01:44 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

using std::cout;
using std::endl;

int	main(void)
{
	Fixed		a;
	Fixed const	b(10);
	Fixed const	c(42.42f);
	Fixed const	d(b);
	Fixed const e(-45.0f);
	Fixed const f(34.817f);
	Fixed const g(0.0167f);

	a = Fixed(1234.4321f);
	
	cout<<"a is "<<a<<endl;
	cout<<"b is "<<b<<endl;
	cout<<"c is "<<c<<endl;
	cout<<"d is "<<d<<endl;


	cout<<"e is "<<e<<endl;
	cout<<"f is "<<f<<endl;
	cout<<"g is "<<g<<endl;

	cout<<"a is "<<a.toInt()<<" as integer"<<endl;
	cout<<"b is "<<b.toInt()<<" as integer"<<endl;
	cout<<"c is "<<c.toInt()<<" as integer"<<endl;
	cout<<"d is "<<d.toInt()<<" as integer"<<endl;

	cout<<"e is "<<e.toInt()<<" as integer"<<endl;
	cout<<"f is "<<f.toInt()<<" as integer"<<endl;
	cout<<"g is "<<g.toInt()<<" as integer"<<endl;
	
	return (0);
}
