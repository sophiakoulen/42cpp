/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:17:18 by skoulen           #+#    #+#             */
/*   Updated: 2023/04/20 14:29:52 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

using std::endl;
using std::cout;

int main(void)
{
	MateriaSource	src;

	Ice i;
	Cure c;
	src.learnMateria(&i);


	cout<<src;

	MateriaSource*	src2 = new MateriaSource(src);

	src2->learnMateria(&c);

	cout<<*src2;

	delete src2;

	return (0);
}
