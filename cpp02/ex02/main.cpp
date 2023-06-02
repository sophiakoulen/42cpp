/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:01:42 by skoulen           #+#    #+#             */
/*   Updated: 2023/03/31 16:20:02 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

using std::cout;
using std::endl;

int	main(void)
{
	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));
	Fixed const	c(345.12f);
	Fixed const d(-12.12f);

	cout<<"Testing incrementation:"<<endl;
	cout<<a<<endl;
	cout<<++a<<endl;
	cout<<a<<endl;
	cout<<a++<<endl;
	cout<<a<<endl;

	cout<<endl;

	cout<<"Testing min max:"<<endl;
	cout<<Fixed::max(a,b)<<endl;
	cout<<Fixed::min(c, d)<<endl;

	cout<<endl;

	cout<<"Testing multiplication:"<<endl;
	cout<<"3 * 7 = "<<Fixed(3) * Fixed(7)<<endl;
	cout<<"0.75 * 4 = "<<Fixed(0.75f) * Fixed(4)<<endl;
	cout<<"-10 * -100 = "<<Fixed(-10) * Fixed(-100)<<endl;
	cout<<"0.001 * 1000 = "<<Fixed(0.001f) * Fixed(1000)<<endl;
	cout<<"12 * 2.01 = "<<Fixed(12) * Fixed(2.01f)<<endl;
	cout<<"0.01 * 0.01 = "<<Fixed(0.01f) * Fixed(0.01f)<<endl;

	cout<<endl;

	cout<<"Testing addition and subtraction:"<<endl;
	cout<<"2 + -1 = "<<Fixed(2) + Fixed(-1)<<endl;
	cout<<"42 - 42 = "<<Fixed(42) - Fixed(42)<<endl;

	cout<<endl;

	cout <<"Testing division:"<<endl;
	cout<<"42 / 6.2 = "<<Fixed(42) / Fixed(6.2f)<<endl;
	cout<<"500000 / 3 = "<<Fixed(500000) / Fixed(3)<<endl;
	cout<<"32.7 / 0.01 = "<<Fixed(32.7f) / Fixed(0.01f)<<endl;
	cout<<"43 / 9 = "<<Fixed(43) / Fixed(9)<<endl;
	cout<<"43.78 / 3 = "<<Fixed(43.78f) / Fixed(3)<<endl;
	cout<<"42 / 0.1 = "<<Fixed(42) / Fixed(0.1f)<<endl;

	return (0);
}
