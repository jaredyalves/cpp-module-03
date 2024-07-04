#include "ClapTrap.hpp"

#include <iostream>

namespace ClapTrap
{
    ClapTrap::ClapTrap()
        : _type("ClapTrap"),
          _name("Unknown"),
          _hit_points(static_cast<unsigned int>(10)),
          _energy_points(static_cast<unsigned int>(10)),
          _attack_damage(static_cast<unsigned int>(0))
    {
        std::cout << "[DEBUG] ClapTrap default constructor called" << std::endl;
    }

    ClapTrap::ClapTrap(const std::string& name)
        : _type("ClapTrap"),
          _name(name),
          _hit_points(static_cast<unsigned int>(10)),
          _energy_points(static_cast<unsigned int>(10)),
          _attack_damage(static_cast<unsigned int>(0))
    {
        std::cout << "[DEBUG] ClapTrap name (" << name << ") constructor called" << std::endl;
    }

    ClapTrap::ClapTrap(const ClapTrap& other)
        : _type(other._type),
          _name(other._name),
          _hit_points(other._hit_points),
          _energy_points(other._energy_points),
          _attack_damage(other._attack_damage)
    {
        std::cout << "[DEBUG] ClapTrap copy constructor called" << std::endl;
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
            _type = other._type;
            _name = other._name;
            _hit_points = other._hit_points;
            _energy_points = other._energy_points;
            _attack_damage = other._attack_damage;
        }
        return *this;
    }

    std::string ClapTrap::getType() const
    {
        return _type;
    }

    void ClapTrap::setType(const std::string& type)
    {
        std::cout << "[DEBUG] " << _type << " " << _name;
        std::cout << ", setting type to " << type;
        std::cout << std::endl;
        _type = type;
    }

    std::string ClapTrap::getName() const
    {
        return _name;
    }

    void ClapTrap::setName(const std::string& name)
    {
        std::cout << "[DEBUG] " << _type << " " << _name;
        std::cout << ", setting name to " << name;
        std::cout << std::endl;
        _name = name;
    }

    unsigned int ClapTrap::getHitPoints() const
    {
        std::cout << "[DEBUG] " << _type << " " << _name;
        std::cout << " has " << _hit_points << " hit points.";
        std::cout << std::endl;
        return _hit_points;
    }

    void ClapTrap::setHitPoints(const unsigned int hit_points)
    {
        std::cout << "[DEBUG] " << _type << " " << _name;
        std::cout << ", setting hit points to " << hit_points;
        std::cout << std::endl;
        _hit_points = hit_points;
    }

    unsigned int ClapTrap::getEnergyPoints() const
    {
        std::cout << "[DEBUG] " << _type << " " << _name;
        std::cout << " has " << _energy_points << " energy points.";
        std::cout << std::endl;
        return _energy_points;
    }

    void ClapTrap::setEnergyPoints(const unsigned int energy_points)
    {
        std::cout << "[DEBUG] " << _type << " " << _name;
        std::cout << ", setting energy points to " << energy_points;
        std::cout << std::endl;
        _energy_points = energy_points;
    }

    unsigned int ClapTrap::getAttackDamage() const
    {
        std::cout << "[DEBUG] " << _type << " " << _name;
        std::cout << " can cause " << _attack_damage << " of attack damage.";
        std::cout << std::endl;
        return _attack_damage;
    }

    void ClapTrap::setAttackDamage(const unsigned int attack_damage)
    {
        std::cout << "[DEBUG] " << _type << " " << _name;
        std::cout << ", setting attack damage to " << attack_damage;
        std::cout << std::endl;
        _attack_damage = attack_damage;
    }

    bool ClapTrap::hasEnoughPoints() const
    {
        bool enough_points = false;

        if (_hit_points == static_cast<unsigned int>(0))
        {
            std::cout << _type << " " << _name;
            std::cout << " doesn't have enough hit points.";
            std::cout << std::endl;
        }
        else if (_energy_points == static_cast<unsigned int>(0))
        {
            std::cout << _type << " " << _name;
            std::cout << " doesn't have enough energy points.";
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
        std::cout << " took damage and lost " << amount << " hit points.";
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
            if (amount == static_cast<unsigned int>(0))
            {
                std::cout << " tries to repair itself, but fails to do it.";
            }
            else
            {
                std::cout << " repaired itself, receiving " << amount << " hit points.";

                _hit_points += amount;
            }
            std::cout << std::endl;

            _energy_points--;
        }
    }
}
