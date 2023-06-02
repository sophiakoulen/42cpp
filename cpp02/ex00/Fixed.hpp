/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:45:40 by skoulen           #+#    #+#             */
/*   Updated: 2023/03/31 11:16:16 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

class Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed& f);
		Fixed & operator=(const Fixed& rhs);
		~Fixed(void);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
	private:
		int					_value;
		static const int	_float_bits;
};

#endif
