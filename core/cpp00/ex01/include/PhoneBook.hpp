/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:59:33 by tbaker            #+#    #+#             */
/*   Updated: 2024/11/11 18:09:22 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <string>
# include <cstdlib>

 class PhoneBook{
	public:
		PhoneBook();
		void displayContacts(void);
		void addContacts(void);
		void selectContact(void);
		bool checkIndexValue(std::string& indexValue);
		bool isWhiteSpace(char c);
		int	numberOfContacts;

	private:
		static const int MAX_CONTACTS = 8;
		Contact contacts[MAX_CONTACTS];
		int	indexPosition;
 };

#endif
