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
 * \file blob.hpp
 * \author Braden McDorman
 * \copyright KISS Institute for Practical Robotics
 */

#ifndef _BLOB_HPP_
#define _BLOB_HPP_

class Blob
{
public:
	Blob(const int& cx, const int& cy,
		const int& width, const int& height,
		const double& confidence);
		
	Blob();
	
	const int& centerX() const;
	const int& centerY() const;
	const int& width() const;
	const int& height() const;
	const double& confidence() const;
	
	const bool& isValid() const;
private:
	
	int m_cx;
	int m_cy;
	int m_width;
	int m_height;
	double m_confidence;
	
	bool m_valid;
};

#endif
