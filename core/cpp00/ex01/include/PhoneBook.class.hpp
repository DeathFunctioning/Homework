#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# include <iostream>
# include "Contact.class.hpp"

class PhoneBook {

	private:
		const int MAX_CONTACTS = 8;
		Contact Contacts[MAX_CONTACTS];
		int	contactCount;

	public:

	PhoneBook(void);
	
	void	addContact(const Contact &contact);
	void	displayContacts() const;

};

#endif
