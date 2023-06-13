/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:55:30 by skoulen           #+#    #+#             */
/*   Updated: 2023/06/13 10:03:20 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

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

void	Bureaucrat::signForm(AForm& f)
{
	try
	{
		f.beSigned(*this);
		cout<<GREEN<<_name<<" signed "<<f.getName()<<RESET<<endl;
	}
	catch (AForm::FormAlreadySignedException& e)
	{
		cout<<RED<<_name<<" couldn't sign "<<f.getName()
			<<" because it had already been signed"<<RESET<<endl;
	}
	catch (AForm::GradeTooLowException& e)
	{
		cout<<RED<<_name<<" couldn't sign "<<f.getName()
			<<" because their grade is too low"<<RESET<<endl;
	}
}

void	Bureaucrat::executeForm(AForm& f)
{
	try
	{
		f.execute(*this);
		cout<<GREEN<<_name<<" executed "<<f.getName()<<RESET<<endl;
	}
	catch (AForm::GradeTooLowException& e)
	{
		cout<<RED<<_name<<" couldn't execute "<<f.getName()
			<<" because their grade is too low"<<RESET<<endl;
	}
	catch (AForm::FormNotSignedException& e)
	{
		cout<<RED<<_name<<" couldn't execute "<<f.getName()
			<<" because it hadn't been signed"<<RESET<<endl;
	}
}

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& b)
{
	o<<b.getName()<<", bureaucrat grade "<<b.getGrade()<<std::endl;
	return (o);
}
