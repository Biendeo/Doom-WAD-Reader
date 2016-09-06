#pragma once

#include <string>

#include "Constants.h"

namespace Biendeo {
	namespace WAD {
		struct Directory {
			// Creates a default directory with 0 properties.
			Directory();
			// Fills out the directory's properties based on a binary array.
			// This array must start at the directory start.
			Directory(byte* wadBinary);
			
			wadAddress offData;
			unsigned int sizeData;
			byte name[8];

			// Converts this directory into byte format.
			byte* ToBytes();
		};
	}
}