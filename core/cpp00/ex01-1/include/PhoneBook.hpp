/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:59:33 by tbaker            #+#    #+#             */
/*   Updated: 2024/10/29 14:10:28 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <string>
# include <limits>

 class PhoneBook{
	public:
		PhoneBook();
		void displayContacts(void);
		void addContacts(void);
		void selectContact(void);


	private:
		static const int MAX_CONTACTS = 8;
		Contact contacts[MAX_CONTACTS];
		int	numberOfContacts;
		int	indexPosition;
 };

#endif
