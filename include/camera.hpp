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
 * \file blobtastic.hpp
 * \author Braden McDorman
 * \copyright KISS Institute for Practical Robotics
 */

#ifndef _CAMERA_HPP_
#define _CAMERA_HPP_

#include "image.hpp"

struct CameraPrivate;

class Camera : public Image
{
public:
	Camera(int id);
	Camera();
	
	bool open();
	
	bool isOpen() const;

	static unsigned int availableCameras();

	/*!
	 * Grabs a new frame from the currently opened camera.
	 * Returns 1 on success, 0 otherwise.
	 */
	bool update();

	/*!
	 * Get the current frame as a 1 dimensional array.
	 * \return Current frame data in RGB format. This pointer is only valid until update() is called again.
	 * \see camera_update
	 * \see get_camera_frame_size
	 */
	unsigned char *frame();
	
	bool putFrame(unsigned char *buffer);
	bool putFrame(unsigned char *buffer, const unsigned short& width, const unsigned short& height);

	/*!
	 * Get the current frame as a 1 dimensional array.
	 * \return Current frame data in HSV format. This pointer is only valid until update() is called again.
	 * \see camera_update
	 * \see get_camera_frame
	 */
	unsigned char *frameHsv();
	
	bool putFrameHsv(unsigned char *buffer);
	bool putFrameHsv(unsigned char *buffer, const unsigned short& width, const unsigned short& height);

	/*!
	 * Gets a pointer to the beginning of the specified row. This is a convenience
	 * method that is equivilent to: get_camera_frame()[row * frameWidth()]
	 *
	 * \return The pointer to the first byte of the specified row. 0 if row is out of bounds.
	 */
	unsigned char *frameRow(int row);

	/*!
	 * Gets a pointer to the beginning of the specified pixel. This is a convenience
	 * method that is equivilent to: frame()[y * frameWidth() + x]
	 *
	 * \return The pointer to the first byte of the specified pixel, 0 if x or y are out of bounds.
	 */
	unsigned char *framePixel(const unsigned short& x, const unsigned short& y);

	/*!
	 * Gets the number of pixels returned by get_camera_frame()
	 * 
	 * \return The number of pixels in the frame.
	 * \note The actual size of the array is three times as large as this method returns. This is because each pixel is three bytes.
	 * \see get_camera_frame_width()
	 * \see get_camera_frame()
	 */
	unsigned int frameSize();

	/*!
	 * Gets the width of the frame returned by get_camera_frame().
	 * \return The width of the frame, in pixels.
	 */
	unsigned short frameWidth();

	/*!
	 * Gets the height of the frame returned by get_camera_frame().
	 * \return The width of the frame, in pixels.
	 */
	unsigned short frameHeight();

	/*!
	 * Closes the current camera interface. Does nothing if no camera is open.
	 */
	void close();
	
	
	virtual bool image(cv::Mat *data) const;
private:
	void updateRgb();
	void updateHsv();
	
	int m_id;
	
	CameraPrivate *m_private;
};

#endif
