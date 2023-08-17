/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausann>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 11:32:57 by skoulen           #+#    #+#             */
/*   Updated: 2023/08/17 15:57:25 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_H
# define BITCOIN_EXCHANGE_H

# include <fstream>
# include <iostream>
# include <string>
# include <map>
# include <cstdlib>

class BitcoinExchange
{
	public:
		~BitcoinExchange();
		BitcoinExchange(const char *filename);
		BitcoinExchange(const BitcoinExchange& btc);
		BitcoinExchange&	operator=(const BitcoinExchange& rhs);

		void	answerQuery(const std::string& query) const;
		void	doInput(const char *filename) const;

	private:
		BitcoinExchange();
		void	parseDatabase(const char *filename);
		bool	isValidDate(const std::string& date) const;

		std::map<std::string, float>	_database;
};

#endif
