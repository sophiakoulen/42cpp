/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:32:40 by skoulen           #+#    #+#             */
/*   Updated: 2023/04/17 10:51:35 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

# include "AAnimal.hpp"
# include "Brain.hpp"

# include <ostream>

class Cat: public AAnimal
{
	public:
		Cat(void);
		Cat(const Cat& c);
		~Cat(void);
		Cat& operator=(const Cat& rhs);
	
		void	makeSound(void) const;
		Brain&	getBrain(void) const;

	private:
		Brain	*_brain;
};

std::ostream&	operator<<(std::ostream& o, const Cat& rhs);

#endif
