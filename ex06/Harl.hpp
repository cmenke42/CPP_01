/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:14:28 by cmenke            #+#    #+#             */
/*   Updated: 2023/10/21 17:29:59 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

#define ERR_ARG_COUNT "Error: Wrong number of arguments"
#define INFO_USELESS "[ Probably complaining about insignificant problems ]"

class Harl
{
	public:
	Harl( void );
	~Harl( void );

	static const std::string	complainLevels[4];
	void						complain( std::string level );

	private:
	void	_debug( void );
	void	_info( void );
	void	_warning( void );
	void	_error( void );

	typedef void	(Harl::*_complainFun)(void);
	_complainFun	_complainFunctions[4];
};

#endif /* HARL_HPP */
