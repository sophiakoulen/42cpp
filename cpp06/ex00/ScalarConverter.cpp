/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:39:44 by skoulen           #+#    #+#             */
/*   Updated: 2023/08/07 12:13:10 by skoulen          ###   ########.fr       */
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
	if (long_res < static_cast<long int>(INT_MIN) || long_res > static_cast<long int>(INT_MAX))
		return (-1);
	*res = static_cast<int>(long_res);
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
	*res = static_cast<float>(double_res);
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

int	ScalarConverter::detectType(const std::string& str, void *val)
{
	if (ScalarConverter::toChar(str, reinterpret_cast<char *>(val)) == 0)
		return (CHAR);
	else if (ScalarConverter::toInt(str, reinterpret_cast<int *>(val)) == 0)
		return (INT);
	else if (ScalarConverter::toFloat(str, reinterpret_cast<float *>(val)) == 0)
		return (FLOAT);
	else if (ScalarConverter::toDouble(str, reinterpret_cast<double *>(val)) == 0)
		return (DOUBLE);
	else
		return (INVALID);
}

void	ScalarConverter::writeAsChar(const std::string &str)
{
	union u_multi	val;
	char			res;
	bool			possible = false;

	cout<<"char: ";
	int	type = ScalarConverter::detectType(str, reinterpret_cast<void *>(&val));
	if (type == CHAR)
	{
		possible = true;
		res = *reinterpret_cast<char *>(&val);
	}
	else if (type == INT)
	{
		int	*i = reinterpret_cast<int *>(&val);
		if (*i >= CHAR_MIN || *i <= CHAR_MAX)
		{
			possible = true;
			res = static_cast<char>(*i);
		}
	}
	else if (type == FLOAT)
	{
		float	*f = reinterpret_cast<float *>(&val); 
		if (!std::isnan(*f) && *f >= CHAR_MIN && *f <= CHAR_MAX)
		{
			possible = true;
			res = static_cast<char>(*f);
		}
	}
	else if (type == DOUBLE)
	{
		double	*d = reinterpret_cast<double *>(&val);
		if (!std::isnan(*d) && *d >= CHAR_MIN && *d <= CHAR_MAX)
		{
			possible = true;
			res = static_cast<char>(*d);
		}
	}
	if (!possible)
		cout << "impossible";
	else if (isprint(res))
		cout << res;
	else
		cout << "Non displayable";
	cout<<endl;
}

void	ScalarConverter::writeAsInt(const std::string &str)
{
	union u_multi	val;
	
	cout<<"int: ";
	int	type = ScalarConverter::detectType(str, &val);
	if (type == CHAR)
	{
		char	*c = reinterpret_cast<char *>(&val);
		cout<<static_cast<int>(*c);
	}
	else if (type == INT)
	{
		int	*i = reinterpret_cast<int *>(&val);
		cout<<*i;
	}
	else if (type == FLOAT)
	{
		float	*f = reinterpret_cast<float *>(&val);
		if (std::isnan(*f) || *f < INT_MIN || *f > INT_MAX)
			cout<<"impossible";
		else
			cout<<static_cast<int>(*f);
	}
	else if (type == DOUBLE)
	{
		double	*d = reinterpret_cast<double *>(&val);
		if (std::isnan(*d) || *d < INT_MIN || *d > INT_MAX)
			cout<<"impossible";
		else
			cout<<static_cast<int>(*d);
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
	int	type = ScalarConverter::detectType(str, reinterpret_cast<void *>(&val));
	if (type == CHAR)
	{
		char	*c = reinterpret_cast<char *>(&val);
		cout<<static_cast<float>(*c)<<"f";	
	}
	else if (type == INT)
	{
		int	*i = reinterpret_cast<int *>(&val);
		cout<<static_cast<float>(*i)<<"f";
	}
	else if (type == FLOAT)
	{
		float	*f = reinterpret_cast<float *>(&val);
		cout<<*f<<"f";
	}
	else if (type == DOUBLE)
	{
		double	*d = reinterpret_cast<double *>(&val);
		cout<<static_cast<float>(*d)<<"f";
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
	int	type = ScalarConverter::detectType(str, reinterpret_cast<void *>(&val));
	if (type == CHAR)
	{
		char	*c = reinterpret_cast<char *>(&val);
		cout<<static_cast<double>(*c);	
	}
	else if (type == INT)
	{
		int	*i = reinterpret_cast<int *>(&val);
		cout<<static_cast<double>(*i);
	}
	else if (type == FLOAT)
	{
		float	*f = reinterpret_cast<float *>(&val);
		cout<<static_cast<double>(*f);
	}
	else if (type == DOUBLE)
	{
		double	*d = reinterpret_cast<double *>(&val);
		cout<<static_cast<double>(*d);
	}
	else
	{
		cout<<"impossible";
	}
	cout<<endl;
	cout.precision(ss);
	cout.unsetf(std::ios_base::floatfield);
}
