#include <deque>
#include <vector>
#include <iostream>

int main()
{
	typedef std::deque<int>	TContainer;
	TContainer	container;
	
	for (unsigned int i = 0; i < 10; i++)
		container.push_back(i);
	
	TContainer::iterator range_start	= container.begin();
	TContainer::iterator range_end		= container.begin() + 2;
	
	TContainer tmp(range_start, range_end);
	container.erase(range_start, range_end);

	container.insert(container.begin(), tmp.begin(), tmp.end());

	for (unsigned int i = 0; i < container.size(); i++)
		std::cout << container[i] << std::endl;

	return (0);
}
