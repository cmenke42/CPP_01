/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 23:17:02 by cmenke            #+#    #+#             */
/*   Updated: 2023/09/11 23:27:52 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string		stringVar;
	std::string*	stringPTR;
	std::string&	stringREF = stringVar;

	stringVar = "HI THIS IS BRAIN";
	stringPTR = &stringVar;

	std::cout << "PRINTING ADDRESSES" << std::endl;
	std::cout << "stringVar:" << &stringVar << std::endl;
	std::cout << "stringPTR:" << stringPTR << std::endl;
	std::cout << "stringREF:" << &stringREF << std::endl;

	std::cout << "\nPRINTING VALUES" << std::endl;
	std::cout << "stringVar:" << stringVar << std::endl;
	std::cout << "stringPTR:" << *stringPTR << std::endl;
	std::cout << "stringREF:" << stringREF << std::endl;
	return (0);
}