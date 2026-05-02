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
			std::cout 
		}
};

class PhoneBook {
	public:
		Contact	contacts[8];
		void	print_phonebook()
		{
			if (!contacts)
				return ;
			for (int i = 0; contacts[i]; i++)
				contacts[i].printthis();
		}
};

void	add_contact(PhoneBook phoneBook)
{
	
}

void	print_phonebook(PhoneBook phoneBook)
{
	int	index;
	for (int i = 0; contact[i]; i++;)
		contact.display();
	atoi(std::cin) >> index;

}

int	main(void)
{
	PhoneBook	phoneBook;
	std::string	cmd;

	while (1)
	{
		std::cin >> cmd;
		if (cmd.compare("ADD"))
			add_contact(phoneBook);
		else if (cmd.compare("SEARCH"))
			print_phonebook();
		else if (cmd.compare("EXIT"))
			break ;
	}
	return 0;
}
