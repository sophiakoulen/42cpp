/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausann>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:30:35 by skoulen           #+#    #+#             */
/*   Updated: 2023/08/07 15:08:56 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.h"

class A
{
	public:
		A& operator=(const A & rhs)
		{
			(void) rhs;
			std::cout << "* Assignement operator called *" << std::endl;
			return (*this);
		}	
};

class B
{
	private:
		B& operator=(const B & rhs)
		{
			(void) rhs;
			std::cout << "* Assignement operator called *" << std::endl;
			return (*this);
		}
};

class C
{
	public:
		const char *id;

		C(const char *str)
		{
			id = str;
		}

		/* this is a weird <= operator that always returns true */
		bool	operator <= (const C & rhs) const
		{
			(void) rhs;
			return (true);
		}

	private:
		C();
};

std::ostream& operator<<(std::ostream& o, const C & c)
{
	o << c.id;
	return (o);
}

int main( void )
{
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	
	double truc = 42;
	double bidule = 42;

	std::cout << "min(truc, bidule) = "<<::min(truc, bidule) << std::endl;
	std::cout << "max(truc, bidule) = "<<::max(truc, bidule) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);

	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	float	e = 42.0f;
	double	f = -35.005;
	(void) e;
	(void) f;

	//cette ligne ne compile pas
	//std::cout << "min (e, f) = "<<::min(e, f) << std::endl;

	A foo;
	A bar;

	::swap(foo, bar);

	//cette ligne ne compile pas
	//std::cout << "min(foo, bar) = "<<::min(foo, bar)<< std::endl;

	B hello;
	B world;
	(void) hello;
	(void) world;

	//cette ligne ne compile pas
	//::swap(hello, world);

	C truc1("truc1");
	C truc2("truc2");

	std::cout << "min(truc1, truc2) = "<<::min(truc1, truc2)<<std::endl;

	return 0;
}
