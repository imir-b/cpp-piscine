/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 04:15:36 by username          #+#    #+#             */
/*   Updated: 2026/05/09 04:32:39 by vbleskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ADD : save a new contact
// - contact : first name, last name, nickname, phone number, darkest secret
// - maximum of 8 contacts

// SEARCH : display a specific contact
// -> display the saved contacts as a list of 4 columns (index, first name, last name, nickname)
// - each column must be 10 char wide
// - '|' separates them
// - the text must be right-aligned
// - if the thext is longer than the column, it must be truncated and the last displayable char
// must be replaced by a '.'
// -> then prompt the user again for the index of the entry to display

// EXIT : exit and destroy the contacts

// any other input is ignored

#include "PhoneBook.hpp"
#include <iostream>
#include <stdlib.h>

class Contact
{
	public :
	int	index;
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string secret;

	void	display(void)
	{
		std::cout << first_name << std::endl << last_name << std::endl << nickname << std::endl << phone_number << std::endl << secret << std::endl;
	}

	void	print_index(void)
	{
		std::cout << index << ' | ' << first_name << ' | ' << last_name << ' | ' << nickname << std::endl;
	}
};

class PhoneBook
{
	public :
	Contact	contacts[8];

	void	print_phonebook(void)
	{
		if (!contacts)
			return ;
		for (int i = 0; contacts[i].index; i++)
			contacts[i].print_index();
	}

	Contact	add_contact(void)
	{
		std::string first_name = prompt("first name");
		std::string last_name = prompt("last name");
		std::string nickname = prompt("nickname");
		std::string phone_number = prompt("phone number");
		std::string secret = prompt("secret");
		int	index = 0;

		while (contacts[index].index)
			index++;
		if (index == 8)
			insert_contact(contacts[0], 0, first_name, last_name, nickname, phone_number, secret);
		else
			insert_contact(contacts[index + 1], index + 1, first_name, last_name, nickname, phone_number, secret);
	}

	int	search(int index)
	{
		if (!contacts[index].index)
			return (0);
		return (1);
	}
	private :
	std::string prompt(char *field)
	{
		std::string value;
		std::cout << "Notice \'" << field << "\' of the new contact : " << std::endl;
		std::cin >> value;
		return (value);
	}

	int	insert_contact(Contact new_contact, int index, std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string secret)
	{
		if (first_name.empty() || last_name.empty() || nickname.empty() || phone_number.empty() || secret.empty())
			return (1);
		new_contact.index = index;
		new_contact.first_name = first_name;
		new_contact.last_name = last_name;
		new_contact.nickname = nickname;
		new_contact.phone_number = phone_number;
		new_contact.secret = secret;
		return (0);
	}
};

int	main(void)
{
	PhoneBook	phoneBook;

	std::string cmd;
	int	index;

	while (1)
	{
		std::cin >> cmd;
		if (cmd.compare("ADD"))
			phoneBook.add_contact();
		else if (cmd.compare("SEARCH"))
		{
			phoneBook.print_phonebook();
			std::cin >> index;
			if (phoneBook.search(index))
				phoneBook.contacts[index].display();
		}
		else if (cmd.compare("EXIT"))
			break ;
	}
	return (0);
}
