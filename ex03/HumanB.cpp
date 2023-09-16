/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 00:08:15 by cmenke            #+#    #+#             */
/*   Updated: 2023/09/16 18:02:42 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"


HumanB::HumanB(std::string name)
		: _name(name), _weapon(NULL)
{

}

HumanB::~HumanB()
{
}

void	HumanB::attack(void) const
{
	std::cout << this->_name << " attacks with their ";
	if (this->_weapon)
		std::cout << this->_weapon->getType();
	std::cout << std::endl;
}

void	HumanB::setWeapon(Weapon& weaponName)
{
	this->_weapon = &weaponName;
}

void	HumanB::setWeapon(Weapon* weaponName)
{
	this->_weapon = weaponName;
}
