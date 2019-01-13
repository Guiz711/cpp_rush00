/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Log.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 18:17:42 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/10 11:07:52 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Log.hpp"

Log	*Log::_instance = NULL;

Log::Log(void):
	_FilePath("./log.txt")
{}

Log::Log(const Log& src):
	_FilePath(src._FilePath)
{}

Log::~Log(void) {}

Log&	Log::operator=(const Log& rhs)
{
	if(this  == &rhs)
		return *this;

	_FilePath = rhs._FilePath;
	return *this;
}

Log&	Log::instance(void)
{
	if(_instance == NULL)
		_instance = new Log();
	return *_instance;
}

std::string	Log::getTimestamp(void) const
{
	std::time_t now;
	struct tm	timestruct;
	char		buff[19];

	now = std::time(NULL);
	timestruct = *localtime(&now);
	std::strftime(buff, sizeof(buff), "[%Y%m%d_%H%M%S] ", &timestruct);
	return std::string(buff);
}

std::string	Log::makeLogEntry(const std::string& message) const
{
	return (this->getTimestamp() + message);
}

void		Log::log(const std::string& message) const
{
	std::ofstream	ofs(_FilePath.c_str(), std::ios::out | std::ios::app);

	if (ofs.is_open())
		ofs << this->getTimestamp()
			<< "    LOG | " << message << std::endl;
	else
		std::cout << this->_FilePath << " couldn't be open." << std::endl;
	ofs.close();
}

void		Log::logWarning(const std::string& message) const
{
	std::ofstream	ofs(_FilePath.c_str(), std::ios::out | std::ios::app);

	if (ofs.is_open())
		ofs << this->getTimestamp()
			<< "WARNING | " << message << std::endl;
	else
		std::cout << this->_FilePath << " couldn't be open." << std::endl;
	ofs.close();
}

void		Log::logError(const std::string& message) const
{
	std::ofstream	ofs(_FilePath.c_str(), std::ios::out | std::ios::app);

	if (ofs.is_open())
		ofs << this->getTimestamp()
			<< "  ERROR | " << message << std::endl;
	else
		std::cout << this->_FilePath << " couldn't be open." << std::endl;
	ofs.close();
}
