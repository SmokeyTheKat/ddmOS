#include "../../include/ddcLib/ddcMath.h"



int32t ddMath_pow_int(int16t v, uint16t p)
{
	int32t _o = 1;
	for (uint16t i = 0; i <= p; i++) _o *= v;
	return _o;
}

double ddMath_sqrt(int16t _v)
{
	double t;
	double s;
	s = _v / 2;
	t = 0;
	while(s != t)
	{
		t = s;
		s = (_v / t + t) / 2;
	}
	return s;
}



