#include "PhoneBook.class.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

static int			read_index(void);
static std::string	truncate(std::string str);
static std::string	spaces(int n);
static void			wait_user_quit(void);
static void			clear_screen(void);

PhoneBook::PhoneBook(void):
	_index(0)
{
	return ;
}

void	PhoneBook::add(void)
{
	cout<<"\033[2J\033[H"; //clear screen
	this->contacts[this->_index].fill();
	this->_index = (this->_index + 1) % 8;
}

void	PhoneBook::search(void)
{
	int	index;

	clear_screen();
	this->show(); //show table of contacts
	index = read_index();	
	if (index != -1)
	{
		clear_screen();
		this->contacts[index].show();
	}	
	wait_user_quit();	
	clear_screen();
}

void	PhoneBook::show(void) const
{
	cout<<"Contacts in your phone book:"<<endl;
	for (int i = 0; i < 8; i++)
	{
		cout<<
			spaces(9)<<i<<'|'<<
			truncate(this->contacts[i].getFirstName())<<'|'<<
			truncate(this->contacts[i].getLastName())<<"|"<<
			truncate(this->contacts[i].getNickname())<<endl;
	}
}

static int	read_index(void)
{
	std::string	input;
	int			index;
	char		*end;
	
	cout<<"Enter which index you want to see: ";
	std::getline(cin, input);
	index = std::strtol(input.c_str(), &end, 0);
	if (index < 0 || index > 7 || *end != '\0' || errno == ERANGE)
	{
		cout<<"Error: index out of range"<<endl;
		return (-1);
	}
	return (index);
}

static std::string	spaces(int n)
{
	std::string	res;

	res.resize(n, ' ');
	return (res);
}

static std::string	truncate(std::string str)
{
	std::string	res;

	if (str.length() <= 10)
	{
		res.resize(10 - str.length(), ' ');
		res.append(str);
	}
	else
	{
		res = str;
		res.resize(10);
		res[9] = '.';
	}
	return (res);
}

static void	wait_user_quit(void)
{
	char	c;

	cout<<"[press q to continue] ";
	do
		cin.get(c);
	while (c != 'q' && c != 'Q');
}

static void	clear_screen(void)
{
	cout<<"\033[2J\033[H";
}
