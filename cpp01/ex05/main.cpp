/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:36:21 by skoulen           #+#    #+#             */
/*   Updated: 2023/03/10 18:10:56 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	Harl harl;

	cout<<"DEBUG level:"<<endl;
	harl.complain("debug");
	cout<<endl;

	cout<<"INFO level:"<<endl;
	harl.complain("info");
	cout<<endl;

	cout<<"WARNING level:"<<endl;
	harl.complain("warning");
	cout<<endl;

	cout<<"ERROR level:"<<endl;
	harl.complain("error");
	cout<<endl;

	cout<<"UNKOWN level:"<<endl;
	harl.complain("unkown");
	cout<<endl;
	return (0);
}