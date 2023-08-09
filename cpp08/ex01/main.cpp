/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausann>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 11:25:35 by skoulen           #+#    #+#             */
/*   Updated: 2023/08/09 14:04:35 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int main()
{
	Span s1(3);
	s1.addNumber(1);
	s1.addNumber(3);
	std::cout << "s1: " << s1 << std::endl;
	s1.addNumber(6);
	std::cout << "s1: " << s1 << std::endl;

	int arr[] = {17, 3, -1, 4, 78, 42};
	Span s2(arr, arr + sizeof(arr) / sizeof(int));
	std::cout << "s2: " << s2 << std::endl;

	Span s3(1000000);
	for (int i = 0; i < 1000000; i++)
		s3.addNumber(i);

	srand(time(NULL));
	Span s4(1000000);
	for (int i = 0; i < 1000000; i++)
		s4.addNumber(rand() % 10000000);

	int arr2[] = {43, 6, 7, 6};
	Span s5(5);
	for (unsigned int i = 0; i < 4; i++)
		s5.addNumber(arr2[i]);

	Span s6(s5);
	s6.addNumber(17);

	std::cout << "s5: " << s5 << std::endl;
	std::cout << "s6: " << s6 << std::endl;

	s6 = s1;
	
	Span s7(42);
	std::cout << "s7: " << s7 << std::endl;

	std::cout << std::endl;

	try
	{
		std::cout << s7.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "std::exception caught: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << "s1 shortest_span:\t" << s1.shortestSpan() << std::endl;
	std::cout << "s1 longest_span:\t" << s1.longestSpan() << std::endl;
	
	std::cout << std::endl;
	
	std::cout << "s2 shortest_span:\t" << s2.shortestSpan() << std::endl;
	std::cout << "s2 longest_span:\t" << s2.longestSpan() << std::endl;
	
	std::cout << std::endl;
	
	std::cout << "s3 shortest_span:\t" << s3.shortestSpan() << std::endl;
	std::cout << "s3 longest_span:\t" << s3.longestSpan() << std::endl;

	std::cout << std::endl;

	std::cout << "s4 shortest_span:\t" << s4.shortestSpan() << std::endl;
	std::cout << "s4 longest_span:\t" << s4.longestSpan() << std::endl;
	
	std::cout << std::endl;
	
	std::cout << "s5 shortest_span:\t" << s5.shortestSpan() << std::endl;
	std::cout << "s5 longest_span:\t" << s5.longestSpan() << std::endl;

	return (0);
}
