#include "verbose.h"
#include "build_options.hpp"

#include <cstdarg>
#include <cstdio>
#include <sstream>

#if VERBOSE_ERRORS

void error(const char *format, ...)
{
	static const char *prefix = "Error";
	std::stringstream message;
	message << prefix << ": ";
	message << format;
	
	va_list args;
	va_start(args, format);
	vfprintf(stderr, message.str().c_str(), args);
	va_end(args);
}

#else

void error(const char *format, ...) {}

#endif