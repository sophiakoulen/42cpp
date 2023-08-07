/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausann>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:11:56 by skoulen           #+#    #+#             */
/*   Updated: 2023/08/07 15:54:18 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.h"

template<typename T>
T	plus_42(T item)
{
	return (item + 42);
}

template<typename T>
T	accumulate(T item)
{
	static T sum;
	sum = sum + item;
	return (sum);
}

std::string	revstr(std::string str)
{
	std::string res = str;
	for (unsigned int i = 0; i < str.size(); i++)
		res[i] = str[str.size() - 1 - i];
	return (res);
}

int main()
{
	char str[] = "012345678";
	iter(str, sizeof(str) / sizeof(char) - 1, plus_42);
	std::cout << str << std::endl;

	int	arr[] = {42, 43, 17, -3, 0, INT_MIN};
	iter(arr, sizeof(arr) / sizeof(int), plus_42);
	for (unsigned int i = 0; i < sizeof(arr) / sizeof(int); i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	std::string str_tab[] = {"hello", "world"};
	size_t		str_tab_size = sizeof(str_tab) / sizeof(std::string);
	//cette ligne ne compile pas:
	//iter(str_tab, str_tab_size,  plus_42);
	for (unsigned int i = 0; i < str_tab_size; i++)
		std::cout << str_tab[i] << " ";
	std::cout << std::endl;

	//std::cout << std::string("hello") + 42 << std::endl;

	int		arr2[] = {0, 1, 2, 3, 4, 5};
	size_t	arr2_size = sizeof(arr2) / sizeof(int);
	iter(arr2, arr2_size, accumulate);
	for (unsigned int i = 0; i < arr2_size; i++)
		std::cout << arr2[i] << " ";
	std::cout << std::endl;

	iter(str_tab, str_tab_size,  accumulate);
	for (unsigned int i = 0; i < str_tab_size; i++)
		std::cout << str_tab[i] << " ";
	std::cout << std::endl;

	iter(str_tab, str_tab_size,  revstr);
	for (unsigned int i = 0; i < str_tab_size; i++)
		std::cout << str_tab[i] << " ";
	std::cout << std::endl;

	return 0;
}
