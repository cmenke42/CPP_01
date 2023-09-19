/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:14:21 by cmenke            #+#    #+#             */
/*   Updated: 2023/09/19 16:08:12 by cmenke           ###   ########.fr       */
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

const char* Harl::complainLevels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

void	Harl::complain( std::string level)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (!std::strcmp(complainLevels[i], level.c_str()))
			break;
		i++;
	}
	if (i < 4)
		(this->*_complainFunctions[i])();
	else
		std::cerr << "Error: no level name:" << level << std::endl;
}

void	Harl::_debug( void )
{
	std::cerr << "DEBUG:" << std::endl;
}

void	Harl::_info( void )
{
	std::cerr << "INFO:" << std::endl;
}

void	Harl::_warning( void )
{
	std::cerr << "WARNING:" << std::endl;
}

void	Harl::_error( void )
{
	std::cerr << "ERROR:" << std::endl;
}
