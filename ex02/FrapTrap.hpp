#ifndef FRAPTRAP_HPP
#define FRAPTRAP_HPP

#include "ClapTrap.hpp"

namespace ClapTrap
{
    class FrapTrap : public ClapTrap
    {
    public:
        FrapTrap();
        explicit FrapTrap(const std::string& name);
        FrapTrap(const FrapTrap& other);

        ~FrapTrap();

        FrapTrap& operator=(const FrapTrap& other);

        void highFivesGuys();
    };
}

#endif //FRAPTRAP_HPP
