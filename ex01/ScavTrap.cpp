#include "ScavTrap.hpp"

#include <iostream>

namespace ClapTrap
{
    ScavTrap::ScavTrap()
    {
        std::cout << "[DEBUG] ScavTrap default constructor called" << std::endl;
        setType("ScavTrap");
        setHitPoints(static_cast<unsigned int>(100));
        setEnergyPoints(static_cast<unsigned int>(50));
        setAttackDamage(static_cast<unsigned int>(20));
    }

    ScavTrap::ScavTrap(const std::string& name)
        : ClapTrap(name)
    {
        std::cout << "[DEBUG] ScavTrap name (" << name << ") constructor called" << std::endl;
        setType("ScavTrap");
        setHitPoints(static_cast<unsigned int>(100));
        setEnergyPoints(static_cast<unsigned int>(50));
        setAttackDamage(static_cast<unsigned int>(20));
    }

    ScavTrap::ScavTrap(const ScavTrap& other)
        : ClapTrap(other)
    {
        std::cout << "[DEBUG] ScavTrap copy constructor called" << std::endl;
    }

    ScavTrap::~ScavTrap()
    {
        std::cout << "[DEBUG] ScavTrap destructor called" << std::endl;
    }

    ScavTrap& ScavTrap::operator=(const ScavTrap& other)
    {
        std::cout << "[DEBUG] ScavTrap copy assignment operator called" << std::endl;
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

    void ScavTrap::guardGate()
    {
        if (hasEnoughPoints())
        {
            std::cout << getType() << " " << getName();
            std::cout << " is keeping the gate safe.";
            std::cout << std::endl;

            setEnergyPoints(getEnergyPoints() - static_cast<unsigned int>(1));
        }
    }
}
