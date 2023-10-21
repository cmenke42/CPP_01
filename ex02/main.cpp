/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 23:17:02 by cmenke            #+#    #+#             */
/*   Updated: 2023/10/21 12:37:57 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string		stringVAR;
	std::string*	stringPTR;
	std::string&	stringREF = stringVAR;

	stringVAR = "HI THIS IS BRAIN";
	stringPTR = &stringVAR;

	std::cout << "PRINTING ADDRESSES HELD BY\n";
	std::cout << "stringVAR:" << &stringVAR;
	std::cout << "\nstringPTR:" << stringPTR;
	std::cout << "\nstringREF:" << &stringREF;

	std::cout << "\n\nPRINTING VALUES POINTED TO BY";
	std::cout << "\nstringVAR:" << stringVAR;
	std::cout << "\nstringPTR:" << *stringPTR;
	std::cout << "\nstringREF:" << stringREF << std::endl;
	return (0);
}
