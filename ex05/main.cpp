/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:21:29 by cmenke            #+#    #+#             */
/*   Updated: 2023/09/18 19:27:38 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl	messagesFromHarl;

	messagesFromHarl.complain("DEBUG");
	messagesFromHarl.complain("INFO");
	messagesFromHarl.complain("WARNING");
	messagesFromHarl.complain("ERROR");
	messagesFromHarl.complain("nonsense");
}
