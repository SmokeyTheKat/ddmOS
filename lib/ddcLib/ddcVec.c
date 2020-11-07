#include "../../include/ddcLib/ddcVec.h"


ddVec2 make_ddVec2(double _x, double _y)
{
	ddVec2 _o;
	_o.x = _x;
	_o.y = _y;
	return _o;
}


bool ddVec2_compare(const ddVec2 _d, const ddVec2 _s)
{
	return ((_d.x == _s.x) && (_d.y == _s.y));
}
void ddVec2_set(ddVec2* _d, const ddVec2 _s)
{
	_d->x = _s.x;
	_d->y = _s.y;
}


void ddVec2_add(ddVec2* _d, const ddVec2 _s)
{
	_d->x += _s.x;
	_d->y += _s.y;
}
void ddVec2_subtract(ddVec2* _d, const ddVec2 _s)
{
	_d->x -= _s.x;
	_d->y -= _s.y;
}
void ddVec2_multiply(ddVec2* _d, const ddVec2 _s)
{
	_d->x *= _s.x;
	_d->y *= _s.y;
}
void ddVec2_divide(ddVec2* _d, const ddVec2 _s)
{
	_d->x /= _s.x;
	_d->y /= _s.y;
}
void ddVec2_dot(ddVec2* _d, const ddVec2 _s)
{
	_d->x *= _s.x;
	_d->y *= _s.y;
}
double ddVec2_magnitude(ddVec2 _d)
{
	return ddMath_sqrt((_d.x*_d.x) + (_d.y*_d.y));
}
ddVec2 ddVec2_normalize(ddVec2 _d)
{
	ddVec2 _o;
	double mag = ddVec2_magnitude(_d);
	_o.x = _d.x / mag;
	_o.y = _d.y / mag;
	return _o;
}




ddIVec2 make_ddIVec2(int _x, int _y)
{
	ddIVec2 _o;
	_o.x = _x;
	_o.y = _y;
	return _o;
}


bool ddIVec2_compare(const ddIVec2 _d, const ddIVec2 _s)
{
	return ((_d.x == _s.x) && (_d.y == _s.y));
}
void ddIVec2_set(ddIVec2* _d, const ddIVec2 _s)
{
	_d->x = _s.x;
	_d->y = _s.y;
}


void ddIVec2_add(ddIVec2* _d, const ddIVec2 _s)
{
	_d->x += _s.x;
	_d->y += _s.y;
}
void ddIVec2_subtract(ddIVec2* _d, const ddIVec2 _s)
{
	_d->x -= _s.x;
	_d->y -= _s.y;
}
void ddIVec2_multiply(ddIVec2* _d, const ddIVec2 _s)
{
	_d->x *= _s.x;
	_d->y *= _s.y;
}
void ddIVec2_divide(ddIVec2* _d, const ddIVec2 _s)
{
	_d->x = (int)((double)_d->x / (double)_s.x);
	_d->y = (int)((double)_d->x / (double)_s.y);
}
void ddIVec2_dot(ddIVec2* _d, const ddIVec2 _s)
{
	_d->x *= _s.x;
	_d->y *= _s.y;
}
double ddIVec2_magnitude(ddIVec2 _d)
{
	return ddMath_sqrt((_d.x*_d.x) + (_d.y*_d.y));
}
ddIVec2 ddIVec2_normalize(ddIVec2 _d)
{
	ddIVec2 _o;
	double mag = ddIVec2_magnitude(_d);
	_o.x = (int)((double)_d.x / mag);
	_o.y = (int)((double)_d.y / mag);
	return _o;
}
























ddVec3 make_ddVec3(double _x, double _y, double _z)
{
	ddVec3 _o;
	_o.x = _x;
	_o.y = _y;
	_o.z = _z;
	return _o;
}


void ddVec3_add(ddVec3* _d, const ddVec3 _s)
{
	_d->x += _s.x;
	_d->y += _s.y;
	_d->z += _s.z;
}
void ddVec3_subtract(ddVec3* _d, const ddVec3 _s)
{
	_d->x -= _s.x;
	_d->y -= _s.y;
	_d->z -= _s.z;
}
void ddVec3_multiply(ddVec3* _d, const ddVec3 _s)
{
	_d->x *= _s.x;
	_d->y *= _s.y;
	_d->z *= _s.z;
}
void ddVec3_divide(ddVec3* _d, const ddVec3 _s)
{
	_d->x /= _s.x;
	_d->y /= _s.y;
	_d->z /= _s.z;
}
void ddVec3_dot(ddVec3* _d, const ddVec3 _s)
{
	_d->x *= _s.x;
	_d->y *= _s.y;
	_d->z *= _s.z;
}
double ddVec3_magnitude(ddVec3 _d)
{
	return ddMath_sqrt((_d.x*_d.x) + (_d.y*_d.y) + (_d.z*_d.z));
}
ddVec3 ddVec3_normalize(ddVec3 _d)
{
	ddVec3 _o;
	double mag = ddVec3_magnitude(_d);
	_o.x = _d.x / mag;
	_o.y = _d.y / mag;
	_o.z = _d.z / mag;
	return _o;
}

