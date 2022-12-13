#pragma once

#include <inttypes.h>


struct FunctionTypeNumTag {
	const uint8_t exp;
	const uint8_t sin;
	const uint8_t cos;
	const uint8_t ln;
};

extern struct FunctionTypeNumTag FunctionTypeNum;