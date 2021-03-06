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

#include "rec709_linearised_gamma_lut.h"

using namespace libdcp;

LUTCache<Rec709LinearisedGammaLUT> Rec709LinearisedGammaLUT::cache;

Rec709LinearisedGammaLUT::Rec709LinearisedGammaLUT (int bits, float gamma)
	: LUT (bits, gamma)
{
	int const bit_length = pow (2, bits);
	for (int i = 0; i < bit_length; ++i) {
		float const p = static_cast<float> (i) / (bit_length - 1);
		if (p > 0.08125) {
			_lut[i] = pow ((p + 0.099) / 1.099, gamma);
		} else {
			_lut[i] = p / 4.5;
		}
	}
}
