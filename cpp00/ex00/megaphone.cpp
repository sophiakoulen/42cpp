/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:15:28 by skoulen           #+#    #+#             */
/*   Updated: 2023/03/08 11:57:14 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using std::cout;
using std::endl;

int	main(int argc, char	**argv)
{
	if (argc == 1)
	{
		cout<< "* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<endl;
	}
	else
	{
		for (int i = 0; i < argc - 1; i++)
		{
			std::string	str(argv[i + 1]);
			std::string::iterator	it;
			for (it = str.begin(); it != str.end(); it++)
				cout<<(char)std::toupper(*it);
			if (i != argc - 2)
				cout<<" ";
		}
		cout<<endl;
	}
	return (0);
}
