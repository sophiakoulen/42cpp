/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:02:36 by skoulen           #+#    #+#             */
/*   Updated: 2023/06/13 10:29:34 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>

using std::cout;
using std::endl;

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute):
	_name(name),
	_isSigned(false),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute)
{
	cout<<"Form "<<_name<<" ctor"<<endl;
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& cpy):
	_name(cpy._name),
	_isSigned(cpy._isSigned),
	_gradeToSign(cpy._gradeToSign),
	_gradeToExecute(cpy._gradeToExecute)
{
	cout<<"Form "<<_name<<" cpy ctor"<<endl;
}

Form::~Form()
{
	cout<<"Form "<<_name<<" dtor"<<endl;
}

Form& Form::operator=(const Form& rhs)
{
	cout<<"Form "<<_name<<" cpy assignment operator"<<endl;
	_isSigned = rhs._isSigned;
	return (*this);
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Form::GradeTooHighException");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Form::GradeTooLowException");
}

const char	*Form::FormAlreadySignedException::what() const throw()
{
	return ("Form::FormAlreadySignedException");
}

void	Form::beSigned(const Bureaucrat& b)
{
	if (_isSigned)
		throw Form::FormAlreadySignedException();
	if (_gradeToSign < b.getGrade())
		throw Form::GradeTooLowException();
	_isSigned = true;
}

const std::string&	Form::getName() const
{
	return (_name);
}

bool	Form::getIsSigned() const
{
	return (_isSigned);
}

int		Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int		Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

std::ostream&	operator<<(std::ostream& o, const Form& f)
{
	o<<"Form "<<f.getName()<<", gradeToSign: "<<f.getGradeToSign()
		<<", gradeToExecute: "<<f.getGradeToExecute()<<", isSigned: "
		<<f.getIsSigned()<<endl;
	return (o);
}
