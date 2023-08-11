/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausann>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:28:25 by skoulen           #+#    #+#             */
/*   Updated: 2023/08/11 10:26:21 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <algorithm>

int main()
{
	MutantStack<int> s;
	s.push(5);
	s.push(17);
	s.push(-3);
	s.push(17);
	s.push(0);
	s.push(-1);

	MutantStack<int>::iterator	it;

	it = s.begin();
	++it;
	--it;

	std::cout << "Iterating the stack, from begin() to end():" << std::endl;
	for (it = s.begin(); it != s.end(); it++)
		std::cout << *it << std::endl;

	std::cout << std::endl;
	std::cout << "Adding +3 to all items..." << std::endl;
	for (it = s.begin(); it != s.end(); ++it)
		*it = *it + 3;

	std::cout << std::endl;
	std::cout << "Iterating the stack, from begin() to end():" << std::endl;
	for (it = s.begin(); it != s.end(); ++it)
		std::cout << *it << std::endl;

	std::cout << std::endl;

	std::ptrdiff_t c = std::count(s.begin(), s.end(), 20);
	std::cout << "Number of elements equal to 20: " << c << std::endl;
	
	std::cout << std::endl;

	int sequence[] = {20, 0};
	MutantStack<int>::iterator seq = std::search(s.begin(), s.end(), sequence, sequence + sizeof(sequence) / sizeof(int));
	std::cout << "The sequence appears in the stack: " << std::boolalpha << ((seq != s.end()) ? true : false) << std::endl;

	std::cout << std::endl;

	it = --s.end();
	s.pop();
	s.push(1024);
	std::cout << "Last element of the stack is: " << *it << std::endl; 
	
	std::cout << std::endl;
	
	std::cout << "Actual content from stack, from top to bottom: " << std::endl;
	while (!s.empty())
	{
		std::cout << s.top() << std::endl;
		s.pop();
	}

	return 0;
}
