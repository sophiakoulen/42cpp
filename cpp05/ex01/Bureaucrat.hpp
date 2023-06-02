/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:38:56 by skoulen           #+#    #+#             */
/*   Updated: 2023/06/02 17:36:18 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <string>
# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat
{
	public:
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat& cpy);
		~Bureaucrat();
		Bureaucrat&	operator=(const Bureaucrat& rhs);

		const std::string&	getName() const;
		int					getGrade() const;

		void			increaseGrade();
		void			decreaseGrade();

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		void	signForm(Form& f);

	private:
		Bureaucrat();
		
		const std::string	_name;
		int					_grade;
};

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& b);

#endif /* BUREAUCRAT_H */
