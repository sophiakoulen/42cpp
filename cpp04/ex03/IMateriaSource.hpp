/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:27:59 by skoulen           #+#    #+#             */
/*   Updated: 2023/04/20 12:59:40 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_H
# define IMATERIASOURCE_H

# include <string>
# include "AMateria.hpp"

class IMateriaSource
{
	public:
		virtual				~IMateriaSource(){};
		virtual void		learnMateria(AMateria* m) = 0;
		virtual AMateria*	createMateria(std::string const & type) = 0;
} ;

#endif
