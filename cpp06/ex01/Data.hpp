/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausann>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:45:13 by skoulen           #+#    #+#             */
/*   Updated: 2023/08/07 12:48:48 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

typedef struct s_weird
{
	void		*hello;
	const char	*world;
}	t_weird;

class Data
{
	public:
		Data(void *ptr);
		~Data();
		Data	&operator=(const Data &rhs);

	private:
		int		_i;
		float	_f;
		t_weird	_weird;
		Data();
};

#endif
