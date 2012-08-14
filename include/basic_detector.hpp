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
 * \file basic_detector.hpp
 * \author Braden McDorman
 * \copyright KISS Institute for Practical Robotics
 */

#ifndef _BASIC_DETECTOR_HPP_
#define _BASIC_DETECTOR_HPP_

#include "detector.hpp"
#include <vector>

struct BasicChannel;

class BasicDetector : public Detector
{
public:
	BasicDetector();
	virtual ~BasicDetector();
	
	virtual void update(Image *image);
	
	virtual unsigned int numberOfChannels() const;
	virtual const Channel *channel(const unsigned int& index) const;
private:
	void updateChannel(BasicChannel *channel);
	
	std::vector<BasicChannel *> m_channels;
};


#endif
