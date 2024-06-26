/*
 *  Copyright (c) 2023 Rhys Bryant
 *  Author Rhys Bryant
 *
 *	This file is part of SimpleHTTP
 *
 *   SimpleHTTP is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU Lesser General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   any later version.
 *
 *   SimpleHTTP is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU Lesser General Public License for more details.
 *
 *   You should have received a copy of the GNU Lesser General Public License
 *   along with SimpleHTTP.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once
#include "ServerConnection.h"
#include <string>
namespace SimpleHTTPTest {
	//Dummy Connection for Testing
	class MockServerConnection: public SimpleHTTP::ServerConnection {
	public:
		std::string buffer;
		bool writeData(uint8_t* data, int len, uint8_t apiFlags) {
			buffer.append((char*)data, len);
			return true;
		}

		inline bool write(uint8_t* data, uint16_t len) {
			buffer.append((char*)data, len);
			return true;
		}
	};
}