/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inventory.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:21:54 by skoulen           #+#    #+#             */
/*   Updated: 2023/04/20 12:29:38 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INVENTORY_H
# define INVENTORY_H

#include "AMateria.hpp"
#include <string>

class Inventory
{
	public:
		Inventory();
		Inventory(const Inventory& i);
		~Inventory();
		Inventory&	operator=(const Inventory& rhs);

		AMateria**	get();		
		AMateria**	get(int idx);
		AMateria**	get(const std::string& type);

		std::string	serialize() const;

	private:
		AMateria*	_inventory[4];
};

#endif
