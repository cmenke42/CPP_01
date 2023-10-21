/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 00:10:11 by cmenke            #+#    #+#             */
/*   Updated: 2023/10/21 13:09:12 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	std::cout << "BOB" << std::endl;
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	std::cout << "\nJIM" << std::endl;
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}	
	std::cout << "\nRANDY" << std::endl;
	{
		Weapon club = Weapon("crude spiked club");
		HumanB randy("Randy");
		randy.setWeapon(NULL);
		randy.attack();
		club.setType("some other type of club");
		randy.attack();
		randy.setWeapon(club);
		randy.attack();
	}
	return (0);
}
