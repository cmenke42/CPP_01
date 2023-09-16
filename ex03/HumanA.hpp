/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 23:39:36 by cmenke            #+#    #+#             */
/*   Updated: 2023/09/16 18:05:41 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

#include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string name, Weapon& weaponName);
		~HumanA(void);
		void	attack(void) const;

	private:
		std::string	_name;
		Weapon&		_weapon;
};

#endif /* HUMAN_A_HPP */
