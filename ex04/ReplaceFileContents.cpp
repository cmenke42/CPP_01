/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReplaceFileContents.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 00:19:06 by cmenke            #+#    #+#             */
/*   Updated: 2023/10/21 17:03:55 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ReplaceFileContents.hpp"

static bool	isDirectory(const std::string& filePath);

ReplaceFileContents::ReplaceFileContents(void)
{
}

ReplaceFileContents::~ReplaceFileContents()
{
}

bool	ReplaceFileContents::_openFiles(void)
{
	std::string	outputFileName;

	if (isDirectory(this->_inputFilename))
		return (false);
	outputFileName = this->_inputFilename + ".replace";
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

static bool	isDirectory(const std::string& filePath)
{
    struct stat path_stat;

	if (filePath.empty())
	{
		std::cerr << "Error: no input file" << std::endl;
		return (true);
	}
    if (stat(filePath.c_str(), &path_stat) != 0)
	{
		std::cerr << "Error: couldn't stat file" << std::endl;
		return (true);
	}
	if (!S_ISDIR(path_stat.st_mode))
		return (false);
	std::cerr << "Error: input file is a directory" << std::endl;
    return (true);
}

void	ReplaceFileContents::_closeFiles(void)
{
	_inputFile.close();
	_outputFile.close();
}

void	ReplaceFileContents::setInputFilename(const std::string inputFilename)
{
	this->_inputFilename = inputFilename;
}

bool	ReplaceFileContents::replace(const std::string needle, const std::string replacement)
{
	std::string	line;

	if (!this->_openFiles())
		return (false);
	while (std::getline(this->_inputFile, line))
	{
		if(this->_inputFile.fail() || this->_outputFile.fail())
		{
			std::cerr << "Error: couldn't read/write to files" << std::endl;
			this->_closeFiles();
			return (false);
		}
		this->_replaceNeedleInHaystack(line, needle, replacement);
		this->_outputFile << line;
		if (!this->_inputFile.eof())
			this->_outputFile << '\n';
	}
	this->_outputFile.flush();
	this->_closeFiles();
	return (true);
}

void	ReplaceFileContents::_replaceNeedleInHaystack(std::string& haystack, const std::string& needle,
			const std::string& replacement)
{
	size_t	lenOfNeedle;
	size_t	lenOfReplacement;
	size_t	startOfReplacement;
	size_t	startOfSearch;

	if (haystack.empty())
		return ;
	lenOfNeedle = needle.length();
	lenOfReplacement = replacement.length();
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
