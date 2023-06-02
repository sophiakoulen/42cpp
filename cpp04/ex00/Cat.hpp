/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:32:40 by skoulen           #+#    #+#             */
/*   Updated: 2023/04/05 15:19:49 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

#include "Animal.hpp"

class Cat: public Animal
{
	public:
		Cat(void);
		Cat(const Cat& c);
		~Cat(void);
		Cat& operator=(const Cat& rhs);
	
		void	makeSound(void) const;
};

#endif
