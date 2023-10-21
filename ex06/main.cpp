/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:21:29 by cmenke            #+#    #+#             */
/*   Updated: 2023/10/21 17:39:39 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl	messagesFromHarl;

	if (argc != 2)
	{
		std::cerr << ERR_ARG_COUNT << std::endl;
		return (1);
	}
	messagesFromHarl.complain(argv[1]);
	return (0);
}
