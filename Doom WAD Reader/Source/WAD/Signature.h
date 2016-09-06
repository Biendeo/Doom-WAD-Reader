#pragma once

#include "Constants.h"
#include "Identification.h"

namespace Biendeo {
	namespace WAD {
		// The signature of the WAD, which contains the main information.
		struct Signature {
			// The type of WAD this is (IWAD or WAD).
			Identification wadType;
			// The number of lumps in this WAD.
			unsigned int numLumps;
			// The location of the directory.
			// TODO: Figure out what this is.
			wadAddress infoTableOfS;

			// Converts this signature into the byte format.
			byte* ToBytes();
		};
	}
}