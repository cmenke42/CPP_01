/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 21:19:51 by cmenke            #+#    #+#             */
/*   Updated: 2023/09/11 22:59:51 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

static void	initializeHorde(const int N, const std::string& name,
				Zombie createdHorde[]);

Zombie*	Zombie::zombieHorde( int N, std::string name)
{
	Zombie*	createdHorde;

	if (N < 1)
	{
		std::cout << "Error: can't allocate horde \""<< name << "\" smaller 1" << std::endl;
		return (NULL);
	}
	try
	{
		createdHorde = new Zombie[N];
	}
	catch (const std::bad_alloc& exception)
	{
		std::cerr << "Error: couldn't allocate Zombie horde: \"" << name << "\". \n";
		std::cerr << exception.what() << std:: endl;
		return (NULL);
	}
	initializeHorde(N, name, createdHorde);
	return (createdHorde);
}

static void	initializeHorde(const int N, const std::string& name,
				Zombie createdHorde[])
{
	int	i;

	i = 0;
	while (i < N)
	{
		createdHorde[i].setName(name);
		createdHorde[i].announce();
		i++;
	}
}
