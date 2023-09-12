/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:12:01 by cmenke            #+#    #+#             */
/*   Updated: 2023/09/11 22:24:35 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : _name("")
{
}

Zombie::~Zombie( void )
{
	std::cout << _name << " destroyed." << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << this->_name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName( const std::string& name)
{
	this->_name = name;
}
