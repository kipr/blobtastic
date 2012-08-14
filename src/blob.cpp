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

#include "blob.hpp"

Blob::Blob(const int& cx, const int& cy,
	const int& width, const int& height,
	const double& confidence)
	: m_cx(cx),
	m_cy(cy),
	m_width(width),
	m_height(height),
	m_confidence(confidence),
	m_valid(true) {}

Blob::Blob()
	: m_cx(0),
	m_cy(0),
	m_width(0),
	m_height(0),
	m_confidence(0),
	m_valid(false) {}


const int& Blob::centerX() const
{
	return m_cx;
}

const int& Blob::centerY() const
{
	return m_cy;
}

const int& Blob::width() const
{
	return m_width;
}

const int& Blob::height() const
{
	return m_height;
}

const double& Blob::confidence() const
{
	return m_confidence;
}

const bool& Blob::isValid() const
{
	return m_valid;
}