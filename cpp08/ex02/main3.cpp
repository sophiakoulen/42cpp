#include "MutantStack.hpp"
#include <iostream>

int main()
{
	MutantStack<int> s1;
	s1.push(2);
	s1.push(5);

	MutantStack<int> s2(s1);
	s2.push(3);

	MutantStack<int>::iterator it;

	for (it = s2.begin(); it != s2.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	MutantStack<int> s3;
	s3.push(1);
	s3.push(2);
	s3.push(3);

	s3 = s1;

	for (it = s3.begin(); it != s3.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	return 0;
}
