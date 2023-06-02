/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:08:06 by skoulen           #+#    #+#             */
/*   Updated: 2023/04/20 14:03:16 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H
# define AMATERIA_H

#include "ICharacter.hpp"
#include <string>

class ICharacter;

class AMateria
{
	protected:
		std::string	_type;
		AMateria();
	
	public:
		AMateria(std::string const & type);
		AMateria(const AMateria& m);
		virtual ~AMateria(void);
		AMateria& operator=(const AMateria& rhs);

		std::string const & getType() const;

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

};

#endif
