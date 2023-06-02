#include "Contact.class.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

static void	read_value(const char *prompt, std::string & str);

void	Contact::fill(void)
{
	read_value("first name", this->_first_name);
	read_value("last name", this->_last_name);
	read_value("nickname", this->_nickname);
	read_value("phone number", this->_phone_number);
	read_value("darkest secret", this->_darkest_secret);
}

void	Contact::show(void) const
{
	cout
		<<"\tFirst name:\t"<<this->_first_name<<endl
		<<"\tLast name:\t"<<this->_last_name<<endl
		<<"\tNickname:\t"<<this->_nickname<<endl
		<<"\tPhone number:\t"<<this->_phone_number<<endl
		<<"\tDarkest secret:\t"<<this->_darkest_secret<<endl;
}

string	Contact::getFirstName(void) const
{
	return (this->_first_name);
}

string	Contact::getLastName(void) const
{
	return (this->_last_name);
}

string	Contact::getNickname(void) const
{
	return (this->_nickname);
}

string	Contact::getPhoneNumber(void) const
{
	return (this->_phone_number);
}

string	Contact::getDarkestSecret(void) const
{
	return (this->_darkest_secret);
}

static void	read_value(const char *prompt, std::string & str)
{
	if (!cin.eof())
	{
		cout<<"Enter "<<prompt<<": ";
		std::getline(cin, str);
		if (str.empty())
		{
			cout<<"Error: value cannot be empty"<<endl;
			read_value(prompt, str);
		}
	}
}
