#ifndef _IMAGE_HPP_
#define _IMAGE_HPP_

namespace cv
{
	class Mat;
}

class Image
{
public:
	virtual ~Image();
	virtual bool image(cv::Mat *data) const = 0;
};

#endif
