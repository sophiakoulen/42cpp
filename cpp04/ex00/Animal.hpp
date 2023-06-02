/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:52:06 by skoulen           #+#    #+#             */
/*   Updated: 2023/04/05 15:07:38 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

# include <string>

class Animal
{
	public:
		Animal(void);
		Animal(const Animal& a);
		virtual ~Animal(void);
		Animal& operator=(const Animal& a);

		virtual	void	makeSound(void) const;

		std::string	getType(void) const;

	protected:
		std::string	_type;
};

#endif
