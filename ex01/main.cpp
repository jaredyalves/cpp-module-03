#include <iostream>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    {
        std::cout << "[TEST] Bob attacks John with 0 attack damage." << std::endl;
        ClapTrap::ClapTrap bob("Bob");
        bob.setAttackDamage(static_cast<unsigned int>(0));
        bob.attack("John");
    }
    std::cout << std::endl;
    {
        std::cout << "[TEST] Bob attacks John with 1 attack damage." << std::endl;
        ClapTrap::ClapTrap bob("Bob");
        bob.setAttackDamage(static_cast<unsigned int>(1));
        bob.attack("John");
    }
    std::cout << std::endl;
    {
        std::cout << "[TEST] Bob attacks John with 10 attack damage." << std::endl;
        ClapTrap::ClapTrap bob("Bob");
        bob.setAttackDamage(static_cast<unsigned int>(10));
        bob.attack("John");
    }
    std::cout << std::endl;
    {
        std::cout << "[TEST] Bob loses 1 energy points when attacking." << std::endl;
        ClapTrap::ClapTrap bob("Bob");
        bob.setAttackDamage(static_cast<unsigned int>(0));
        std::cout << "Bob has " << bob.getEnergyPoints() << " energy points." << std::endl;
        bob.attack("John");
        std::cout << "Bob has " << bob.getEnergyPoints() << " energy points." << std::endl;
        bob.setAttackDamage(static_cast<unsigned int>(5));
        bob.attack("John");
        std::cout << "Bob has " << bob.getEnergyPoints() << " energy points." << std::endl;
    }
    std::cout << std::endl;
    {
        std::cout << "[TEST] Bob takes damage." << std::endl;
        ClapTrap::ClapTrap bob("Bob");
        ClapTrap::ClapTrap john("John");
        john.setAttackDamage(static_cast<unsigned int>(5));
        std::cout << "Bob has " << bob.getHitPoints() << " hit points." << std::endl;
        john.attack("Bob");
        bob.takeDamage(static_cast<unsigned int>(5));
        std::cout << "Bob has " << bob.getHitPoints() << " hit points." << std::endl;
    }
    std::cout << std::endl;
    {
        std::cout << "[TEST] Bob can't attack with 0 hit points." << std::endl;
        ClapTrap::ClapTrap bob("Bob");
        bob.setHitPoints(static_cast<unsigned int>(0));
        std::cout << "Bob has " << bob.getHitPoints() << " hit points." << std::endl;
        bob.attack("John");
    }
    std::cout << std::endl;
    {
        std::cout << "[TEST] Bob can't repair with 0 hit points." << std::endl;
        ClapTrap::ClapTrap bob("Bob");
        bob.setHitPoints(static_cast<unsigned int>(0));
        std::cout << "Bob has " << bob.getHitPoints() << " hit points." << std::endl;
        bob.beRepaired(static_cast<unsigned int>(10));
    }
    std::cout << std::endl;
    {
        std::cout << "[TEST] Bob can't attack with 0 energy points." << std::endl;
        ClapTrap::ClapTrap bob("Bob");
        bob.setEnergyPoints(static_cast<unsigned int>(0));
        std::cout << "Bob has " << bob.getEnergyPoints() << " energy points." << std::endl;
        bob.attack("John");
    }
    std::cout << std::endl;
    {
        std::cout << "[TEST] Bob can't repair with 0 energy points." << std::endl;
        ClapTrap::ClapTrap bob("Bob");
        bob.setEnergyPoints(static_cast<unsigned int>(0));
        std::cout << "Bob has " << bob.getEnergyPoints() << " energy points." << std::endl;
        bob.beRepaired(static_cast<unsigned int>(10));
    }
    std::cout << std::endl;
    {
        std::cout << "[TEST] Bob is able to repair itself." << std::endl;
        ClapTrap::ClapTrap bob("Bob");
        bob.setHitPoints(static_cast<unsigned int>(1));
        std::cout << "Bob has " << bob.getHitPoints() << " hit points." << std::endl;
        bob.beRepaired(static_cast<unsigned int>(9));
        std::cout << "Bob has " << bob.getHitPoints() << " hit points." << std::endl;
    }
    std::cout << std::endl;
    {
        std::cout << "[TEST] Bob loses 1 energy point when reparing itself." << std::endl;
        ClapTrap::ClapTrap bob("Bob");
        std::cout << "Bob has " << bob.getEnergyPoints() << " energy points." << std::endl;
        bob.beRepaired(static_cast<unsigned int>(5));
        std::cout << "Bob has " << bob.getEnergyPoints() << " energy points." << std::endl;
    }
    std::cout << std::endl;
    {
        std::cout << "[TEST] ScavTrap Bob starts from ClapTrap." << std::endl;
        ClapTrap::ScavTrap bob("Bob");
        bob.attack("John");
    }
    std::cout << std::endl;
    {
        std::cout << "[TEST] ScavTrap Bob can guard the gate." << std::endl;
        ClapTrap::ScavTrap bob("Bob");
        bob.guardGate();
    }
}
