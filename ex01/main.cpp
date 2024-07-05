#include <iostream>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    // ClapTrap tests
    {
        std::cout << "[TEST] ClapTrap is initialized properly" << std::endl;
        ClapTrap::ClapTrap bob("Bob");
        (void)bob.getHitPoints();
        (void)bob.getEnergyPoints();
        (void)bob.getAttackDamage();
    }
    std::cout << std::endl;
    {
        std::cout << "[TEST] ClapTrap can attack with 0 attack damage" << std::endl;
        ClapTrap::ClapTrap bob("Bob");
        bob.setAttackDamage(static_cast<unsigned int>(0));
        bob.attack("John");
    }
    std::cout << std::endl;
    {
        std::cout << "[TEST] ClapTrap can attack with 5 attack damage" << std::endl;
        ClapTrap::ClapTrap bob("Bob");
        bob.setAttackDamage(static_cast<unsigned int>(5));
        bob.attack("John");
    }
    std::cout << std::endl;
    {
        std::cout << "[TEST] ClapTrap loses 1 energy point when attacking with 0 attack damage" << std::endl;
        ClapTrap::ClapTrap bob("Bob");
        bob.setAttackDamage(static_cast<unsigned int>(0));
        (void)bob.getEnergyPoints();
        bob.attack("John");
        (void)bob.getEnergyPoints();
    }
    std::cout << std::endl;
    {
        std::cout << "[TEST] ClapTrap loses 1 energy point when attacking with 5 attack damage" << std::endl;
        ClapTrap::ClapTrap bob("Bob");
        bob.setAttackDamage(static_cast<unsigned int>(5));
        (void)bob.getEnergyPoints();
        bob.attack("John");
        (void)bob.getEnergyPoints();
    }
    std::cout << std::endl;
    {
        std::cout << "[TEST] ClapTrap loses 5 hit points when taking 5 damage" << std::endl;
        ClapTrap::ClapTrap bob("Bob");
        (void)bob.getHitPoints();
        bob.takeDamage(static_cast<unsigned int>(5));
        (void)bob.getHitPoints();
    }
    std::cout << std::endl;
    {
        std::cout << "[TEST] ClapTrap can't attack when has 0 hit points" << std::endl;
        ClapTrap::ClapTrap bob("Bob");
        bob.setHitPoints(static_cast<unsigned int>(0));
        bob.attack("John");
    }
    std::cout << std::endl;
    {
        std::cout << "[TEST] ClapTrap can't attack when has 0 energy points" << std::endl;
        ClapTrap::ClapTrap bob("Bob");
        bob.setEnergyPoints(static_cast<unsigned int>(0));
        bob.attack("John");
    }
    std::cout << std::endl;
    {
        std::cout << "[TEST] ClapTrap can't repair when has 0 hit points" << std::endl;
        ClapTrap::ClapTrap bob("Bob");
        bob.setHitPoints(static_cast<unsigned int>(0));
        bob.beRepaired(static_cast<unsigned int>(5));
    }
    std::cout << std::endl;
    {
        std::cout << "[TEST] ClapTrap can't repair when has 0 energy points" << std::endl;
        ClapTrap::ClapTrap bob("Bob");
        bob.setEnergyPoints(static_cast<unsigned int>(0));
        bob.beRepaired(static_cast<unsigned int>(5));
    }
    std::cout << std::endl;
    {
        std::cout << "[TEST] ClapTrap receives 0 hit points when recovering with 0" << std::endl;
        ClapTrap::ClapTrap bob("Bob");
        (void)bob.getHitPoints();
        bob.beRepaired(static_cast<unsigned int>(0));
        (void)bob.getHitPoints();
    }
    std::cout << std::endl;
    {
        std::cout << "[TEST] ClapTrap receives 5 hit points when recovering with 5" << std::endl;
        ClapTrap::ClapTrap bob("Bob");
        (void)bob.getHitPoints();
        bob.beRepaired(static_cast<unsigned int>(5));
        (void)bob.getHitPoints();
    }
    std::cout << std::endl;
    {
        std::cout << "[TEST] ClapTrap loses 1 energy point when recovering with 0" << std::endl;
        ClapTrap::ClapTrap bob("Bob");
        (void)bob.getEnergyPoints();
        bob.beRepaired(static_cast<unsigned int>(0));
        (void)bob.getEnergyPoints();
    }
    std::cout << std::endl;
    {
        std::cout << "[TEST] ClapTrap loses 1 energy point when recovering with 5" << std::endl;
        ClapTrap::ClapTrap bob("Bob");
        (void)bob.getEnergyPoints();
        bob.beRepaired(static_cast<unsigned int>(5));
        (void)bob.getEnergyPoints();
    }
    std::cout << std::endl;

    // ScavTrap tests
    {
        std::cout << "[TEST] ScavTrap is initialized properly" << std::endl;
        ClapTrap::ScavTrap bob("Bob");
        (void)bob.getHitPoints();
        (void)bob.getEnergyPoints();
        (void)bob.getAttackDamage();
    }
    std::cout << std::endl;
    {
        std::cout << "[TEST] ScavTrap can attack properly" << std::endl;
        ClapTrap::ScavTrap bob("Bob");
        bob.attack("John");
    }
    std::cout << std::endl;
    {
        std::cout << "[TEST] ScavTrap can guard the gate" << std::endl;
        ClapTrap::ScavTrap bob("Bob");
        bob.guardGate();
    }
    std::cout << std::endl;
}
