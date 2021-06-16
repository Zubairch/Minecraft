
#include "MC.h"

// subject to change

void* __cdecl operator new[](size_t size, const char* name, int flags, unsigned debugFlags, const char* file, int line) {

	return new __int8[size];
}

void* __cdecl operator new[](unsigned __int64 size, unsigned __int64, unsigned __int64, char const*, int, unsigned int, char const*, int) {

		return new __int8[size];
}
