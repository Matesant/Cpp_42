/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:56:49 by matesant          #+#    #+#             */
/*   Updated: 2024/08/22 12:03:01 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

# include "Utils.hpp"

// Class declaration
class Replace
{
  public:
	Replace(std::string filename, std::string needle, std::string haystack);
	~Replace();

	std::string getFilename(void) const;
	std::string getHaystack(void) const;
	std::string getNeedle(void) const;

  private:
	std::string _filename;
	std::string _needle;
	std::string _haystack;
};

#endif
