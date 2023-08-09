/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausann>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 09:34:56 by skoulen           #+#    #+#             */
/*   Updated: 2023/08/09 11:10:37 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.h"
#include <vector>
#include <list>
#include <iostream>

int	main()
{
	int arr1[] = {0, 1, 2, 42, 57};
	std::vector<int>	vec;
	for (unsigned int i = 0; i < sizeof(arr1)/sizeof(int); i++)
		vec.push_back(arr1[i]);

	int arr2[] = {-1, 0, 1, 1, 1, 42};
	std::list<int>	lst;
	for (unsigned int i = 0; i < sizeof(arr2)/sizeof(int); i++)
		lst.push_back(arr2[i]);

	std::vector<int>::iterator		vec_it = easyfind(vec, 42);
	std::list<int>::iterator		lst_it = easyfind(lst, -1);
	std::list<int>::iterator		foo_it = easyfind(lst, 1);
	std::list<int>::iterator		bar_it = easyfind(lst, 4242);

	std::cout << "*vec_it: "; print_iterator(vec, vec_it); std::cout << std::endl; 
	std::cout << "*lst_it: "; print_iterator(lst, lst_it); std::cout << std::endl;
	std::cout << "*foo_it: "; print_iterator(lst, foo_it); std::cout << std::endl;
	std::cout << "*bar_it: "; print_iterator(lst, bar_it); std::cout << std::endl;

	/* accessing the end() iterator results in undefined behaviour */
	//this line segfaults
	//std::cout << "*vec.end(): " << *vec.end() << std::endl;
	
	//this line prints '6' huh?
	//std::cout << "*lst.end(): " << *lst.end() << std::endl;
	
	return 0;
}

