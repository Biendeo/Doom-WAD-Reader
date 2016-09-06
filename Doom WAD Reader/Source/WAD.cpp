#include "WAD.h"

#include <fstream>
#include <string>

namespace Biendeo {
	WAD::WAD(char* wadLocation) {
		std::fstream wadFile(wadLocation, std::fstream::binary | std::fstream::in | std::fstream::ate);
		wadFile.seekg(0, std::fstream::end);
		int wadSize = static_cast<int>(wadFile.tellg());

		byte* wadBinary = new byte[wadSize];

		wadFile.seekg(0, std::fstream::beg);
		wadFile.read(wadBinary, wadSize);
		wadFile.close();

		byte* wadType = SubArray(wadBinary, 0, 4);
		std::string wadTypeStr(wadType);
		delete[] wadType;

		if (wadTypeStr == "IWAD") {
			type = WADType::IWAD;
		} else if (wadTypeStr == "PWAD") {
			type = WADType::PWAD;
		} else {
			throw std::exception("WAD type not detected.");
		}

		delete[] wadBinary;
	}

	WAD::~WAD() {

	}

	bool WAD::Write(char* wadLocation) {
		std::fstream wadFile(wadLocation, std::fstream::out);

		// The first part of a WAD is the type in ASCII. This is always 4 bytes.
		wadFile.write(WADTypeToString(type), 4);

		wadFile.close();

		return true;
	}

	byte* WAD::SubArray(byte* arr, int startPos, int length) {
		byte* returnArr = new char[length + 1];
		memcpy(returnArr, &arr[startPos], length);
		returnArr[length] = '\0';
		return returnArr;
	}
}