/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:28:53 by skoulen           #+#    #+#             */
/*   Updated: 2023/04/20 14:12:28 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
# define CHARACTER_H

# include "ICharacter.hpp"
# include "Inventory.hpp"
# include <string>
# include <ostream>

class Character: public ICharacter
{
	public:
		Character(const std::string& name);
		~Character();
		Character(const Character& c);
		Character&	operator=(const Character& rhs);

		const std::string&	getName(void) const;

		void	equip(AMateria *m);
		void	unequip(int idx);
		void	use(int idx, ICharacter& target);

		std::string	serialize() const;

	private:
		std::string	_name;
		Inventory	_inventory;

		Character();
};

std::ostream&	operator<<(std::ostream& o, const Character& rhs);	

#endif
