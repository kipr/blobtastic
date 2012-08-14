/**************************************************************************
 *  Copyright 2012 KISS Institute for Practical Robotics                  *
 *                                                                        *
 *  This file is part of blobtastic.                                      *
 *                                                                        *
 *  blobtastic is free software: you can redistribute it and/or modify    *
 *  it under the terms of the GNU General Public License as published by  *
 *  the Free Software Foundation, either version 2 of the License, or     *
 *  (at your option) any later version.                                   *
 *                                                                        *
 *  blobtastic is distributed in the hope that it will be useful,         *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *  GNU General Public License for more details.                          *
 *                                                                        *
 *  You should have received a copy of the GNU General Public License     *
 *  along with blobtastic.  Check the LICENSE file in the project root.   *
 *  If not, see <http://www.gnu.org/licenses/>.                           *
 **************************************************************************/

/*!
 * \file channel.hpp
 * \author Braden McDorman
 * \copyright KISS Institute for Practical Robotics
 */

#ifndef _CHANNEL_HPP_
#define _CHANNEL_HPP_

#include <vector>
#include "blob.hpp"

class Channel
{
public:
	const Blob& blob(const unsigned int& index) const;
	const unsigned int& numberOfBlobs() const;
	
	void setBlobs(const std::vector<Blob>& blobs);
	
private:
	std::vector<Blob> m_blobs;
};

#endif
