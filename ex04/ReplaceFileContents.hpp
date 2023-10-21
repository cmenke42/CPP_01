/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReplaceFileContents.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 21:01:16 by cmenke            #+#    #+#             */
/*   Updated: 2023/10/21 17:00:03 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_FILE_CONTENTS_HPP
# define REPLACE_FILE_CONTENTS_HPP


#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <sys/stat.h>

#define ERR_WRONG_ARG_NUM "Error: Wrong number of arguments."
#define ERR_EXPECTED_ARG "Expected arguments: filename, string \
to seach for, replacement"

class ReplaceFileContents
{
	public:
		ReplaceFileContents(void);
		~ReplaceFileContents(void);

		void	setInputFilename(const std::string inputFilename);
		bool	replace(const std::string needle, const std::string replacement);

	private:
		std::string		_inputFilename;
		std::ifstream	_inputFile;
		std::ofstream	_outputFile;

		bool			_openFiles(void);
		void			_closeFiles(void);
		void			_replaceNeedleInHaystack(std::string& haystack, const std::string& needle,
							const std::string& replacement);
};

#endif /* REPLACE_FILE_CONTENTS_HPP */
