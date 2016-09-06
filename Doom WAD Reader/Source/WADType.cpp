#include "WADType.h"

namespace Biendeo {
	char* WADTypeToString(WADType type) {
		switch (type) {
			case WADType::IWAD:
				return "IWAD";
			case WADType::PWAD:
				return "PWAD";
			default:
				return nullptr;
		}
	}
}