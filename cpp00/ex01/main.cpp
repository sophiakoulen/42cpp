/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:29:45 by skoulen           #+#    #+#             */
/*   Updated: 2023/03/09 12:44:28 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;

int	main()
{
	PhoneBook	pb;
	std::string	action;

	while (!cin.eof())
	{
		cout<<"Enter a command, either ADD, SEARCH or EXIT"<<endl;
		cout<<"> ";	
		cin>>std::ws; //getting rid of remaining whitespace
		std::getline(cin, action); //reading entire line into string
		if (action == "EXIT" || cin.eof())
			break ;
		else if (action == "ADD")
			pb.add();
		else if (action == "SEARCH")
			pb.search();
		else
			cout<<"Invalid command"<<endl;
	}
	cout<<"exit"<<endl;
	return (0);
}
