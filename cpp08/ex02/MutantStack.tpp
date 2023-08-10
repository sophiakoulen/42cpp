/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausann>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:39:17 by skoulen           #+#    #+#             */
/*   Updated: 2023/08/10 17:59:26 by skoulen          ###   ########.fr       */
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
}

template <typename T>
T&	MutantStack<T>::MutantStackIterator::operator*() const
{
	std::stack<T *> stackB;
	T*				elt;

	for (size_t i = 0; i < _position; i++)
	{
		stackB.push(_stackA.top());
		_stackA.pop();
	}

	elt = _stackA.top();

	while (!stackB.empty())
	{
		_stackA->push(stackB.top());
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
	_stackB.pop();
}
