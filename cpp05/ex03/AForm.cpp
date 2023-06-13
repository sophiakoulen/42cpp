/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:02:36 by skoulen           #+#    #+#             */
/*   Updated: 2023/06/13 10:00:59 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iostream>

using std::cout;
using std::endl;

AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute):
	_name(name),
	_isSigned(false),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute)
{
	cout<<"AForm "<<_name<<" ctor"<<endl;
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& cpy):
	_name(cpy._name),
	_isSigned(cpy._isSigned),
	_gradeToSign(cpy._gradeToSign),
	_gradeToExecute(cpy._gradeToExecute)
{
	cout<<"AForm "<<_name<<" cpy ctor"<<endl;
}

AForm::~AForm()
{
	cout<<"AForm "<<_name<<" dtor"<<endl;
}

AForm& AForm::operator=(const AForm& rhs)
{
	cout<<"AForm "<<_name<<" cpy assignment operator"<<endl;
	_isSigned = rhs._isSigned;
	return (*this);
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("AForm::GradeTooHighException");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("AForm::GradeTooLowException");
}

const char	*AForm::FormNotSignedException::what() const throw()
{
	return ("AForm::FormNotSignedException");
}

const char	*AForm::FormAlreadySignedException::what() const throw()
{
	return ("AForm::FormAlreadySignedException");
}

void	AForm::beSigned(const Bureaucrat& b)
{
	if (_isSigned)
		throw AForm::FormAlreadySignedException();
	if (_gradeToSign < b.getGrade())
		throw AForm::GradeTooLowException();
	_isSigned = true;
}

void	AForm::execute(const Bureaucrat& b) const
{
	if (!_isSigned)
		throw AForm::FormNotSignedException();
	if (_gradeToExecute < b.getGrade())
		throw AForm::GradeTooLowException();
	action();
}

const std::string&	AForm::getName() const
{
	return (_name);
}

bool	AForm::getIsSigned() const
{
	return (_isSigned);
}

int		AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int		AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

std::ostream&	operator<<(std::ostream& o, const AForm& f)
{
	o<<"Form "<<f.getName()<<", gradeToSign: "<<f.getGradeToSign()
		<<", gradeToExecute: "<<f.getGradeToExecute()<<", isSigned: "
		<<f.getIsSigned()<<endl;
	return (o);
}
