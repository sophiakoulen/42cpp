/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausann>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:40:55 by skoulen           #+#    #+#             */
/*   Updated: 2023/08/07 12:48:18 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_H
# define SERIALIZER_H

#include "Data.hpp"
#include <cstdint>

class Serializer
{
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer& s);
		Serializer	&operator=(const Serializer& rhs);

	public:
		static uintptr_t	serialize(Data *ptr);
		static Data			*deserialize(uintptr_t raw);
};

#endif
