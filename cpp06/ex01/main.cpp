/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausann>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:51:20 by skoulen           #+#    #+#             */
/*   Updated: 2023/08/07 12:39:44 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include <cassert>

int main()
{
	char truc[] = "hello world";
	Data obj(truc);
	uintptr_t raw = Serializer::serialize(&obj);
	Data *ptr = Serializer::deserialize(raw);
	assert(&obj == ptr);
	return (0);
}
