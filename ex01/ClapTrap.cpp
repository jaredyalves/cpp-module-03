#include "ClapTrap.hpp"

#include <iostream>

namespace ClapTrap
{
    ClapTrap::ClapTrap()
    {
        std::cout << "[DEBUG] ClapTrap default constructor called" << std::endl;
        _type = "ClapTrap";
        _hit_points = static_cast<unsigned int>(10);
        _energy_points = static_cast<unsigned int>(10);
        _attack_damage = static_cast<unsigned int>(0);
    }

    ClapTrap::ClapTrap(const std::string& name)
    {
        std::cout << "[DEBUG] ClapTrap name constructor called" << std::endl;
        _type = "ClapTrap";
        _name = name;
        _hit_points = static_cast<unsigned int>(10);
        _energy_points = static_cast<unsigned int>(10);
        _attack_damage = static_cast<unsigned int>(0);
    }

    ClapTrap::ClapTrap(const ClapTrap& other)
    {
        std::cout << "[DEBUG] ClapTrap copy constructor called" << std::endl;
        _type = "ClapTrap";
        _name = other._name;
        _hit_points = other._hit_points;
        _energy_points = other._energy_points;
        _attack_damage = other._attack_damage;
    }

    ClapTrap::~ClapTrap()
    {
        std::cout << "[DEBUG] ClapTrap destructor called" << std::endl;
    }

    ClapTrap& ClapTrap::operator=(const ClapTrap& other)
    {
        std::cout << "[DEBUG] ClapTrap copy assignment operator called" << std::endl;
        if (this != &other)
        {
            _type = "ClapTrap";
            _name = other._name;
            _hit_points = other._hit_points;
            _energy_points = other._energy_points;
            _attack_damage = other._attack_damage;
        }
        return *this;
    }

    std::string ClapTrap::getName() const
    {
        return _name;
    }

    void ClapTrap::setName(const std::string& name)
    {
        _name = name;
    }

    unsigned int ClapTrap::getHitPoints() const
    {
        return _hit_points;
    }

    void ClapTrap::setHitPoints(const unsigned int hit_points)
    {
        _hit_points = hit_points;
    }

    unsigned int ClapTrap::getEnergyPoints() const
    {
        return _energy_points;
    }

    void ClapTrap::setEnergyPoints(const unsigned int energy_points)
    {
        _energy_points = energy_points;
    }

    unsigned int ClapTrap::getAttackDamage() const
    {
        return _attack_damage;
    }

    void ClapTrap::setAttackDamage(const unsigned int attack_damage)
    {
        _attack_damage = attack_damage;
    }

    bool ClapTrap::hasEnoughPoints() const
    {
        bool enough_points = false;
        if (_hit_points == static_cast<unsigned int>(0))
        {
            std::cout << _type << " " << _name << " doesn't have enough hit points.";
            std::cout << std::endl;
        }
        else if (_energy_points == static_cast<unsigned int>(0))
        {
            std::cout << _type << " " << _name << " doesn't have enough energy points.";
            std::cout << std::endl;
        }
        else
        {
            enough_points = true;
        }
        return enough_points;
    }

    void ClapTrap::attack(const std::string& target)
    {
        if (hasEnoughPoints())
        {
            std::cout << _type << " " << _name;
            if (_attack_damage == static_cast<unsigned int>(0))
            {
                std::cout << " looked away when attacking, causing no damage to " << target << ".";
            }
            else
            {
                std::cout << " attacks " << target << ", causing " << _attack_damage << " points of damage!";
            }
            std::cout << std::endl;

            _energy_points--;
        }
    }

    void ClapTrap::takeDamage(unsigned int amount)
    {
        std::cout << _type << " " << _name;
        std::cout << " lost " << amount << " hit points.";
        std::cout << std::endl;

        if (amount < _hit_points)
        {
            _hit_points -= amount;
        }
        else
        {
            _hit_points = static_cast<unsigned int>(0);
        }
    }

    void ClapTrap::beRepaired(unsigned int amount)
    {
        if (hasEnoughPoints())
        {
            std::cout << _type << " " << _name;
            std::cout << " repaired itself, receiving " << amount << " hit points.";
            std::cout << std::endl;

            _hit_points += amount;

            _energy_points--;
        }
    }
}
