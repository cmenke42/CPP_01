/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 21:22:19 by cmenke            #+#    #+#             */
/*   Updated: 2023/09/11 22:34:24 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie* zombie1;
	Zombie* zombie2;
	Zombie	zombie3("three");
	Zombie	zombie4("four");

	std::cout << "\nRANDOM" << std::endl;
	Zombie::randomChump("rand_three");
	Zombie::randomChump("rand_four");

	std::cout << "\nALLOCATE" << std::endl;
	zombie1 = Zombie::newZombie("one");
	zombie2 = Zombie::newZombie("two");

	std::cout << "\nDELETE HEAP" << std::endl;
	delete zombie1;
	delete zombie2;

	std::cout << "\nDELETE OTHERS" << std::endl;
	return (0);
}
