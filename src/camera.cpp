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

#include "camera.hpp"
#include "camera_p.hpp"
#include <opencv2/opencv.hpp>

#include "verbose.h"

Camera::Camera(int id)
	: m_id(id),
	m_private(new CameraPrivate) {}

Camera::Camera()
	: m_id(0),
	m_private(new CameraPrivate) {}

bool Camera::open()
{
	return m_private->capture.open(m_id) ? update() : false;
}

bool Camera::isOpen() const
{
	return m_private->capture.isOpened();
}

unsigned int Camera::availableCameras()
{
	return 1; // TODO: Implement
}

bool Camera::update()
{
	if(!m_private->capture.grab()) return false;
	m_private->capture.retrieve(m_private->raw);
	m_private->rgbValid = m_private->hsvValid = false;
	return true;
}

unsigned char *Camera::frame()
{
	if(m_private->raw.empty()) return 0;
	updateRgb();
	return m_private->rgb.data;
}

bool Camera::putFrame(unsigned char *buffer)
{
	return putFrame(buffer, frameWidth(), frameHeight());
}

bool Camera::putFrame(unsigned char *buffer, const unsigned short& width, const unsigned short& height)
{
	if(m_private->raw.empty()) return false;
	updateRgb();
	cv::Mat scaled;
	cv::resize(m_private->rgb, scaled, cv::Size(width, height));
	if(width * height < scaled.rows * scaled.cols) {
		error("put frame failed. Buffer is too small. (needed %u, got %u)\n",
			width * height, scaled.rows * scaled.cols);
		return false;
	}
	memcpy(buffer, scaled.data, scaled.rows * scaled.cols * scaled.elemSize());
	return true;
}

unsigned char *Camera::frameHsv()
{
	if(m_private->raw.empty()) return 0;
	updateHsv();
	return m_private->hsv.ptr();
}

bool Camera::putFrameHsv(unsigned char *buffer)
{
	return putFrameHsv(buffer, frameWidth(), frameHeight());
}

bool Camera::putFrameHsv(unsigned char *buffer, const unsigned short& width, const unsigned short& height)
{
	if(m_private->raw.empty()) return false;
	updateHsv();
	cv::Mat scaled;
	cv::resize(m_private->hsv, scaled, cv::Size(width, height));
	if(width * height < scaled.rows * scaled.cols) {
		error("put frame hsv failed. Buffer is too small. (needed %u, got %u)\n",
			width * height, scaled.rows * scaled.cols);
		return false;
	}
	memcpy(buffer, scaled.data, scaled.rows * scaled.cols * scaled.elemSize());
	return true;
}

unsigned char *Camera::frameRow(int row)
{
	if(m_private->raw.empty()) return 0;
	updateRgb();
	return m_private->rgb.ptr(row);
}

unsigned char *Camera::framePixel(const unsigned short& x, const unsigned short& y)
{
	if(m_private->raw.empty()) return 0;
	updateRgb();
	return frameRow(y) + x * 3;
}

unsigned int Camera::frameSize()
{
	return frameWidth() * frameHeight() * 3;
}

unsigned short Camera::frameWidth()
{
	return m_private->raw.cols;
}

unsigned short Camera::frameHeight()
{
	return m_private->raw.rows;
}

void Camera::close()
{
	m_private->capture.release();
}

bool Camera::image(cv::Mat *data) const
{
	if(m_private->raw.empty()) return false;
	m_private->raw.copyTo(*data);
	return true;
}

void Camera::updateRgb()
{
	if(m_private->rgbValid) return;
	cv::cvtColor(m_private->raw, m_private->rgb, CV_BGR2RGB);
	m_private->rgbValid = true;
}

void Camera::updateHsv()
{
	if(m_private->hsvValid) return;
	cv::cvtColor(m_private->raw, m_private->hsv, CV_BGR2HSV);
	m_private->hsvValid = true;
}