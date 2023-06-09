/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:39:44 by skoulen           #+#    #+#             */
/*   Updated: 2023/06/09 18:02:04 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <climits>
#include <cerrno>
#include <cfloat>
#include <cmath>

using std::cout;
using std::endl;

void	ScalarConverter::convert(const std::string& str)
{
	ScalarConverter::writeAsChar(str);
	ScalarConverter::writeAsInt(str);
	ScalarConverter::writeAsFloat(str);
	ScalarConverter::writeAsDouble(str);
}

int	ScalarConverter::toChar(const std::string& str, char *res)
{
	if (str.length() != 1 || std::isdigit(str[0]))
		return (-1);
	*res = str[0];
	return (0);
}

int	ScalarConverter::toInt(const std::string& str, int *res)
{
	const char * const	start_ptr = str.c_str();
	char *				end_ptr;
	long int			long_res;

	long_res = std::strtol(start_ptr, &end_ptr, 0);
	if (*end_ptr != '\0')
		return (-1);
	if (long_res < (long int) INT_MIN || long_res > (long int) INT_MAX)
		return (-1);
	*res = (int) long_res;
	return (0);
}

int ScalarConverter::toFloat(const std::string& str, float *res)
{
	const char * const	start_ptr = str.c_str();
	char *				end_ptr;
	double				double_res;

	errno = 0;
	double_res = std::strtod(start_ptr, &end_ptr);
	if (*end_ptr != 'f')
		return (-1);
	if (*(end_ptr + 1) != '\0')
		return (-1);
	if (errno == ERANGE)
		return (-1);
	*res = (float) double_res;
	return (0);
}

int ScalarConverter::toDouble(const std::string& str, double *res)
{
	const char * const	start_ptr = str.c_str();
	char *				end_ptr;

	errno = 0;
	*res = std::strtod(start_ptr, &end_ptr);
	if (*end_ptr != '\0')
		return (-1);
	if (errno == ERANGE)
		return (-1);
	return (0);
}

bool ScalarConverter::isChar(const std::string& str)
{
	char res;
	return (ScalarConverter::toChar(str, &res) == 0);
}

bool ScalarConverter::isInt(const std::string& str)
{
	int	res;
	return (ScalarConverter::toInt(str, &res) == 0);
}

bool ScalarConverter::isFloat(const std::string& str)
{
	float res;
	return (ScalarConverter::toFloat(str, &res) == 0);
}

bool ScalarConverter::isDouble(const std::string& str)
{
	double res;
	return (ScalarConverter::toDouble(str, &res) == 0);
}

int	ScalarConverter::detectType(const std::string& str)
{
	if (ScalarConverter::isChar(str))
		return (CHAR);
	else if (ScalarConverter::isInt(str))
		return (INT);
	else if (ScalarConverter::isFloat(str))
		return (FLOAT);
	else if (ScalarConverter::isDouble(str))
		return (DOUBLE);
	else
		return (INVALID);
}

void	ScalarConverter::writeAsChar(const std::string &str)
{
	union u_multi	val;
	
	cout<<"char: ";
	int	type = ScalarConverter::detectType(str);
	if (type == CHAR)
	{
		ScalarConverter::toChar(str, &val.c);
		if (!isprint(val.c))
			cout<<"Non displayable";
		else
			cout<<val.c;	
	}
	else if (type == INT)
	{
		ScalarConverter::toInt(str, &val.i);
		if (val.i < CHAR_MIN || val.i > CHAR_MAX)
			cout<<"impossible";
		else if (!isprint((char) val.i))
			cout<<"Non displayable";
		else
			cout<<(char) val.i;
	}
	else if (type == FLOAT)
	{
		ScalarConverter::toFloat(str, &val.f);
		if (std::isnan(val.f) || (float) (char) val.f - val.f < - FLT_EPSILON || (float) (char) val.f - val.f > FLT_EPSILON)
			cout<<"impossible";
		else if (!isprint((char)val.f))
			cout<<"Non displayable";
		else
			cout<<(char)val.f;
	}
	else if (type == DOUBLE)
	{
		ScalarConverter::toDouble(str, &val.d);
		if (std::isnan(val.d) || (char) val.d - val.d < - DBL_EPSILON || (double) (char) val.d - val.d > DBL_EPSILON)
			cout<<"impossible";
		else if (!isprint((char)val.d))
			cout<<"Non displayable";
		else
			cout<<(char)val.d;
	}
	else
	{
		cout<<"impossible";
	}
	cout<<endl;
}

void	ScalarConverter::writeAsInt(const std::string &str)
{
	union u_multi	val;
	
	cout<<"int: ";
	int	type = ScalarConverter::detectType(str);
	if (type == CHAR)
	{
		ScalarConverter::toChar(str, &val.c);
		cout<<(int)val.c;	
	}
	else if (type == INT)
	{
		ScalarConverter::toInt(str, &val.i);
		cout<<val.i;
	}
	else if (type == FLOAT)
	{
		ScalarConverter::toFloat(str, &val.f);
		if (std::isnan(val.f) || (float) (int) val.f - val.f < - FLT_EPSILON || (float) (int) val.f - val.f > FLT_EPSILON)
			cout<<"impossible";
		else
			cout<<(int)val.f;
	}
	else if (type == DOUBLE)
	{
		ScalarConverter::toDouble(str, &val.d);
		if (std::isnan(val.d) || (double) (int) val.d - val.d < - DBL_EPSILON || (double) (int) val.d - val.d > DBL_EPSILON)
			cout<<"impossible";
		else
			cout<<(int)val.d;
	}
	else
	{
		cout<<"impossible";
	}
	cout<<endl;
}

void	ScalarConverter::writeAsFloat(const std::string &str)
{
	union u_multi	val;
	
	cout<<"float: ";
	cout<<std::fixed;
	std::streamsize ss = cout.precision(1);
	int	type = ScalarConverter::detectType(str);
	if (type == CHAR)
	{
		ScalarConverter::toChar(str, &val.c);
		cout<<(float)val.c<<"f";	
	}
	else if (type == INT)
	{
		ScalarConverter::toInt(str, &val.i);
		cout<<(float)val.i<<"f";
	}
	else if (type == FLOAT)
	{
		ScalarConverter::toFloat(str, &val.f);
		cout<<val.f<<"f";
	}
	else if (type == DOUBLE)
	{
		ScalarConverter::toDouble(str, &val.d);
		if ((double) (float) val.d - val.d < - FLT_EPSILON || (double) (float) val.d - val.d > FLT_EPSILON)
			cout<<"impossible";
		else
			cout<<(float)val.d<<"f";
	}
	else
	{
		cout<<"impossible";
	}
	cout<<endl;
	cout.precision(ss);
	cout.unsetf(std::ios_base::floatfield);
}

void	ScalarConverter::writeAsDouble(const std::string &str)
{
	union u_multi	val;
	
	cout<<"double: ";
	cout<<std::fixed;
	std::streamsize ss = cout.precision(1);
	int	type = ScalarConverter::detectType(str);
	if (type == CHAR)
	{
		ScalarConverter::toChar(str, &val.c);
		cout<<(double)val.c;	
	}
	else if (type == INT)
	{
		ScalarConverter::toInt(str, &val.i);
		cout<<(double)val.i;
	}
	else if (type == FLOAT)
	{
		ScalarConverter::toFloat(str, &val.f);
		cout<<(double)val.f;
	}
	else if (type == DOUBLE)
	{
		ScalarConverter::toDouble(str, &val.d);
		cout<<val.d;
	}
	else
	{
		cout<<"impossible";
	}
	cout<<endl;
	cout.precision(ss);
	cout.unsetf(std::ios_base::floatfield);
}