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

#include "camera.h"
#include "camera.hpp"

Camera *g_camera = 0;

void camera_cleanup()
{
	if(g_camera) delete g_camera;
	g_camera = 0;
}

int camera_open()
{
	camera_cleanup();
	g_camera = new Camera();
	return g_camera->open() ? 1 : 0;
}

int camera_open_other(int number)
{
	camera_cleanup();
	g_camera = new Camera(number);
	return g_camera->open() ? 1 : 0;
}

int get_camera_number()
{
	return Camera::availableCameras();
}

int camera_update()
{
	if(!g_camera) return 0;
	return g_camera->update() ? 1 : 0;
}

unsigned char *get_camera_frame()
{
	if(!g_camera) return 0;
	return g_camera->frame();
}

int put_camera_frame(unsigned char *data)
{
	if(!g_camera) return 0;
	return g_camera->putFrame(data) ? 1 : 0;
}

int put_camera_frame_scaled(unsigned char *data, int width, int height)
{
	if(!g_camera) return 0;
	return g_camera->putFrame(data, width, height) ? 1 : 0;
}

unsigned char *get_camera_frame_hsv()
{
	if(!g_camera) return 0;
	return g_camera->frameHsv();
}

int put_camera_frame_hsv(unsigned char *data)
{
	if(!g_camera) return 0;
	return g_camera->putFrameHsv(data) ? 1 : 0;
}

int put_camera_frame_hsv_scaled(unsigned char *data, int width, int height)
{
	if(!g_camera) return 0;
	return g_camera->putFrameHsv(data, width, height) ? 1 : 0;
}

unsigned char *get_camera_frame_row(int row)
{
	if(!g_camera || row < 0) return 0;
	return g_camera->frameRow(row);
}

unsigned char *get_camera_frame_pixel(int x, int y)
{
	if(!g_camera || x < 0 || y < 0) return 0;
	return g_camera->framePixel(x, y);
}

int get_camera_frame_size()
{
	if(!g_camera) return 0;
	return g_camera->frameSize();
}

int get_camera_frame_width()
{
	if(!g_camera) return 0;
	return g_camera->frameWidth();
}

int get_camera_frame_height()
{
	if(!g_camera) return 0;
	return g_camera->frameHeight();
}

void camera_close()
{
	camera_cleanup();
}