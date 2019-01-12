/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Log.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 18:01:57 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/10 11:04:28 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOG_HPP
# define LOG_HPP

# include <string>
# include <iostream>
# include <fstream>

class Log
{
	public:
		~Log(void);

		static Log&	instance(void);

		void		log(const std::string& message) const;
		void		logWarning(const std::string& message) const;
		void		logError(const std::string& message) const;

	private:

		static Log	*_instance;
		std::string _FilePath;

		Log(void);
		Log(const Log& src);

		Log&		operator=(const Log& rhs);

		std::string	getTimestamp(void) const;
		std::string	makeLogEntry(const std::string& message) const;
};

#endif