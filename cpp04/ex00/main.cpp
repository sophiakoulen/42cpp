/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:25:06 by skoulen           #+#    #+#             */
/*   Updated: 2023/04/05 17:47:08 by skoulen          ###   ########.fr       */
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
	const Animal* a = new Animal();
	cout<<endl;
	const Animal* c = new Cat();
	cout<<endl;
	const Animal* d = new Dog();
	cout<<endl;

	cout<<endl;
	cout<<"1. type of c is: "<<c->getType()<<endl;
	cout<<"2. type of d is: "<<d->getType()<<endl;
	cout<<"3. type of a is: "<<a->getType()<<endl;
	cout<<endl;

	cout<<"4. sound of c:"<<endl;
	c->makeSound();
	cout<<"5. sound of d:"<<endl;
	d->makeSound();
	cout<<"6. sound of a:"<<endl;
	a->makeSound();
	cout<<endl;

	cout<<"d.Animal::makeSound()"<<endl;
	d->Animal::makeSound();
	
	delete a;
	cout<<endl;

	delete c;
	cout<<endl;

	delete d;
	cout<<endl;

	Cat b;
	cout<<endl;
	b.makeSound();
	b.Animal::makeSound();
	cout<<endl;

	const WrongAnimal*	wa = new WrongAnimal();
	const WrongCat*		wc1 = new WrongCat();
	const WrongAnimal*	wc = wc1;

	cout<<sizeof(*wa)<<endl;
	cout<<sizeof(*wc1)<<endl;
	cout<<sizeof(*wc)<<endl;

	cout<<"7. type of wa: "<<wa->getType()<<endl;
	cout<<"8. type of wc: "<<wc->getType()<<endl;

	cout<<endl<<"wa sound:"<<endl;
	wa->makeSound();
	cout<<"wc sound:"<<endl;
	wc->makeSound();
	cout<<endl;

	delete wa;
	cout<<endl;

	delete wc;
	cout<<endl;
	return (0);
}
