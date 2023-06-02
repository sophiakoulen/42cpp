/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:05:34 by skoulen           #+#    #+#             */
/*   Updated: 2023/04/05 12:19:14 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

# include "Animal.hpp"

class Dog: public Animal
{
	public:
		Dog(void);
		Dog(const Dog& d);
		~Dog(void);
		Dog& operator=(const Dog& d);

		void	makeSound(void) const;
};

#endif
