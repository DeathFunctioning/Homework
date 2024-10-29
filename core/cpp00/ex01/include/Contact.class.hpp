#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

# include <iostream>
# include <string>

class Contact {

public:

	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	int			phoneNumber;
	std::string	darkestSecret;

	Contact(const std::string &firstName, const std::string &lastName,
			const std::string &nickname, const int &phoneNumber,
			const std::string &darkestSecret);

};

#endif
