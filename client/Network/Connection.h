/**
 * Stars client
 *
 * Copyright (C) 2012, Jan Kaluza <hanzz.k@gmail.com>
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

#include "SDL/SDL_net.h"
#include <vector>

class DataHandler;

class Connection {
	public:
		Connection(DataHandler *handler, IPaddress ip, int port);
		~Connection();

		void start();
		void stop();

		bool isConnected() {
			return m_sock != NULL;
		}

		void readData();

		void sendData(const char *data, unsigned long len);


	private:
		IPaddress m_ip;
		int m_port;
		TCPsocket m_sock;
		std::vector<char> m_buffer;
		DataHandler *m_handler;

	friend class ConnectionManager;
};
