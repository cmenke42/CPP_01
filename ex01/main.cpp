/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 21:22:19 by cmenke            #+#    #+#             */
/*   Updated: 2023/10/21 12:32:30 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name);

int	main(void)
{
	Zombie* zombieHorde1 = NULL;

	std::cout << "ALLOCATE HORDE" << std::endl;
	zombieHorde1 = zombieHorde(-1, "horde -1");
	zombieHorde1 = zombieHorde(0, "horde 0");
	zombieHorde1 = zombieHorde(5, "horde 5");

	std::cout << "\nDELETING HORDE" << std::endl;
	delete[] zombieHorde1;

	return (0);
}
