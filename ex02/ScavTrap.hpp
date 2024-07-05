#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

namespace ClapTrap
{
    class ScavTrap : public ClapTrap
    {
    public:
        ScavTrap();
        explicit ScavTrap(const std::string& name);
        ScavTrap(const ScavTrap& other);

        ~ScavTrap();

        ScavTrap& operator=(const ScavTrap& other);

        void attack(const std::string& target);
        void guardGate();
    };
}

#endif //SCAVTRAP_HPP
