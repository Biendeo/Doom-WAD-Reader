#include "WAD.h"

#include <fstream>
#include <memory>
#include <string>

namespace Biendeo {
	WAD::WAD(char* wadLocation) {
		// Is it a good thing to load the whole WAD into memory?
		std::unique_ptr<byte[]> wadBinary(ReadFile(wadLocation));

		std::unique_ptr<byte[]> wadType(SubArray(wadBinary.get(), 0, 4));
		std::string wadTypeStr((char*)wadType.get());

		if (wadTypeStr == "IWAD") {
			identification = WADType::IWAD;
		} else if (wadTypeStr == "PWAD") {
			identification = WADType::PWAD;
		} else {
			throw std::exception("WAD identification not detected.");
		}

		std::unique_ptr<byte[]> numLumpsBytes(SubArray(wadBinary.get(), 4, 4));
		numLumps = LittleEndianToInt(numLumpsBytes.get());

		std::unique_ptr<byte[]> infoTableOfSBytes(SubArray(wadBinary.get(), 8, 4));
		infoTableOfS = (wadAddress)LittleEndianToInt(infoTableOfSBytes.get());
	}

	WAD::~WAD() {

	}

	bool WAD::Write(char* wadLocation) {
		std::fstream wadFile(wadLocation, std::fstream::out);

		// The first part of a WAD is the identification in ASCII. This is always 4 bytes.
		wadFile.write(WADTypeToString(identification), 4);
		wadFile.write((char*)std::unique_ptr<byte[]>(IntToLittleEndian(numLumps)).get(), 4);
		wadFile.write((char*)std::unique_ptr<byte[]>(IntToLittleEndian((unsigned int)infoTableOfS)).get(), 4);

		wadFile.close();

		return true;
	}

	byte* WAD::SubArray(byte* arr, int startPos, int length) {
		byte* returnArr = new byte[length + 1];
		memcpy(returnArr, &arr[startPos], length);
		returnArr[length] = '\0';
		return returnArr;
	}

	byte* WAD::ReadFile(char* fileLocation) {
		std::fstream wadFile(fileLocation, std::fstream::binary | std::fstream::in | std::fstream::ate);
		wadFile.seekg(0, std::fstream::end);
		int wadSize = static_cast<int>(wadFile.tellg());

		byte* wadBinary = new byte[wadSize];

		wadFile.seekg(0, std::fstream::beg);
		wadFile.read((char*)wadBinary, wadSize);
		wadFile.close();

		return wadBinary;
	}

	unsigned int WAD::LittleEndianToInt(byte* arr) {
		return (arr[0] | arr[1] << 8 | arr[2] << 16 | arr[3] << 24);
	}

	byte* WAD::IntToLittleEndian(unsigned int number) {
		byte* returnArr = new byte[4];
		returnArr[0] = (byte)number;
		returnArr[1] = (byte)(number >> 8);
		returnArr[2] = (byte)(number >> 16);
		returnArr[3] = (byte)(number >> 24);

		return returnArr;
	}
}