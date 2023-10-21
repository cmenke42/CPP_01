/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 00:08:15 by cmenke            #+#    #+#             */
/*   Updated: 2023/10/21 12:57:38 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"


HumanB::HumanB(std::string name)
		: _name(name), _weaponType(NULL)
{

}

HumanB::~HumanB()
{
}

void	HumanB::attack(void) const
{
	if (!this->_weaponType)
		std::cout << this->_name << " has no weapon" << std::endl;
	else
	{
		std::cout << this->_name << " attacks with: ";
		std::cout << this->_weaponType->getType() << std::endl;
	}
}

void	HumanB::setWeapon(Weapon& weaponType)
{
	this->_weaponType = &weaponType;
}

void	HumanB::setWeapon(Weapon* weaponType)
{
	this->_weaponType = weaponType;
}
