/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausann>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 11:14:18 by skoulen           #+#    #+#             */
/*   Updated: 2023/08/09 13:34:39 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
# define SPAN_H

# include <exception>
# include <iostream>
# include <numeric>
# include <cstdlib>

class Span
{
	public:
		Span(unsigned int N);
		Span(const Span& sp);
		
		/* template constructor that uses start and end iterator */
		template <typename InputIt>
		Span(InputIt begin, InputIt end)
		{
			_size = end - begin;
			_array = new int[_size * 2];
			_index = _size;
			for (InputIt it = begin; it != end; it++)
				_array[it - begin] = *it;
		}
		
		~Span();
		void			addNumber(int n);
		unsigned int	shortestSpan(void) const;
		unsigned int	longestSpan(void) const;
		unsigned int	size(void) const;
		const int&		operator[](unsigned int i) const;
		Span&			operator=(const Span& rhs);

	private:
		int				*_array;
		unsigned int	_index;
		unsigned int	_size;
		Span();
};

std::ostream& operator<<(std::ostream& o, const Span& s);

void	toAbs(int &n);

#endif
