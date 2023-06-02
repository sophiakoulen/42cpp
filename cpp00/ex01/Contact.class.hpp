#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

# include <string>

using std::string;

class Contact
{
	private:
		string	_first_name;
		string	_last_name;
		string	_nickname;
		string	_phone_number;
		string	_darkest_secret;

	public:
		void	fill(void);
		void	show(void) const;
		string	getFirstName(void) const;
		string	getLastName(void) const;
		string	getNickname(void) const;
		string	getPhoneNumber(void) const;
		string	getDarkestSecret(void) const;
};

#endif
