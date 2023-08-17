/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:06:09 by skoulen           #+#    #+#             */
/*   Updated: 2023/08/17 13:39:13 by skoulen          ###   ########.fr       */
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
		arr[i] = std::atoi(argv[i + 1]);

	PmergeMe<std::vector<int> >	vecMerge(arr, arr + argc - 1);
	PmergeMe<std::deque<int> >	lstMerge(arr, arr + argc - 1);

	std::cout << "Before:\t" << vecMerge << std::endl;

	float timeVec = vecMerge.sort();
	float timeLst = lstMerge.sort();

	std::cout << "After:\t" << vecMerge << std::endl;

	
	std::cout << "Number of comparisons: " << vecMerge.getComparisonCount() << std::endl;
	std::cout << "Number of comparisons: " << lstMerge.getComparisonCount() << std::endl;
	
	for (unsigned int i = 0; i + 1 < vecMerge.size(); i++)
		assert(vecMerge[i] <= vecMerge[i + 1]);

	std::cout << "Time to process a range of " << vecMerge.size() << " elements with std::vector: " << timeVec << " us" << std::endl;
	std::cout << "Time to process a range of " << lstMerge.size() << " elements with std::deque: " << timeLst << " us" << std::endl;

	return (0);
}
