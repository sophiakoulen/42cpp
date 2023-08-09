/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausann>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:36:18 by skoulen           #+#    #+#             */
/*   Updated: 2023/08/09 14:11:02 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main()
{
	/* creating empty array */
	Array<int> arr;
	std::cout << "size of arr: " << arr.size() << std::endl;
	std::cout << "arr: " << arr << std::endl;

	Array<int> arr2(3);
	std::cout << "size of arr2: " << arr2.size() <<std::endl;
	std::cout << "arr2: " << arr2 << std::endl;
	arr2[0] = 1;
	arr2[1] = 2;
	arr2[2] = 3;
	std::cout << "arr2: " << arr2 << std::endl;

	Array<int> arr3(arr2);
	arr3[0] = 42;
	std::cout << "size of arr3: " << arr3.size() << std::endl;
	std::cout << "arr3: " << arr3 << std::endl;
	std::cout << "arr2: " << arr2 << std::endl;

	arr3 = arr;
	std::cout << "arr3: " << arr3 << std::endl;

	Array<Array<float> > arr4(2);
	std::cout << "size of arr4: " << arr4.size() << std::endl;
	std::cout << "arr4: " << arr4 << std::endl;
	arr4[0] = Array<float>(3);
	std::cout << "arr4: " << arr4 << std::endl;
	arr4[0][1] = 3.14f;
	std::cout << "arr4: " << arr4 << std::endl;

	//this throws a std::out_of_range error
	//std::cout << arr[42] << std::endl;
	
	//this throws a std::out_of_range error
	//std::cout << arr[-1] << std::endl;

	return 0;
}
