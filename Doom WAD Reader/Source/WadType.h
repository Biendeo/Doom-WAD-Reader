#pragma once

namespace Biendeo {
	enum class WADType {
		IWAD,
		PWAD
	};

	// Returns a readable string version of the WAD type.
	char* WADTypeToString(WADType type);
}