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

#include "basic_detector.hpp"
#include "image.hpp"
#include "channel.hpp"
#include "camera_format.hpp"

struct BasicChannel
{
	HSV min;
	HSV max;
	Channel channel;
};

BasicDetector::BasicDetector()
{
	
}

BasicDetector::~BasicDetector()
{
	std::vector<BasicChannel *>::const_iterator it = m_channels.begin();
	for(; it != m_channels.end(); ++it) delete *it;
}

void BasicDetector::update(Image *image)
{
	std::vector<BasicChannel *>::const_iterator it = m_channels.begin();
	for(; it != m_channels.end(); ++it) {
		
	}
}

unsigned int BasicDetector::numberOfChannels() const
{
	return m_channels.size();
}

const Channel *BasicDetector::channel(const unsigned int& index) const
{
	if(index >= m_channels.size()) return 0;
	return &m_channels[index]->channel;
}

void BasicDetector::updateChannel(BasicChannel *channel)
{
	
}