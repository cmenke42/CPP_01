/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 21:19:51 by cmenke            #+#    #+#             */
/*   Updated: 2023/10/21 12:31:40 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

static void	initializeHorde(const int N, const std::string& name,
				Zombie heapHorde[]);

Zombie*	zombieHorde( int N, std::string name)
{
	Zombie*	heapHorde;

	if (N < 1)
	{
		std::cout << "Error: can't allocate horde \""<< name << "\". N < 1" << std::endl;
		return (NULL);
	}
	try
	{
		heapHorde = new Zombie[N];
	}
	catch (const std::bad_alloc& exception)
	{
		std::cerr << "Error: couldn't allocate Zombie horde: \"" << name << "\".\n";
		std::cerr << exception.what() << std:: endl;
		return (NULL);
	}
	initializeHorde(N, name, heapHorde);
	return (heapHorde);
}

static void	initializeHorde(const int N, const std::string& name, Zombie heapHorde[])
{
	int	i;

	i = 0;
	while (i < N)
	{
		heapHorde[i].setName(name);
		heapHorde[i].announce();
		i++;
	}
}
