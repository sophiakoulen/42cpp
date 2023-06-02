/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:55:30 by skoulen           #+#    #+#             */
/*   Updated: 2023/06/02 17:37:00 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

using std::cout;
using std::endl;

Bureaucrat::Bureaucrat(const std::string& name, int grade):
	_name(name), _grade(grade)
{
	cout<<"Bureaucrat "<<_name<<" ctor called"<<endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& cpy):
	_name(cpy._name), _grade(cpy._grade)
{
	cout<<"Bureaucrat "<<_name<<" copy ctor called"<<endl;
}

Bureaucrat::~Bureaucrat()
{
	cout<<"Bureaucrat "<<_name<<" dtor called"<<endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& rhs)
{
	cout<<"Bureaucrat "<<_name<<" assignment operator called"<<endl;
	_grade = rhs._grade;
	return (*this);
}

const std::string&	Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::increaseGrade()
{
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat::decreaseGrade()
{
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

void	Bureaucrat::signForm(Form& f)
{
	try
	{
		f.beSigned(*this);
		cout<<_name<<" signed "<<f.getName()<<endl;
	}
	catch (Form::GradeTooLowException& e)
	{
		cout<<_name<<" couldn't sign "<<f.getName()
			<<" because their grade is too low"<<endl;
	}
}

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& b)
{
	o<<b.getName()<<", bureaucrat grade "<<b.getGrade()<<std::endl;
	return (o);
}
