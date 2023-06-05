/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 17:36:02 by skoulen           #+#    #+#             */
/*   Updated: 2023/06/05 18:33:48 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
# define INTERN_H

#include "AForm.hpp"

class AForm;

class Intern
{
	public:
		Intern();
		Intern(const Intern& cpy);
		~Intern();
		Intern& operator=(const Intern& rhs);
	
		AForm*	makeForm(std::string name, std::string target);
	
	private:
		AForm*	RRFFactory(std::string target) const;
		AForm*	SCFFactory(std::string target) const;
		AForm*	PPFFactory(std::string target) const;
};

#endif
