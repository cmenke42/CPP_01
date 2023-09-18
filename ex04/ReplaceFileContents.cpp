/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReplaceFileContents.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 00:19:06 by cmenke            #+#    #+#             */
/*   Updated: 2023/09/18 01:21:17 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ReplaceFileContents.hpp"

ReplaceFileContents::ReplaceFileContents(void)
{
}

ReplaceFileContents::~ReplaceFileContents()
{
}

bool	ReplaceFileContents::_openFiles(void)
{
	std::string	outputFileName;

	outputFileName = (outputFileName + this->_inputFilename) + ".replace";
	this->_inputFile.open(this->_inputFilename, std::ifstream::in);
	if(!this->_inputFile.is_open())
	{
		std::cerr << "Error: couldn't open input File:" << this->_inputFilename << std::endl;
		return (false);
	}
	this->_outputFile.open(outputFileName.c_str(), std::ofstream::out | std::ofstream::trunc);
	if(!this->_outputFile.is_open())
	{
		std::cerr << "Error: couldn't open output File" << outputFileName << std::endl;
		this->_inputFile.close();
		return (false);
	}
	return (true);
}

void	ReplaceFileContents::_closeFiles(void)
{
	_inputFile.close();
	_outputFile.close();
}

void	ReplaceFileContents::setInputFilename(const char* inputFilename)
{
	this->_inputFilename = inputFilename;
}

bool	ReplaceFileContents::replace(const char* needle, const char* replacement)
{
	std::string	line;

	if (!this->_openFiles())
		return (false);
	while (std::getline(this->_inputFile, line))
	{
		this->_replaceNeedleInHaystack(line, needle, replacement);
		this->_outputFile << line << '\n';
		if(!this->_inputFile.good() || !this->_outputFile.good())
		{
			std::cerr << "Error: couldn't read/write to files" << std::endl;
			this->_closeFiles();
			return (false);
		}
	}
	this->_outputFile.flush();
	this->_closeFiles();
	return (true);
}

void	ReplaceFileContents::_replaceNeedleInHaystack(std::string& haystack, const char* needle,
			const char* replacement)
{
	size_t	lenOfNeedle;
	size_t	lenOfReplacement;
	size_t	startOfReplacement;
	size_t	startOfSearch;

	if (haystack.empty() || !needle || !replacement)
		return ;
	lenOfNeedle = std::strlen(needle);
	lenOfReplacement = std::strlen(replacement);
	startOfSearch = 0;
	if (lenOfNeedle == 0)
		return ;
	while (1)
	{
		startOfReplacement = haystack.find(needle, startOfSearch);
		if (startOfReplacement == std::string::npos)
			break ;
		haystack.erase(startOfReplacement, lenOfNeedle);
		haystack.insert(startOfReplacement, replacement);
		startOfSearch = startOfReplacement + lenOfReplacement;
	}
}
