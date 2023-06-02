/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:39:16 by skoulen           #+#    #+#             */
/*   Updated: 2023/03/08 16:00:18 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int	main()
{
	string	str("HI THIS IS BRAIN");
	string	*stringPTR = &str;
	string	&stringREF = str;

	cout<<"Address of the string: "<<&str<<endl;
	cout<<"Address stored in stringPTR: "<<stringPTR<<endl;
	cout<<"Address of stringREF: "<<&stringREF<<endl;

	cout<<"Value of the string: "<<str<<endl;
	cout<<"Value pointed by stringPTR: "<<*stringPTR<<endl;
	cout<<"Value pointed by stringREF: "<<stringREF<<endl;

	return (0);
}