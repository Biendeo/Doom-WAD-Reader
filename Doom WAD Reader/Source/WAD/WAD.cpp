#include "WAD.h"

#include <fstream>
#include <memory>
#include <string>

namespace Biendeo {
	namespace WAD {
		WAD::WAD(char* wadLocation) {
			// Is it a good thing to load the whole WAD into memory?
			std::unique_ptr<byte[]> wadBinary(ReadFile(wadLocation));

			signature = Signature(wadBinary.get());
			directory = Directory(&wadBinary.get()[signature.infoTableOfS]);
		}

		WAD::~WAD() {

		}

		bool WAD::Write(char* wadLocation) {
			std::fstream wadFile(wadLocation, std::fstream::out);

			wadFile.write((char*)std::unique_ptr<byte[]>(signature.ToBytes()).get(), 12);
			wadFile.write((char*)std::unique_ptr<byte[]>(directory.ToBytes()).get(), 16);

			wadFile.close();

			return true;
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