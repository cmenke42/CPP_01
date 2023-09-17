/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:59:51 by cmenke            #+#    #+#             */
/*   Updated: 2023/09/17 22:56:05 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ReplaceString.hpp"

bool	openFiles(char* inputFileName, char* searchFor, char* replacement);


//expected input (3), (filename, search, replace)
int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << ERR_WRONG_ARG_NUM "\n" << ERR_EXPECTED_ARG << std::endl;
		return (1);
	}
	openFiles(argv[1], argv[2], argv[3]);
}


bool	openFiles(char* inputFileName, char* searchFor, char* replacement)
{
	std::ifstream	inputFile;
	std::string		oneLine;
	size_t			startOfReplacement;
	size_t			lenOfNeedle;
	size_t			position;

	inputFile.open(inputFileName, std::fstream::in);
	if (!inputFile.is_open())
	{
		std::cerr << "Error: couldn't open input File:" << inputFileName << std::endl;
		return (false);
	}
	lenOfNeedle = std::strlen(searchFor);
	while (inputFile.good())
	{
		position = 0;
		std::getline(inputFile, oneLine);
		std::cout << "OLD:" << oneLine << std::endl;
		while (1)
		{
			startOfReplacement = oneLine.find(searchFor, position);
			std::cout
			if (startOfReplacement == std::string::npos)
				break;
			oneLine.erase(startOfReplacement, startOfReplacement + lenOfNeedle);
			oneLine.insert(startOfReplacement, replacement);
			position = startOfReplacement + lenOfNeedle;
		}
		std::cout << "NEW:" << oneLine << std::endl;
	}
	inputFile.close();
	return (true);
}
