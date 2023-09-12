/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 21:19:51 by cmenke            #+#    #+#             */
/*   Updated: 2023/09/11 22:11:43 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	Zombie::newZombie( std::string name)
{
	Zombie*	createdZombie;

	try
	{
		createdZombie = new Zombie(name);
	}
	catch (const std::bad_alloc& exception)
	{
		std::cerr << "Error: couldn't allocate Zombie: " << name << ". ";
		std::cerr << exception.what() << std:: endl;
		return (NULL);
	}
	return (createdZombie);
}
