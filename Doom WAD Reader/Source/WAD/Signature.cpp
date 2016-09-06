#include "Signature.h"

#include <memory>

namespace Biendeo {
	namespace WAD {
		byte* Signature::ToBytes() {
			// This creates a new array for the content. It is always 12 bytes long.
			byte* arr = new byte[12];

			memcpy(&arr[0], IdentificationToString(wadType), 4);
			memcpy(&arr[4], std::unique_ptr<byte[]>(IntToLittleEndian(numLumps)).get(), 4);
			memcpy(&arr[8], std::unique_ptr<byte[]>(IntToLittleEndian(infoTableOfS)).get(), 4);

			return arr;
		}
	}
}
