/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:45:40 by skoulen           #+#    #+#             */
/*   Updated: 2023/03/30 17:33:05 by skoulen          ###   ########.fr       */
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

	private:
		int					_value;
		static const int	_float_bits;
};

std::ostream& operator<<(std::ostream& o, const Fixed& rhs);

#endif
