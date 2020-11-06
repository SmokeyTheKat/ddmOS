#ifndef __ddlib_ddcMath_h__
#define __ddlib_ddcMath_h__

#include "../ddcDef.h"

inline int32t ddMath_pow_int(int16t v, uint16t p)
{
	int32t _o = 1;
	for (uint16t i = 0; i <= p; i++) _o *= v;
	return _o;
}






#endif
