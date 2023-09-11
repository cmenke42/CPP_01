/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:12:36 by cmenke            #+#    #+#             */
/*   Updated: 2023/09/11 18:19:35 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
	public:
		void announce( void );
		
		// It creates a zombie, name it, and return it so you can use it outside of the function scope
		Zombie* newZombie( std::string name );

		// It creates a zombie, name it, and the zombie announces itself
		void randomChump( std::string name );

	private:
		std::string _name;

};




#endif /* ZOMBIE_HPP */