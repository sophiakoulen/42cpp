/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausann>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 11:30:36 by skoulen           #+#    #+#             */
/*   Updated: 2023/08/17 16:43:36 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::~BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const char *filename)
{
	parseDatabase(filename);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& btc)
{
	_database = btc._database;
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
	_database = rhs._database;
	return (*this);
}

void	BitcoinExchange::parseDatabase(const char *filename)
{
	std::ifstream	inputfile;

	inputfile.open(filename);
	if (!inputfile)
	{
		std::cout << "Could not open database '"<< filename << "': " << std::strerror(errno) << std::endl;
		exit(2);
	}

	std::string	line;
	getline(inputfile, line); //skip first line
	while (getline(inputfile, line))
	{
		std::string date;
		std::string	value;

		size_t pos = line.find_first_of(",");
		if (pos == std::string::npos)
		{
			std::cout << "Format error in database" << std::endl;
			exit(3);
		}
		
		date = line.substr(0, pos);
		value = line.substr(pos + 1, line.size());
	
		_database[date] = std::strtod(value.c_str(), 0);
	}
}

void	BitcoinExchange::doInput(const char *filename) const
{
	std::ifstream	inputfile;

	inputfile.open(filename);
	if (!inputfile)
	{
		std::cout << "Error: could not open file '"<< filename << "': " << std::strerror(errno) << std::endl;
		exit(2);
	}

	std::string	line;
	getline(inputfile, line); //skip first line
	while (getline(inputfile, line))
	{
		answerQuery(line);
	}
}

void	BitcoinExchange::answerQuery(const std::string& query) const
{
	std::string	date;
	std::string	amountStr;
	float		amount;
	char*		err_check;

	size_t pos = query.find(" | ");
	if (pos == std::string::npos)
	{
		std::cout << "Error: bad input => " << query << std::endl;
		return ;
	}

	date = query.substr(0, pos);
	amountStr = query.substr(pos + 3, query.size());
	amount = std::strtod(amountStr.c_str(), &err_check);
	
	if (!isValidDate(date) || *err_check != 0)
	{
		std::cout << "Error: bad input => " << query << std::endl;
		return ;
	}

	if (amount < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return ;
	}

	if (amount > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return ;
	}

	std::map<std::string, float>::const_iterator it = _database.upper_bound(date);

	if (it == _database.begin())
	{
		std::cout << "Error: date is too ancient." << std::endl;
		return ;
	}

	it--;

	std::cout << date << " => " << amount << " = " << it->second  * amount << std::endl;
}

bool	BitcoinExchange::isValidDate(const std::string& date) const
{
	std::string	dateCpy;
	std::string	yyyy;
	std::string	mm;
	std::string	dd;
	size_t		pos;
	char		*err_check;

	dateCpy = date;
	pos = dateCpy.find("-");
	if (pos == std::string::npos)
		return false;
	yyyy = dateCpy.substr(0, pos);
	dateCpy = dateCpy.substr(pos + 1, dateCpy.size());
	
	pos = dateCpy.find("-");
	if (pos == std::string::npos)
		return false;
	mm = dateCpy.substr(0, pos);
	dateCpy = dateCpy.substr(pos + 1, dateCpy.size());

	dd = dateCpy;

	int year = std::strtol(yyyy.c_str(), &err_check, 10);
	if (*err_check != 0 || year < 1960 || year > 2060)
		return (false);

	int month = std::strtol(mm.c_str(), &err_check, 10);
	if (*err_check != 0 || month < 1 || month > 12)
		return (false);

	int day = std::strtol(dd.c_str(), &err_check, 10);
	if (*err_check != 0 || day < 1 || day > 31)
		return (false);

	return (true);
}
