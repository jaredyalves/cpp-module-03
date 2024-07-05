#include "ClapTrap.hpp"

#include <iostream>

namespace ClapTrap
{
    ClapTrap::ClapTrap()
        : _name("Unknown"),
          _hit_points(static_cast<unsigned int>(10)),
          _energy_points(static_cast<unsigned int>(10)),
          _attack_damage(static_cast<unsigned int>(0))
    {
        std::cout << "[DEBUG] ClapTrap default constructor called" << std::endl;
    }

    ClapTrap::ClapTrap(const std::string& name)
        : _name(name),
          _hit_points(static_cast<unsigned int>(10)),
          _energy_points(static_cast<unsigned int>(10)),
          _attack_damage(static_cast<unsigned int>(0))
    {
        std::cout << "[DEBUG] ClapTrap name (" << name << ") constructor called" << std::endl;
    }

    ClapTrap::ClapTrap(const ClapTrap& other)
        : _name(other._name),
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
            _name = other._name;
            _hit_points = other._hit_points;
            _energy_points = other._energy_points;
            _attack_damage = other._attack_damage;
        }
        return *this;
    }

    std::string ClapTrap::getName() const
    {
        std::cout << "[DEBUG] ClapTrap is named " << _name << std::endl;
        return _name;
    }

    void ClapTrap::setName(const std::string& name)
    {
        std::cout << "[DEBUG] ClapTrap " << _name << ", setting name to " << name << std::endl;
        _name = name;
    }

    unsigned int ClapTrap::getHitPoints() const
    {
        std::cout << "[DEBUG] " << _name << " has " << _hit_points << " hit points" << std::endl;
        return _hit_points;
    }

    void ClapTrap::setHitPoints(const unsigned int hit_points)
    {
        std::cout << "[DEBUG] ClapTrap " << _name << ", setting hit points to " << hit_points << std::endl;
        _hit_points = hit_points;
    }

    unsigned int ClapTrap::getEnergyPoints() const
    {
        std::cout << "[DEBUG] " << _name << " has " << _energy_points << " energy points" << std::endl;
        return _energy_points;
    }

    void ClapTrap::setEnergyPoints(const unsigned int energy_points)
    {
        std::cout << "[DEBUG] ClapTrap " << _name << ", setting energy points to " << energy_points << std::endl;
        _energy_points = energy_points;
    }

    unsigned int ClapTrap::getAttackDamage() const
    {
        std::cout << "[DEBUG] " << _name << " has " << _attack_damage << " attack damage" << std::endl;
        return _attack_damage;
    }

    void ClapTrap::setAttackDamage(const unsigned int attack_damage)
    {
        std::cout << "[DEBUG] ClapTrap " << _name << ", setting attack damage to " << attack_damage << std::endl;
        _attack_damage = attack_damage;
    }

    bool ClapTrap::hasEnoughPoints() const
    {
        bool enough_points = false;

        if (_hit_points == static_cast<unsigned int>(0))
        {
            std::cout << "ClapTrap " << _name << " doesn't have enough hit points." << std::endl;
        }
        else if (_energy_points == static_cast<unsigned int>(0))
        {
            std::cout << "ClapTrap " << _name << " doesn't have enough energy points." << std::endl;
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
            std::cout << "ClapTrap " << _name;
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

    void ClapTrap::takeDamage(unsigned int amount)
    {
        std::cout << "ClapTrap " << _name << " took damage and lost " << amount << " hit points." << std::endl;

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
            std::cout << "ClapTrap " << _name;
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
