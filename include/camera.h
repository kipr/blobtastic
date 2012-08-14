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
 * \file blobtastic.h
 * \author Braden McDorman
 * \copyright KISS Institute for Practical Robotics
 */

#ifndef _CAMERA_H_
#define _CAMERA_H_

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * Opens the default camera. Closes all other cameras.
 */
int camera_open();

/*!
 * Opens a specific camera. Closes all other cameras.
 * \param number the index of the camera to open. -1 opens the default camera.
 *
 * \see camera_open
 */
int camera_open_other(int number);

/*!
 * Gets the number of cameras available system wide. These cameras are identified by a unique integer identifier.
 *
 * For example, if this method returned 2, camera 0 and camera 1 would be available for opening.
 *
 * \see camera_open_other
 */
int get_camera_number();

/*!
 * Grabs a new frame from the currently opened camera.
 * Returns 1 on success, 0 otherwise.
 */
int camera_update();

/*!
 * Get the current frame as a 1 dimensional array.
 * \return Current frame data in RGB format. This pointer is only valid until camera_update() is called again.
 * \see camera_update
 * \see get_camera_frame_size
 */
unsigned char *get_camera_frame();


int put_camera_frame(unsigned char *data);

int put_camera_frame_scaled(unsigned char *data, int width, int height);

/*!
 * Get the current frame as a 1 dimensional array.
 * \return Current frame data in HSV format. This pointer is only valid until camera_update() is called again.
 * \see camera_update
 * \see get_camera_frame
 */
unsigned char *get_camera_frame_hsv();

int put_camera_frame_hsv(unsigned char *data);

int put_camera_frame_hsv_scaled(unsigned char *data, int width, int height);

/*!
 * Gets a pointer to the beginning of the specified row. This is a convenience
 * method that is equivilent to: get_camera_frame()[row * get_camera_frame_width()]
 *
 * \return The pointer to the first byte of the specified row. 0 if row is out of bounds.
 */
unsigned char *get_camera_frame_row(int row);

/*!
 * Gets a pointer to the beginning of the specified pixel. This is a convenience
 * method that is equivilent to: get_camera_frame()[y * get_camera_frame_width() + x]
 *
 * \return The pointer to the first byte of the specified pixel, 0 if x or y are out of bounds.
 */
unsigned char *get_camera_frame_pixel(int x, int y);

/*!
 * Gets the number of pixels returned by get_camera_frame()
 * 
 * \return The number of pixels in the frame.
 * \note The actual size of the array is three times as large as this method returns. This is because each pixel is three bytes.
 * \see get_camera_frame_width()
 * \see get_camera_frame()
 */
int get_camera_frame_size();

/*!
 * Gets the width of the frame returned by get_camera_frame().
 * \return The width of the frame, in pixels.
 */
int get_camera_frame_width();

/*!
 * Gets the height of the frame returned by get_camera_frame().
 * \return The width of the frame, in pixels.
 */
int get_camera_frame_height();

/*!
 * Closes the current camera interface. Does nothing if no camera is open.
 */
void camera_close();

#ifdef __cplusplus
}
#endif

#endif
