/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:25:06 by skoulen           #+#    #+#             */
/*   Updated: 2023/04/17 09:34:46 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include <iostream>

using std::cout;
using std::endl;

int	main(void)
{
	Cat c;
	Brain& b1 = c.getBrain();
	b1.ideas[0] = "Hello world, i'm a cat!";
	cout<<c;

	Dog d;
	Brain& b2 = d.getBrain();
	b2.ideas[0] = "Hello world, i'm a dog!";
	cout<<d;

	/* check that copies are deep, that means check if the contents
	 * of brain is copied */
	Cat c2;
	c2 = c;
	cout<<c2;

	Dog d2;
	d2 = d;
	cout<<d;

	/* Array of animal objects */
	Animal*	a[2];
	a[0] = new Cat();
	a[1] = new Dog();

	for (int i = 0; i < 2; i++)
		delete a[i];
}
