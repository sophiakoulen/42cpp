/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausann>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 12:53:55 by skoulen           #+#    #+#             */
/*   Updated: 2023/08/07 13:15:57 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Base
{
	public:
		virtual ~Base(){};
};

class A: public Base
{

};

class B: public Base
{

};

class C: public Base
{

};

Base	*generate(void)
{
	int choice = rand() % 3;
	if (choice == 0)
		return (new A());
	else if (choice == 1)
		return (new B());
	else
		return (new C());
}

void	identify(Base *b)
{
	if (dynamic_cast<A *>(b) != NULL)
	   std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(b) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(b) != NULL)
		std::cout << "C" << std::endl;
	else
		std::cout << "other" << std::endl;	
}

void	identify(Base &base)
{
	try
	{
		A& a = dynamic_cast<A&>(base);
		static_cast<void>(a);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (std::bad_cast){}

	try
	{
		B& b = dynamic_cast<B&>(base);
		static_cast<void>(b);
		std::cout << "B" << std::endl;
		return ;
	}
	catch(std::bad_cast){}

	try
	{
		C& c = dynamic_cast<C&>(base);
		static_cast<void>(c);
		std::cout << "C" << std::endl;
		return ;
	}
	catch(std::bad_cast)
	{
		std::cout << "other"<<std::endl;
	}
}

int main()
{
	srand(time(NULL));
	Base *randomObject = generate();
	identify(randomObject);
	identify(*randomObject);
	return 0;
}
