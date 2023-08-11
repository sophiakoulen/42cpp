/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausann>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:39:17 by skoulen           #+#    #+#             */
/*   Updated: 2023/08/11 10:02:20 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStackIterator::MutantStackIterator()
{
	_ptr		= 0;
}

template <typename T>
MutantStack<T>::MutantStackIterator::MutantStackIterator(const MutantStackIterator& it)
{
	_position	= it._position;
	_ptr		= it._ptr;
}

template <typename T>
MutantStack<T>::MutantStackIterator::MutantStackIterator(size_t position, MutantStack<T>* ptr)
{
	_position	= position;
	_ptr		= ptr;
}

template <typename T>
MutantStack<T>::MutantStackIterator::~MutantStackIterator()
{

}

template <typename T>
typename MutantStack<T>::MutantStackIterator&	MutantStack<T>::MutantStackIterator::operator=(const MutantStack<T>::MutantStackIterator& rhs)
{
	_position	= rhs._position;
	_ptr		= rhs._ptr;
	return (*this);
}

template <typename T>
T&	MutantStack<T>::MutantStackIterator::operator*() const
{
	std::stack<T *> stackB;
	T*				elt;

	while (!_ptr->_stackA.empty())
	{
		stackB.push(_ptr->_stackA.top());
		_ptr->_stackA.pop();
	}

	for (size_t i = 0; i < _position; i++)
	{
		_ptr->_stackA.push(stackB.top());
		stackB.pop();
	}

	elt = stackB.top();

	while (!stackB.empty())
	{
		_ptr->_stackA.push(stackB.top());
		stackB.pop();
	}

	return (*elt);
}

template <typename T>
typename MutantStack<T>::MutantStackIterator&	MutantStack<T>::MutantStackIterator::operator++()
{
	_position++;
	return (*this);
}

template <typename T>
typename MutantStack<T>::MutantStackIterator	MutantStack<T>::MutantStackIterator::operator++(int)
{
	MutantStack<T>::MutantStackIterator	old = *this;
	operator++();
	return (old);
}

template <typename T>
typename MutantStack<T>::MutantStackIterator&	MutantStack<T>::MutantStackIterator::operator--()
{
	_position--;
	return (*this);
}

template <typename T>
typename MutantStack<T>::MutantStackIterator	MutantStack<T>::MutantStackIterator::operator--(int)
{
	MutantStack<T>::MutantStackIterator	old = *this;
	operator--();
	return (old);
}

template <typename T>
bool	MutantStack<T>::MutantStackIterator::operator==(const MutantStack<T>::MutantStackIterator& rhs) const
{
	return (_ptr == rhs._ptr && _position == rhs._position);
}

template <typename T>
bool	MutantStack<T>::MutantStackIterator::operator!=(const MutantStack<T>::MutantStackIterator& rhs) const
{
	return !(*this == rhs);
}

template <typename T>
typename MutantStack<T>::MutantStackIterator	MutantStack<T>::begin()
{
	return (MutantStackIterator(0, this));
}

template <typename T>
typename MutantStack<T>::MutantStackIterator	MutantStack<T>::end()
{
	return (MutantStackIterator(this->size(), this));
}

template <typename T>
void	MutantStack<T>::push(const T& value)
{
	this->std::stack<T>::push(value);
	_stackA.push(&this->std::stack<T>::top());
}

template <typename T>
void	MutantStack<T>::pop()
{
	this->std::stack<T>::pop();
	_stackA.pop();
}
