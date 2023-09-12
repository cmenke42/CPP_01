/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:12:36 by cmenke            #+#    #+#             */
/*   Updated: 2023/09/11 23:12:34 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
	public:
		Zombie( std::string name );
		~Zombie( void );

		static Zombie*	newZombie( std::string name );
		static void		randomChump( std::string name );

		void			announce( void );
	private:
		std::string _name;

};

#endif /* ZOMBIE_HPP */
