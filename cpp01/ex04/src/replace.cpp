/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:03:06 by matesant          #+#    #+#             */
/*   Updated: 2024/08/22 12:02:52 by matesant         ###   ########.fr       */
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