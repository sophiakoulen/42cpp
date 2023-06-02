/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:52:06 by skoulen           #+#    #+#             */
/*   Updated: 2023/04/17 11:02:31 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_H
# define AANIMAL_H

# include <string>

class AAnimal
{
	public:
		AAnimal(void);
		AAnimal(const AAnimal& a);
		virtual ~AAnimal(void);
		AAnimal& operator=(const AAnimal& a);

		virtual	void	makeSound(void) const = 0;

		std::string	getType(void) const;

	protected:
		std::string	_type;
};

#endif
