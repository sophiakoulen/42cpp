/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:32:23 by skoulen           #+#    #+#             */
/*   Updated: 2023/03/08 15:25:14 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <string>

class Zombie{
	private:
		std::string	_name;
	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);
		void	announce(void) const;
		void	setName(std::string name);
} ;

#endif