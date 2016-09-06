#include "Constants.h"

namespace Biendeo {
	namespace WAD {
		unsigned int LittleEndianToInt(byte* arr) {
			return (arr[0] | arr[1] << 8 | arr[2] << 16 | arr[3] << 24);
		}

		byte* IntToLittleEndian(unsigned int number) {
			byte* returnArr = new byte[4];
			returnArr[0] = (byte)number;
			returnArr[1] = (byte)(number >> 8);
			returnArr[2] = (byte)(number >> 16);
			returnArr[3] = (byte)(number >> 24);

			return returnArr;
		}
	}
}