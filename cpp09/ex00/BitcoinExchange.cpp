/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausann>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 11:30:36 by skoulen           #+#    #+#             */
/*   Updated: 2023/08/11 17:38:41 by skoulen          ###   ########.fr       */
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
	
	if (err_check == amountStr.c_str())
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
