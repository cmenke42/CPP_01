/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:21:29 by cmenke            #+#    #+#             */
/*   Updated: 2023/09/19 16:23:56 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	printHarlMessages(Harl& messagesFromHarl, const int i);

int	main(int argc, char **argv)
{
	Harl	messagesFromHarl;
	int		i;

	if (argc != 2)
	{
		std::cerr << ERR_ARG_COUNT << std::endl;
		return (1);
	}
	i = 0;
	while (i < 4)
	{
		if (!std::strcmp(argv[1], Harl::complainLevels[i]))
			break;
		i++;
	}
	printHarlMessages(messagesFromHarl, i);
	return (0);
}

void	printHarlMessages(Harl& messagesFromHarl, const int i)
{
	switch (i)
	{
		case 0:
			messagesFromHarl.complain("DEBUG");
			messagesFromHarl.complain("INFO");
			messagesFromHarl.complain("WARNING");
			messagesFromHarl.complain("ERROR");
			break;
		case 1:
			messagesFromHarl.complain("INFO");
			messagesFromHarl.complain("WARNING");
			messagesFromHarl.complain("ERROR");
			break;
		case 2:
			messagesFromHarl.complain("WARNING");
			messagesFromHarl.complain("ERROR");
			break;
		case 3:
			messagesFromHarl.complain("ERROR");
			break;
		default:
			std::cerr << INFO_USELESS << std::endl;
	}
}
