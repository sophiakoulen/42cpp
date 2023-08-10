/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausann>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:28:25 by skoulen           #+#    #+#             */
/*   Updated: 2023/08/10 17:59:42 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>

int main()
{
	MutantStack<int> s;
	s.push(5);
	s.push(17);

	MutantStack<int>::iterator	it = s.begin();
	std::cout << *it << std::endl;
	++it;
	std::cout << *it << std::endl;
	int& ref = *it;
	ref = 42;
	std::cout << *it << std::endl;

	std::cout << std::endl;
	while (!s.empty())
	{
		std::cout << s.top() << std::endl;
		s.pop();
	}

	return 0;
}
