# include "HumanB.hpp"

HumanB::HumanB(std::string const name, Weapon * weapon) : _name(name), _weapon(weapon)
{
     if (this->_weapon->getType() == "")
    {
        std::cout << ANSI_YELLOW << "[...] new human B created (name : " << this->_name
        << ", no weapon)"
        << ANSI_RESET << std::endl;
    }
    else
    {
        std::cout << ANSI_YELLOW << "[...] new human B created (name : " << this->_name
        << ", type of weapon : " << this->_weapon->getType() << ")"
        << ANSI_RESET << std::endl;
    }
}

HumanB::HumanB(std::string const name) : _name(name), _weapon(NULL)
{
    std::cout << ANSI_YELLOW << "[...] new human B created (name : " << this->_name
    << ", no weapon)"
    << ANSI_RESET << std::endl;
}

HumanB::~HumanB(void)
{
    std::cout << ANSI_YELLOW << "[...] destruction of human (name : " << this->_name
    << ")"
    << ANSI_RESET << std::endl;
}

void    HumanB::setWeapon(Weapon & weapon)
{
    this->_weapon = &weapon;
}

void	HumanB::attack(void)
{
    if (!this->_weapon || this->_weapon->getType() == "")
        std::cout << this->_name << " has no weapon to launch an attack..." << this->_weapon->getType() << std::endl;
    else
        std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;    
}
