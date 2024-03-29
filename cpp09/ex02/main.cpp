/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:06:09 by skoulen           #+#    #+#             */
/*   Updated: 2023/08/17 15:37:47 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <cassert>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Usage: ./PmergeMe [number]..." << std::endl;
		return (2);
	}

	int *arr = new int[argc - 1];
	for (int i = 0; i < argc - 1; i++)
	{
		char	*error_ptr;
		long long int	num = std::strtol(argv[i + 1], &error_ptr, 0);
		if (*error_ptr != 0 || num < 0 || num > INT_MAX)
		{
			std::cout << "Error" << std::endl;
			delete[] arr;
			return (1);
		}
		arr[i] = num;
	}

	PmergeMe<std::vector<int> >	vecMerge(arr, arr + argc - 1);
	PmergeMe<std::deque<int> >	deqMerge(arr, arr + argc - 1);

	delete[] arr;

	std::cout << "Before:\t" << vecMerge << std::endl;

	float timeVec = vecMerge.sort();
	float timeLst = deqMerge.sort();

	std::cout << "After:\t" << vecMerge << std::endl;

	
	
	for (unsigned int i = 0; i + 1 < vecMerge.size(); i++)
		assert(vecMerge[i] <= vecMerge[i + 1]);

	for (unsigned int i = 0; i + 1 < vecMerge.size(); i++)
		assert(deqMerge[i] <= deqMerge[i + 1]);
	
	std::cout << "Time to process a range of " << vecMerge.size() << " elements with std::vector: " << timeVec << " us;\t"
		<< "Number of comparisons: " << vecMerge.getComparisonCount() << std::endl;
	
	std::cout << "Time to process a range of " << deqMerge.size() << " elements with std::deque: " << timeLst << " us;\t"
		<< "Number of comparisons: " << deqMerge.getComparisonCount() << std::endl;

	return (0);
}
