/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 21:22:19 by cmenke            #+#    #+#             */
/*   Updated: 2023/09/11 23:36:50 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie* zombieHorde1;
	Zombie* zombieHorde2;
	Zombie* zombieHorde3;

	std::cout << "\nALLOCATE HORDES" << std::endl;
	zombieHorde1 = Zombie::zombieHorde(-1, "horde -1");
	zombieHorde1 = Zombie::zombieHorde(0, "horde 0");
	zombieHorde2 = Zombie::zombieHorde(5, "horde 5");
	zombieHorde3 = Zombie::zombieHorde(900000000, "horde 900000000");

	std::cout << "\nDELETING HORDES" << std::endl;
	delete[] zombieHorde1;
	delete[] zombieHorde2;
	delete[] zombieHorde3;

	return (0);
}
