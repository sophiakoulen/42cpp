/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:03:05 by skoulen           #+#    #+#             */
/*   Updated: 2023/04/17 09:08:49 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
# define BRAIN_H

#include <string>
#include <ostream>

class Brain
{
	public:
		Brain(void);
		Brain(const Brain& b);
		~Brain(void);
		Brain& operator=(const Brain& rhs);
	
		std::string	ideas[100];
};

std::ostream&	operator<<(std::ostream& o, const Brain& rhs);

#endif
