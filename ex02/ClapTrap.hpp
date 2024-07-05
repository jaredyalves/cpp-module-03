#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

namespace ClapTrap
{
    class ClapTrap
    {
    public:
        ClapTrap();
        explicit ClapTrap(const std::string& name);
        ClapTrap(const ClapTrap& other);

        ~ClapTrap();

        ClapTrap& operator=(const ClapTrap& other);

        std::string  getName() const;
        void         setName(const std::string& name);
        unsigned int getHitPoints() const;
        void         setHitPoints(unsigned int hit_points);
        unsigned int getEnergyPoints() const;
        void         setEnergyPoints(unsigned int energy_points);
        unsigned int getAttackDamage() const;
        void         setAttackDamage(unsigned int attack_damage);

        bool hasEnoughPoints() const;
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

    protected:
        std::string  _name;
        unsigned int _hit_points;
        unsigned int _energy_points;
        unsigned int _attack_damage;
    };
}

#endif //CLAPTRAP_HPP
