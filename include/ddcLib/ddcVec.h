#ifndef __ddVec__
#define __ddVec__

#include "./ddcMath.h"
#include "../ddcDef.h"

typedef struct ddVec2 ddVec2;
typedef struct ddVec3 ddVec3;



ddVec2 make_ddVec2(double _x, double _y);

void    ddVec2_set(ddVec2* _d, const ddVec2 _s);
bool    ddVec2_compare(const ddVec2 _d, const ddVec2 _s);
void    ddVec2_add(ddVec2* _d, const ddVec2 _s);
void    ddVec2_subtract(ddVec2* _d, const ddVec2 _s);
void    ddVec2_multiply(ddVec2* _d, const ddVec2 _s);
void    ddVec2_divide(ddVec2* _d, const ddVec2 _s);
void    ddVec2_dot(ddVec2* _d, const ddVec2 _s);
double  ddVec2_magnitude(ddVec2 _d);
ddVec2  ddVec2_normalize(ddVec2 _d);



ddVec3 make_ddVec3(double _x, double _y, double _z);

void    ddVec3_set(ddVec3* _d, const ddVec3 _s);
void    ddVec3_compare(ddVec3* _d, const ddVec3 _s);
void    ddVec3_add(ddVec3* _d, const ddVec3 _s);
void    ddVec3_subtract(ddVec3* _d, const ddVec3 _s);
void    ddVec3_multiply(ddVec3* _d, const ddVec3 _s);
void    ddVec3_divide(ddVec3* _d, const ddVec3 _s);
void    ddVec3_dot(ddVec3* _d, const ddVec3 _s);
double  ddVec3_magnitude(ddVec3 _d);
ddVec3  ddVec3_normalize(ddVec3 _d);




struct ddVec2
{
	double x;
	double y;
};

struct ddVec3
{
	double x;
	double y;
	double z;
};




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
	return sqrt(pow(_d.x, 2) + pow(_d.y, 2));
}
ddVec2 ddVec2_normalize(ddVec2 _d)
{
	ddVec2 _o;
	double mag = ddVec2_magnitude(_d);
	_o.x = _d.x / mag;
	_o.y = _d.y / mag;
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
	return (double)sqrt(pow(_d.x, 2) + pow(_d.y, 2) + pow(_d.z, 2));
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


#endif
