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

# include "PhoneBook.hpp"
# include <iostream>
# include <stdlib.h>

class Contact {
    public:
		int			index;
        std::string	first_name;
        std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	secret;

		void	display()
		{
			std::cout << first_name << std::endl << last_name << std::endl << nickname << std::endl << phone_number << std::endl << secret << std::endl;
		}

		void	print_index()
		{
			std::cout << index << ' | ' << first_name << ' | ' << last_name << ' | ' << nickname << std::endl;
		}
};

class PhoneBook {
	public:
		Contact	contacts[8];

		void	print_phonebook()
		{
			if (!contacts)
				return ;
			for (int i = 0; contacts[i].index; i++)
				contacts[i].print_index();
		}

		Contact	add_contact()
		{
			int	index = 0;
			while (contacts[index].index)
				index++;
			try
			{
				index++;
				contacts[index].index = index;
			}
			// insert new contact 
			catch
			{
				contacts[0].index = 0;
			}
			// erase and replace oldest
		}

		int	search(int index)
		{
			if (!contacts[index].index)
				return 0;
			return 1;
		}
};


int	main(void)
{
	PhoneBook	phoneBook;
	std::string	cmd;
	int			index;

	while (1)
	{
		std::cin >> cmd;
		if (cmd.compare("ADD"))
			phoneBook.add_contact();
		else if (cmd.compare("SEARCH"))
		{
			phoneBook.print_phonebook();
			atoi(std::cin) >> index;
			if (phoneBook.search(index))
				phoneBook.contacts[index].display();
		}
		else if (cmd.compare("EXIT"))
			break ;
	}
	return 0;
}
