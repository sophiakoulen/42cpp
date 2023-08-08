/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausann>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:13:34 by skoulen           #+#    #+#             */
/*   Updated: 2023/08/08 13:50:04 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

# include <stdexcept>
# include <iostream>

template<typename T>
class Array
{
	public:
		Array();
		~Array();
		Array(unsigned int n);
		Array(const Array<T>& a);
		Array<T>&	operator=(const Array<T>& rhs);
		T&			operator[](unsigned int i);
		const T&	operator[](unsigned int i) const;
		unsigned int	size() const;

	private:
		T				*_ptr;
		unsigned int	_size;
};

template<typename T>
std::ostream&	operator<<(std::ostream& o, const Array<T>& a);

# include "Array.tpp"

#endif
