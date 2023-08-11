#include <list>
#include <iostream>

int main()
{
	std::list<int> lst;
	
	lst.push_back(3);
	lst.push_back(4);
	lst.push_back(5);

	std::list<int>::iterator it;
	for (it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << std::endl;

	for (int i = 0; i < 1000; i++)
		it--;

	std::cout << *it << std::endl;

	return 0;
}
