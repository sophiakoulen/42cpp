/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:46:15 by skoulen           #+#    #+#             */
/*   Updated: 2023/06/02 16:24:31 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	try
	{
		Bureaucrat	*dave = new Bureaucrat("Dave", 42);
		delete dave;
	} catch (std::exception& e)
	{
		cout<<"something went wrong: "<<e.what()<<endl;
	}

	try
	{
		Bureaucrat	*charles = new Bureaucrat("Charles", 0);
		delete charles;
	} catch (std::exception& e)
	{
		cout<<"something went wrong: "<<e.what()<<endl;
	}
}
