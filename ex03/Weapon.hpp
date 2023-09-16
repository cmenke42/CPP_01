/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 00:08:48 by cmenke            #+#    #+#             */
/*   Updated: 2023/09/16 18:02:29 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{
	public:
	Weapon(const std::string& weaponType);
	~Weapon(void);

	const std::string&	getType(void) const;
	void				setType(const std::string& weaponType);
	
	private:
		std::string	_type;
};

#endif /* WEAPON_HPP */
