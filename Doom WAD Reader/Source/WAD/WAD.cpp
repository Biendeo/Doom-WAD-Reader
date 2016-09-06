#include "WAD.h"

#include <fstream>
#include <memory>
#include <string>

namespace Biendeo {
	namespace WAD {
		WAD::WAD(char* wadLocation) {
			// Is it a good thing to load the whole WAD into memory?
			std::unique_ptr<byte[]> wadBinary(ReadFile(wadLocation));

			std::unique_ptr<byte[]> wadType(SubArray(wadBinary.get(), 0, 4));
			std::string wadTypeStr((char*)wadType.get());

			if (wadTypeStr == "IWAD") {
				signature.wadType = Identification::IWAD;
			} else if (wadTypeStr == "PWAD") {
				signature.wadType = Identification::PWAD;
			} else {
				throw std::exception("WAD identification not detected.");
			}

			std::unique_ptr<byte[]> numLumpsBytes(SubArray(wadBinary.get(), 4, 4));
			signature.numLumps = LittleEndianToInt(numLumpsBytes.get());

			std::unique_ptr<byte[]> infoTableOfSBytes(SubArray(wadBinary.get(), 8, 4));
			signature.infoTableOfS = (wadAddress)LittleEndianToInt(infoTableOfSBytes.get());
		}

		WAD::~WAD() {

		}

		bool WAD::Write(char* wadLocation) {
			std::fstream wadFile(wadLocation, std::fstream::out);

			wadFile.write((char*)std::unique_ptr<byte[]>(signature.ToBytes()).get(), 12);

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

	}
}