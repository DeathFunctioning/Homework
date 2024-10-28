/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:59:33 by tbaker            #+#    #+#             */
/*   Updated: 2024/10/28 17:39:52 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include "contact.hpp"

 class PhoneBook{
	public:


	private:
		static const int MAX_CONTACTS = 8;
		contacts contats[MAX_CONTACTS];
		int	i;
 };

#endif
