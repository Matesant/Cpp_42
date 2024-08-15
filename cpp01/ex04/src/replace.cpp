/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:03:06 by matesant          #+#    #+#             */
/*   Updated: 2024/08/15 19:29:21 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Replace.hpp"

Replace::~Replace()
{
}

Replace::Replace(std::string filename, std::string haystack, std::string needle)
{
	this->_filename = filename;
	this->_needle = needle;
	this->_haystack = haystack;
	return ;
}

void Replace::formatExtension(void)
{
	size_t lastDotIndex = this->_filename.rfind(".");
	if (lastDotIndex != std::string::npos)
	{
		this->_filename = this->_filename.substr(0, lastDotIndex);
	}
}

std::string Replace::getFilename(void) const
{
	return (this->_filename);
}

std::string Replace::getNeedle(void) const
{
	return (this->_needle);
}

std::string Replace::getHaystack(void) const
{
	return (this->_haystack);
}