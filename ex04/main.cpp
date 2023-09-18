/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 23:13:27 by cmenke            #+#    #+#             */
/*   Updated: 2023/09/18 01:32:05 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ReplaceFileContents.hpp"

//expected input (filename, needle, replacement)
int	main(int argc, char **argv)
{
	ReplaceFileContents	modifyFileContents;

	if (argc != 4)
	{
		std::cerr << ERR_WRONG_ARG_NUM "\n" << ERR_EXPECTED_ARG << std::endl;
		return (1);
	}
	modifyFileContents.setInputFilename(argv[1]);
	if (!modifyFileContents.replace(argv[2], argv[3]))
		return (1);
	return (0);
}
