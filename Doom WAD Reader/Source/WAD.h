#pragma once

#include "Constants.h"
#include "WADType.h"

namespace Biendeo {
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
		// The type of WAD this is (IWAD or WAD).
		WADType type;

		// Returns a sub-array with a null terminator at the end. Remember to delete this array
		// when finished using it.
		byte* SubArray(byte* arr, int startPos, int length);

	};
}