/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:14:28 by cmenke            #+#    #+#             */
/*   Updated: 2023/09/19 16:08:46 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

class Harl
{
	public:
	Harl( void );
	~Harl( void );

	static const char*	complainLevels[4];
	void				complain( std::string level );

	private:
	void	_debug( void );
	void	_info( void );
	void	_warning( void );
	void	_error( void );

	const char*		_complainLevels[4];
	typedef void	(Harl::*_complainFun)(void);
	_complainFun	_complainFunctions[4];
};

#endif /* HARL_HPP */