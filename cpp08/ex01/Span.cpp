/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausann>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 11:19:45 by skoulen           #+#    #+#             */
/*   Updated: 2023/08/09 14:01:42 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N)
{
	_array = new int[N * 2];
	_index = 0;
	_size = N;
}

Span::Span(const Span& sp)
{
	_array	= new int[sp._size * 2];
	_index	= sp._index;
	_size	= sp._size;
	for (unsigned int i = 0; i < _index; i++)
		_array[i] = sp._array[i];
}

Span::~Span()
{
	delete[] _array;
}

void	Span::addNumber(int n)
{
	if (_index >= _size)
		throw std::length_error("Span");
	_array[_index] = n;
	_index++;
}

unsigned int Span::size(void) const
{
	return (_index);
}

const int&	Span::operator[](unsigned int i) const
{
	if (i > _index)
		throw std::out_of_range("Span");
	return (_array[i]);
}

Span&	Span::operator=(const Span& rhs)
{
	delete[] _array;
	_array	= new int[rhs._size * 2];
	_index	= rhs._index;
	_size	= rhs._size;
	for (unsigned int i = 0; i < _index; i++)
		_array[i] = rhs._array[i];
	return (*this);
}

unsigned int	Span::shortestSpan(void) const
{
	int	*min_elt;

	if (_index < 2)
		throw std::length_error("Span");

	std::adjacent_difference(_array, _array + _index, _array + _size);
	std::for_each(_array + _size + 1, _array + _size + _index, toAbs);
	min_elt = std::min_element(_array + _size + 1, _array + _size + _index);
	return (static_cast<unsigned int>(*min_elt));
}

unsigned int	Span::longestSpan(void) const
{
	int	*max_elt;

	if (_index < 2)
		throw std::length_error("Span");

	std::adjacent_difference(_array, _array + _index, _array + _size);
	std::for_each(_array + _size + 1, _array + _size + _index, toAbs);
	max_elt = std::max_element(_array + _size + 1, _array + _size + _index);
	return (static_cast<unsigned int>(*max_elt));
}

std::ostream& operator<<(std::ostream& o, const Span& s)
{
	o << "{";
	for (unsigned int i = 0; i < s.size(); i++)
	{
		o << s[i];
		if (i < s.size() - 1)
			o << ", ";
	}
	o << "}";
	return o;
}

void	toAbs(int &n)
{
	n = abs(n);
}
