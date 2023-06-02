/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:45:40 by skoulen           #+#    #+#             */
/*   Updated: 2023/04/03 09:49:44 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed& f);
		Fixed(int const n);
		Fixed(float const f);
		Fixed & operator=(Fixed const & rhs);
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		
		float	toFloat(void) const;
		int		toInt(void) const;
		
		//comparison overloads
		bool	operator>(const Fixed& rhs) const;
		bool	operator<(const Fixed& rhs) const;
		bool	operator>=(const Fixed& rhs) const;
		bool	operator<=(const Fixed& rhs) const;
		bool	operator==(const Fixed& rhs) const;
		bool	operator!=(const Fixed& rhs) const;

		//arithmetic overloads
		Fixed	operator+(const Fixed& rhs) const;
		Fixed	operator-(const Fixed& rhs) const;
		Fixed	operator*(const Fixed& rhs) const;
		Fixed	operator/(const Fixed& rhs) const;

		//increment overloads
		Fixed&	operator++();
		Fixed	operator++(int);
		Fixed&	operator--();
		Fixed	operator--(int);

		//min max overloads
		static Fixed&	min(Fixed& a, Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b);
		static Fixed&	max(Fixed& a, Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b);
	
		static Fixed	abs(Fixed f);

	private:
		int					_value;
		static const int	_float_bits;
};

std::ostream& operator<<(std::ostream& o, const Fixed& rhs);

#endif
