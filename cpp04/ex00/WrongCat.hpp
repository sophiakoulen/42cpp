/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:34:06 by skoulen           #+#    #+#             */
/*   Updated: 2023/04/05 16:06:44 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WRONG_CAT_H
# define WRONG_CAT_H

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	public:
		WrongCat(void);
		WrongCat(const WrongCat& c);
		~WrongCat(void);
		WrongCat& operator=(const WrongCat& rhs);
	
		void	makeSound(void) const;

		int	huge_array[1200];
};

#endif
