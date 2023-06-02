#ifndef PHONE_BOOK_CLASS_H
# define PHONE_BOOK_CLASS_H

# include "Contact.class.hpp"

class PhoneBook
{
	private:
		int		_index;
		Contact	contacts[8];
		void	show(void) const;
	public:
		void	add(void);
		void	search(void);
		PhoneBook(void);

} ;

#endif
