#ifndef __ddVec__
#define __ddVec__

#include "./ddcMath.h"
#include "../ddcDef.h"

typedef struct ddVec2 ddVec2;
typedef struct ddIVec2 ddIVec2;
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


ddIVec2 make_ddIVec2(int _x, int _y);

void    ddIVec2_set(ddIVec2* _d, const ddIVec2 _s);
bool    ddIVec2_compare(const ddIVec2 _d, const ddIVec2 _s);
void    ddIVec2_add(ddIVec2* _d, const ddIVec2 _s);
void    ddIVec2_subtract(ddIVec2* _d, const ddIVec2 _s);
void    ddIVec2_multiply(ddIVec2* _d, const ddIVec2 _s);
void    ddIVec2_divide(ddIVec2* _d, const ddIVec2 _s);
void    ddIVec2_dot(ddIVec2* _d, const ddIVec2 _s);
double  ddIVec2_magnitude(ddIVec2 _d);
ddIVec2  ddIVec2_normalize(ddIVec2 _d);

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

struct ddIVec2
{
	int x;
	int y;
};

struct ddVec3
{
	double x;
	double y;
	double z;
};


#endif
