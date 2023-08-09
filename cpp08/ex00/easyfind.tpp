/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausann>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 09:56:16 by skoulen           #+#    #+#             */
/*   Updated: 2023/08/09 11:09:59 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


template<typename Container>
typename Container::iterator easyfind(Container& c, int target)
{
	return find(c.begin(), c.end(), target);
}

template<typename Container>
void	print_iterator(Container& c, typename Container::iterator&it)
{
	if (it == c.end())
		std::cout << "value:\tn/a\tposition:\tend" << std::endl;
	else
	{
		std::cout << "value:\t" << *it << "\tposition:\t" << std::distance(c.begin(), it);
	}
}
