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

# include "contact.hpp"
# include <iostream>
# include <string>

 class PhoneBook{
	public:
		PhoneBook(void);
		~PhoneBook(void);
		displayContacts(Contact& Contacts);
		addContacts(Contact& Contacts);


	private:
		static const int MAX_CONTACTS = 8;
		contact contats[MAX_CONTACTS];
		int	numberOfContacts;
 };

#endif
