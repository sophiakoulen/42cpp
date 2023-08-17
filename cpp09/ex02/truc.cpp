#include "PmergeMe.hpp"
#include <vector>
#include <deque>

int main()
{
	PmergeMe<std::vector<int> > p1;
	PmergeMe<std::deque<int> >	p2;

	for (unsigned int i = 0; i < 25; i++)
		std::cout << p1.jacobstahl() << std::endl;

	for (unsigned int i = 0; i < 25; i++)
		std::cout << p2.jacobstahl() << std::endl;
	
	return 0;
}
