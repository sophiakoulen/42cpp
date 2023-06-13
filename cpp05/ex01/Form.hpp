/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:40:20 by skoulen           #+#    #+#             */
/*   Updated: 2023/06/13 10:27:56 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form(const std::string& name, int gradeToSign, int gradeToExecute);
		Form(const Form& cpy);
		~Form();
		Form&	operator=(const Form& rhs);

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

		class FormAlreadySignedException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		void	beSigned(const Bureaucrat& b);

		const std::string&	getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;

	private:
		const std::string&	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

		Form();
};

std::ostream&	operator<<(std::ostream& o, const Form& f);

#endif /* FORM_H */
