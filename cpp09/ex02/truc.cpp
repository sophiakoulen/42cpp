#include "PmergeMe.hpp"
#include <vector>

int main()
{
	PmergeMe<std::vector<int> >	p;
	for (int i = 0; i < 10; i++)
		p.push_back(i);


	p.insert_range(p.begin() + 2, p.begin() + 7, p.end());
	for(unsigned int i = 0; i < p.size(); i++)
	{
		std::cout << p[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}
