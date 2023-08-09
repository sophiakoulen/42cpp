/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausann>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:22:38 by skoulen           #+#    #+#             */
/*   Updated: 2023/08/09 14:17:39 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<typename T>
Array<T>::Array()
{
	_ptr = new T[0];
	_size = 0;
}

template<typename T>
Array<T>::~Array()
{
	delete[] _ptr;
}

template<typename T>
Array<T>::Array(unsigned int n)
{
	_ptr = new T[n];
	_size = n;	
}

template<typename T>
Array<T>::Array(const Array<T>& a):
	_ptr(new T[a._size]),
	_size(a._size)
{
	for (unsigned int i = 0; i < _size; i++)
		_ptr[i] = a._ptr[i];
}

template<typename T>
Array<T>&	Array<T>::operator=(const Array<T>& rhs)
{
	delete[] _ptr;
	_size = rhs._size;
	_ptr = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
		_ptr[i] = rhs._ptr[i];
	return (*this);
}

template<typename T>
T&	Array<T>::operator[](unsigned int i)
{
	if (i < 0 || i >= _size)
		throw std::out_of_range("Array");
	return _ptr[i];
}

template<typename T>
const T& Array<T>::operator[](unsigned int i) const
{
	if (i < 0 || i >= _size)
		throw std::out_of_range("Array");
	return _ptr[i];
}

template<typename T>
unsigned int	Array<T>::size(void) const
{
	return _size;
}

template<typename T>
std::ostream&	operator<<(std::ostream& o, const Array<T>& a)
{
	o<<"{";
	for (unsigned int i = 0; i < a.size(); i++)
	{
		o<<a[i];
		if (i < a.size() - 1)
			o<<", ";
	}
	o<<"}";
	return (o);
}
