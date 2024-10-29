#include "Contact.class.hpp"

Contact::Contact(const std::string &firstName, const std::string &lastname,
		std::string &nickname, const int &phoneNumber,
		const std::string &darkestSecret) : firstName(firstName), lastName(lastName), 
		nickname(nickname), phoneNumber(phoneNumber), darkestSecret(darkestSecret) {}

