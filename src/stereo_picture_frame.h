/*
    Copyright (C) 2012-2013 Carl Hetherington <cth@carlh.net>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

*/

#include <string>
#include <stdint.h>
#include <boost/shared_ptr.hpp>
#include "types.h"

namespace ASDCP {
	namespace JP2K {
		struct SFrameBuffer;
	}
	class AESDecContext;
}

namespace libdcp {

class ARGBFrame;

/** A single frame of a 3D (stereoscopic) picture asset */	
class StereoPictureFrame
{
public:
	StereoPictureFrame (boost::filesystem::path mxf_path, int n);
	~StereoPictureFrame ();

	boost::shared_ptr<ARGBFrame> argb_frame (Eye eye, int reduce = 0, float srgb_gamma = 2.4) const;
	uint8_t const * left_j2k_data () const;
	int left_j2k_size () const;
	uint8_t const * right_j2k_data () const;
	int right_j2k_size () const;

private:
	ASDCP::JP2K::SFrameBuffer* _buffer;
};

}
