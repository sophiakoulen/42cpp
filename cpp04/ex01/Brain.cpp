/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:05:06 by skoulen           #+#    #+#             */
/*   Updated: 2023/04/17 09:12:07 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

using std::cout;
using std::endl;

Brain::Brain(void)
{
	cout<<"Brain default constructor called"<<endl;
}

Brain::Brain(const Brain& b)
{
	cout<<"Brain copy constructor called"<<endl;
	
	/* perform deep copy of the array */
	for (int i = 0; i < 100; i++)
		ideas[i] = b.ideas[i];
}

Brain::~Brain(void)
{
	cout<<"Brain destructor called"<<endl;
}

Brain&	Brain::operator=(const Brain& b)
{
	cout<<"Brain assignment operator called"<<endl;

	for (int i = 0; i < 100; i++)
		ideas[i] = b.ideas[i];
	
	return (*this);
}

std::ostream&	operator<<(std::ostream& o, const Brain& rhs)
{
	for (int i = 0; i < 100; i++)
	{
		if (!rhs.ideas[i].empty())
			o<<"{"<<rhs.ideas[i]<<"}"<<endl;
	}
	
	return (o);
}
