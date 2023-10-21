/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 21:22:19 by cmenke            #+#    #+#             */
/*   Updated: 2023/10/21 12:31:02 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	randomChump( std::string name );
Zombie*	newZombie( std::string name);

int	main(void)
{
	Zombie* heapZombie = NULL;

	std::cout << "RANDOM" << std::endl;
	randomChump("stackRandom");

	std::cout << "\nALLOCATE" << std::endl;
	try
	{
		heapZombie = newZombie("heapZombie");
	}
	catch (const std::bad_alloc& e)
	{
		std::cout << "Memory allocation failed: " << e.what() << std::endl;
	}
	
	std::cout << "\nDELETE HEAP" << std::endl;
	delete heapZombie;
	return (0);
}
