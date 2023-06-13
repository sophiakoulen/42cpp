/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:40:20 by skoulen           #+#    #+#             */
/*   Updated: 2023/06/13 10:01:15 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
# define AFORM_H

# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm(const std::string name, int gradeToSign, int gradeToExecute);
		AForm(const AForm& cpy);
		virtual ~AForm();
		AForm&	operator=(const AForm& rhs);

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

		class FormNotSignedException : public std::exception
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
		void	execute(const Bureaucrat& executor) const;

		const std::string&	getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;

	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

		virtual void action() const = 0;

		AForm();
};

std::ostream&	operator<<(std::ostream& o, const AForm& f);

#endif /* AFORM_H */
