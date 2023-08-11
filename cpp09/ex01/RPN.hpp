/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausann>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:46:40 by skoulen           #+#    #+#             */
/*   Updated: 2023/08/11 17:49:58 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_H
# define RPN_H
# include <stack>

class RPN
{
	public:
		RPN();
		~RPN();
		RPN(const RPN& r);
		RPN&	operator=(const RPN& r);

		void	compute(const std::string& calc);

	private:
		std::stack<int>	_s;

};

#endif
