#include "FrapTrap.hpp"

#include <iostream>

namespace ClapTrap
{
    FrapTrap::FrapTrap()
    {
        std::cout << "[DEBUG] FrapTrap default constructor called" << std::endl;
        _hit_points = static_cast<unsigned int>(100);
        _energy_points = static_cast<unsigned int>(100);
        _attack_damage = static_cast<unsigned int>(30);
    }

    FrapTrap::FrapTrap(const std::string& name)
        : ClapTrap(name)
    {
        std::cout << "[DEBUG] FrapTrap name (" << name << ") constructor called" << std::endl;
        _hit_points = static_cast<unsigned int>(100);
        _energy_points = static_cast<unsigned int>(100);
        _attack_damage = static_cast<unsigned int>(30);
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
            _name = other._name;
            _hit_points = other._hit_points;
            _energy_points = other._energy_points;
            _attack_damage = other._attack_damage;
        }
        return *this;
    }

    void FrapTrap::attack(const std::string& target)
    {
        if (hasEnoughPoints())
        {
            std::cout << "FrapTrap " << _name;
            if (_attack_damage == static_cast<unsigned int>(0))
            {
                std::cout << " fails to attack " << target << ", causing no damage.";
            }
            else
            {
                std::cout << " attacks " << target << ", causing " << _attack_damage << " points of damage!";
            }
            std::cout << std::endl;

            _energy_points--;
        }
    }

    void FrapTrap::highFivesGuys()
    {
        if (hasEnoughPoints())
        {
            std::cout << "FrapTrap " << _name << " is trying to high five everyone. LET'S DO IT!" << std::endl;

            _energy_points--;
        }
    }
}
