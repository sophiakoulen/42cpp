/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausann>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:51:20 by skoulen           #+#    #+#             */
/*   Updated: 2023/08/08 11:40:03 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include <cassert>
#include <iostream>

int main()
{
	char truc[] = "hello world";
	Data obj(truc);

	std::cout << "Pointer of object: " << &obj << std::endl;

	uintptr_t raw = Serializer::serialize(&obj);

	std::cout << "Serialized version: " << raw << std::endl; 
	std::cout << "Serialized version in hex: " << std::hex << raw << std::endl;

	Data *ptr = Serializer::deserialize(raw);

	std::cout << "Deserialized version: " << ptr << std::endl;

	assert(&obj == ptr);
	return (0);
}
