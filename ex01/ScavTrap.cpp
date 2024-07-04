#include "ScavTrap.hpp"

#include <iostream>

namespace ClapTrap
{
    ScavTrap::ScavTrap()
    {
        std::cout << "[DEBUG] ScavTrap default constructor called" << std::endl;
        _type = "ScavTrap";
        _hit_points = static_cast<unsigned int>(100);
        _energy_points = static_cast<unsigned int>(50);
        _attack_damage = static_cast<unsigned int>(20);
    }

    ScavTrap::ScavTrap(const std::string& name)
        : ClapTrap(name)
    {
        std::cout << "[DEBUG] ScavTrap name constructor called" << std::endl;
        _type = "ScavTrap";
        _hit_points = static_cast<unsigned int>(100);
        _energy_points = static_cast<unsigned int>(50);
        _attack_damage = static_cast<unsigned int>(20);
    }

    ScavTrap::ScavTrap(const ScavTrap& other)
        : ClapTrap(other)
    {
        std::cout << "[DEBUG] ScavTrap copy constructor called" << std::endl;
        _type = "ScavTrap";
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
            _type = "ScavTrap";
            _name = other._name;
            _hit_points = other._hit_points;
            _energy_points = other._energy_points;
            _attack_damage = other._attack_damage;
        }
        return *this;
    }

    void ScavTrap::guardGate()
    {
        if (hasEnoughPoints())
        {
            std::cout << _type << " " << _name;
            std::cout << " is now in gate keeper mode.";
            std::cout << std::endl;

            _energy_points--;
        }
    }
}
