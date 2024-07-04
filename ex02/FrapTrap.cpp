#include "FrapTrap.hpp"

#include <iostream>

namespace ClapTrap
{
    FrapTrap::FrapTrap()
    {
        std::cout << "[DEBUG] FrapTrap default constructor called" << std::endl;
        setType("FrapTrap");
        setHitPoints(static_cast<unsigned int>(100));
        setEnergyPoints(static_cast<unsigned int>(100));
        setAttackDamage(static_cast<unsigned int>(30));
    }

    FrapTrap::FrapTrap(const std::string& name)
        : ClapTrap(name)
    {
        std::cout << "[DEBUG] FrapTrap name (" << name << ") constructor called" << std::endl;
        setType("FrapTrap");
        setHitPoints(static_cast<unsigned int>(100));
        setEnergyPoints(static_cast<unsigned int>(100));
        setAttackDamage(static_cast<unsigned int>(30));
    }

    FrapTrap::FrapTrap(const FrapTrap& other)
        : ClapTrap(other)
    {
        std::cout << "[DEBUG] FrapTrap copy constructor called" << std::endl;
    }

    FrapTrap::~FrapTrap()
    {
        std::cout << "[DEBUG] FrapTrap destructor called" << std::endl;
    }

    FrapTrap& FrapTrap::operator=(const FrapTrap& other)
    {
        std::cout << "[DEBUG] FrapTrap copy assignment operator called" << std::endl;
        if (this != &other)
        {
            setType(other.getType());
            setName(other.getName());
            setHitPoints(other.getHitPoints());
            setEnergyPoints(other.getEnergyPoints());
            setAttackDamage(other.getAttackDamage());
        }
        return *this;
    }

    void FrapTrap::highFivesGuys()
    {
        if (hasEnoughPoints())
        {
            std::cout << getType() << " " << getName();
            std::cout << " is trying to high five everyone. LET'S DO IT!";
            std::cout << std::endl;

            setEnergyPoints(getEnergyPoints() - static_cast<unsigned int>(1));
        }
    }
}
