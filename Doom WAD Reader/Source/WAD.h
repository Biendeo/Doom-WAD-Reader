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
		// The identification of WAD this is (IWAD or WAD).
		WADType identification;
		// The number of lumps in this WAD.
		unsigned int numLumps;
		// The location of the directory.
		// TODO: Figure out what this is.
		wadAddress infoTableOfS;

		// Returns a sub-array with a null terminator at the end.
		byte* SubArray(byte* arr, int startPos, int length);
		// Reads a file an returns an array of its contents.
		byte* ReadFile(char* fileLocation);
		// Converts four bytes of an array into an unsigned integer.
		unsigned int LittleEndianToInt(byte* arr);
		// Converts an integer to an array of bytes.
		byte* IntToLittleEndian(unsigned int number);
	};
}