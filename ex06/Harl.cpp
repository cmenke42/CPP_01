/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:14:21 by cmenke            #+#    #+#             */
/*   Updated: 2023/10/21 17:38:58 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl( void )
{
    _complainFunctions[0] = &Harl::_debug;
    _complainFunctions[1] = &Harl::_info;
    _complainFunctions[2] = &Harl::_warning;
    _complainFunctions[3] = &Harl::_error;
}

Harl::~Harl( void )
{
}

const std::string Harl::complainLevels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

void	Harl::complain( std::string level)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (level == complainLevels[i])
			break;
		i++;
	}
	switch (i)
	{
		case 0:
			(this->*_complainFunctions[0])();
		case 1:
			(this->*_complainFunctions[1])();
		case 2:
			(this->*_complainFunctions[2])();
		case 3:
			(this->*_complainFunctions[3])();
			break;
		default:
			std::cout << INFO_USELESS << std::endl;
	}
}

void	Harl::_debug( void )
{
	std::cout << "DEBUG:" << std::endl;
}

void	Harl::_info( void )
{
	std::cout << "INFO:" << std::endl;
}

void	Harl::_warning( void )
{
	std::cout << "WARNING:" << std::endl;
}

void	Harl::_error( void )
{
	std::cout << "ERROR:" << std::endl;
}
