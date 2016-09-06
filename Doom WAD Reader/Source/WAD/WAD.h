#pragma once

#include "Constants.h"
#include "Identification.h"
#include "Signature.h"

namespace Biendeo {
	namespace WAD {
		// The base WAD class, it should contain all the information of a WAD.
		class WAD {
			public:
			// Creates a new WAD from the given WAD path.
			WAD(char* wadLocation);
			// Destroys the WAD object.
			~WAD();

			// Writes this object to a given file location.
			bool Write(char* wadLocation);

			private:
			// The signature of this WAD.
			Signature signature;

			// Returns a sub-array with a null terminator at the end.
			byte* SubArray(byte* arr, int startPos, int length);
			// Reads a file an returns an array of its contents.
			byte* ReadFile(char* fileLocation);
		};
	}
}