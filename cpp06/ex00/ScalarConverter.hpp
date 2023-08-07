/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:31:26 by skoulen           #+#    #+#             */
/*   Updated: 2023/08/07 10:44:15 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#define CHAR	0
#define INT		1
#define FLOAT	2
#define DOUBLE	3
#define INVALID	-1

union u_multi
{
	char	c;
	int		i;
	float	f;
	double	d;
};

class ScalarConverter
{
	public:
		static void	convert(const std::string& str);
	
	private:
		static int	detectType(const std::string& str, void *val);
		static int	toChar(const std::string& str, char *res);
		static int	toInt(const std::string& str, int *res);
		static int	toFloat(const std::string& str, float *res);
		static int	toDouble(const std::string& str, double *res);
		static void	writeAsChar(const std::string& str);
		static void	writeAsInt(const std::string& str);
		static void writeAsFloat(const std::string& str);
		static void writeAsDouble(const std::string& str);

		ScalarConverter();
		ScalarConverter(const ScalarConverter& cpy);
		~ScalarConverter();
		ScalarConverter& operator=(const ScalarConverter& rhs);
};
