#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

class Zombie
{
	public:
	    Zombie(void);
	    ~Zombie(void);
	    void	add_contact(int i);
		void	print_phonebook(void);
		void	print_contact(int i);
		int		number_of_contacts(void);

	private:
		Contact	List[MEMORY];
		int		nbr_contacts;
		void    truncate_text(std::string str);
};

#endif