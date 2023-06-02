/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:29:40 by skoulen           #+#    #+#             */
/*   Updated: 2023/04/05 15:51:24 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WRONG_ANIMAL_H
# define WRONG_ANIMAL_H

# include <string>

class WrongAnimal
{
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal& a);
		~WrongAnimal(void);
		WrongAnimal& operator=(const WrongAnimal& a);

		void	makeSound(void) const;

		std::string	getType(void) const;

	protected:
		std::string	_type;
};

#endif
