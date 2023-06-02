/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:21:44 by skoulen           #+#    #+#             */
/*   Updated: 2023/03/08 14:23:42 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <string>

class Zombie{
	private:
		std::string	_name;
	public:
		Zombie(std::string name);
		~Zombie(void);
		void	announce(void) const;
} ;

#endif