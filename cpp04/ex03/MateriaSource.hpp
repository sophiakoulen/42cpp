/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:58:37 by skoulen           #+#    #+#             */
/*   Updated: 2023/04/20 14:22:32 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_SOURCE_H
# define MATERIA_SOURCE_H

#include "IMateriaSource.hpp"
#include "Inventory.hpp"
#include <string>
#include <ostream>

class MateriaSource: public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& m);
		~MateriaSource();
		MateriaSource&	operator=(const MateriaSource& rhs);

		void		learnMateria(AMateria* m);
		AMateria*	createMateria(std::string const & type);

		std::string	serialize(void) const;

	private:
		Inventory	_inventory;
};

std::ostream&	operator<<(std::ostream& o, const MateriaSource& rhs);

#endif
