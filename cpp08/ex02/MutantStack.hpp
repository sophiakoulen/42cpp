/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausann>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:26:09 by skoulen           #+#    #+#             */
/*   Updated: 2023/08/10 17:52:37 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_H
# define MUTANT_STACK_H

# include <stack>
# include <iterator>
# include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
	class MutantStackIterator
	{
		typedef	T								value_type;
		typedef std::ptrdiff_t					difference_type;
		typedef	T&								reference;
		typedef T*								pointer;
		typedef std::bidirectional_iterator_tag	iterator_category;

		public:
			MutantStackIterator();
			MutantStackIterator(const MutantStackIterator& it);
			MutantStackIterator(size_t position, MutantStack<T>* ptr);
			~MutantStackIterator();
			MutantStackIterator&	operator=(const MutantStackIterator& rhs);

			T&						operator*() const;
			MutantStackIterator&	operator++();

			bool	operator==(const MutantStackIterator& rhs) const;
			bool	operator!=(const MutantStackIterator& rhs) const;

		private:
			
			size_t					_position;
			MutantStack<T>*	_ptr;
	};

	std::stack<T*>	_stackA;

	public:
		MutantStackIterator	begin();
		MutantStackIterator	end();

		void	push(const T& value);
		void	pop();

		typedef MutantStackIterator	iterator;
};

# include "MutantStack.tpp"

#endif
