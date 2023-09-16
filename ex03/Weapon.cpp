/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 00:10:20 by cmenke            #+#    #+#             */
/*   Updated: 2023/09/16 18:02:33 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& weaponType) : _type(weaponType) 
{

}

Weapon::~Weapon(void)
{

}

const std::string&	Weapon::getType(void) const
{
	return (this->_type);
}

void	Weapon::setType(const std::string& weaponType)
{
	this->_type = weaponType;
}
