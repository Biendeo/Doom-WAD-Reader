#pragma once

namespace Biendeo {
	enum class WADType {
		IWAD,
		PWAD
	};

	// Returns a readable string version of the WAD identification.
	char* WADTypeToString(WADType type);
}