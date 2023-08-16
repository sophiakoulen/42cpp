#include "PmergeMe.hpp"
#include <vector>

int main()
{
	PmergeMe<std::vector<int> >	p;
	for (int i = 0; i < 10; i++)
		p.push_back(i);


	PmergeMe<std::vector<int> >::iterator	it;
	int step = 2;
	for (it = p.begin(); it < p.end(); it += 2 * step)
	{
		if (*it < *(it + step))
			p.swap_range(it, it + step, it + step, it + 2 * step);
	}

	for(unsigned int i = 0; i < p.size(); i++)
	{
		std::cout << p[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}
