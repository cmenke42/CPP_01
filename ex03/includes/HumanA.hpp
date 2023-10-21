/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 23:39:36 by cmenke            #+#    #+#             */
/*   Updated: 2023/10/21 12:50:55 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

#include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string name, Weapon& _weaponType);
		~HumanA(void);
		void	attack(void) const;

	private:
		std::string	_name;
		Weapon&		_weaponType;
};

#endif /* HUMAN_A_HPP */
