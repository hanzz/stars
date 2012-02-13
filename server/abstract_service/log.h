/**
 * Hamlog
 *
 * Copyright (C) 2011, Jan Kaluza <hanzz.k@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02111-1301  USA
 */

#pragma once

#include <iostream>

#ifdef WITH_LOG4CXX
#include "log4cxx/logger.h"
#include "log4cxx/consoleappender.h"
#include "log4cxx/patternlayout.h"
#include "log4cxx/propertyconfigurator.h"
#include "log4cxx/helpers/properties.h"
#include "log4cxx/helpers/transcoder.h"
#include "log4cxx/helpers/fileinputstream.h"
using namespace log4cxx;
#endif

#ifdef WITH_LOG4CXX
#define DEFINE_LOGGER(VARIABLE, NAME) static log4cxx::LoggerPtr VARIABLE = log4cxx::Logger::getLogger(NAME);
#define LOG_ERROR LOG4CXX_ERROR
#define LOG_WARN LOG4CXX_WARN
#define LOG_INFO LOG4CXX_INFO
#else
#define DEFINE_LOGGER(VARIABLE, NAME) static const char *VARIABLE = NAME;

#define LOG_ERROR(LOGGER, DATA) std::cerr << "E: <" << LOGGER << "> " << DATA << "\n";
#define LOG_WARN(LOGGER, DATA) std::cout << "W: <" << LOGGER << "> " << DATA << "\n";
#define LOG_INFO(LOGGER, DATA) std::cout << "I: <" << LOGGER << "> " << DATA << "\n";

#endif
