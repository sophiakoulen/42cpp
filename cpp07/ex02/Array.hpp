/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausann>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:13:34 by skoulen           #+#    #+#             */
/*   Updated: 2023/08/07 16:52:48 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

template<typename T>
class Array
{
	public:
		Array<T>();
		Array<T>(unsigned int n);
		Array<T>(const Array<T>& a);
		Array<T>&	operator=(const Array<T>& rhs);
		T& 		operator[](unsigned int i) const;
		unsigned int	size() const;

	private:
		void			*ptr;
		unsigned int	_size;
};

# include "Array.tpp"

#endif
