/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:06:09 by skoulen           #+#    #+#             */
/*   Updated: 2023/08/13 17:41:40 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>

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

	std::cout << "Before:\t";
	for (unsigned int i = 0; i < vecMerge.size(); i++)
		std::cout << vecMerge[i] << " ";
	std::cout << std::endl;

	float timeVec = vecMerge.sort();
	float timeLst = lstMerge.sort();

	std::cout << "After:\t";
	for (unsigned int i = 0; i < vecMerge.size(); i++)
		std::cout << vecMerge[i] << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << vecMerge.size() << " elements with std::vector:\t" << timeVec << " us" << std::endl;
	std::cout << "Time to process a range of " << lstMerge.size() << " elements with std::deque:\t" << timeLst << " us" << std::endl;

	return (0);
}
