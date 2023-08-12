/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausann>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:49:12 by skoulen           #+#    #+#             */
/*   Updated: 2023/08/12 11:42:00 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{

}

RPN::~RPN()
{

}

RPN::RPN(const RPN& r)
{
	_s = r._s;
}

RPN&	RPN::operator=(const RPN& r)
{
	_s = r._s;
	return (*this);
}

void	RPN::compute(const std::string& calc)
{
	for (size_t i = 0; i < calc.size(); i++)
	{
		if (calc[i] == '+' || calc[i] == '-' || calc[i] == '*' || calc[i] == '/')
		{

			if (_s.empty())
			{
				std::cout << "Error" << std::endl;
				std::exit(1);
			}
			int b = _s.top();
			_s.pop();	
			if (_s.empty())
			{
				std::cout << "Error" << std::endl;
				std::exit(1);
			}
			int a = _s.top();
			_s.pop();
			
			if (calc[i] == '+')
				_s.push(a + b);
			else if (calc[i] == '-')
				_s.push(a - b);
			else if (calc[i] == '*')
				_s.push(a * b);
			else
				_s.push(a / b);
		}
		else if (calc[i] >= '0' && calc[i] <= '9')
		{
			_s.push(calc[i] - '0');
		}
		else if (!std::isspace(calc[i]))
		{
			std::cout << "Error" << std::endl;
			std::exit(1);
		}
	}
	if (_s.size() != 1)
	{
		std::cout << "Error" << std::endl;
		std::exit(1);
	}
	std::cout << _s.top() << std::endl;
}
