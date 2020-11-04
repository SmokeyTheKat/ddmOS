#ifndef __ddcString__
#define __ddcString__

#include "../ddcDef.h"

typedef struct ddString ddString;

typedef enum ddStringTypes ddStringTypes;
enum ddStringTypes { DDSTRING_DYNAMIC=0, DDSTRING_CONSTANT, DDSTRING_STATIC };


ddString make_ddString(const char* _c);
ddString make_ddString_length(const char* _c, ddsize _l);
ddString make_auto_ddString(const char* _c);
ddString make_constant_ddString(const char* _c);
//const ddString make_full_constant_ddString(const char* _c);
ddString make_empty_ddString();
ddString make_multi_ddString(const ddString _c, ddsize _n);
ddString make_multi_ddString_cstring(const char* _c, ddsize _n);
ddString make_ddString_from_int(int _v);
ddString make_ddString_from_float(float _f);
void remake_ddString(ddString* _ds, const char* _c);
void raze_ddString(ddString* _d);
void raze_auto_ddString(ddString* _d);
void raze_constant_ddString(ddString* _d);
ddString int_to_ddString(int _v, ddString _ds);
ddString float_to_ddString(float _f, ddString _ds);
void ddString_empty(ddString* _ds);
void ddString_make_constant(ddString* _ds);
void ddString_resize(ddString* _d, ddsize _nl);
void ddString_copy(ddString* _d, const ddString _s);
void ddString_copy_cstring(ddString* _d, const char* _s);
void ddString_add(ddString* _d, const ddString _s);
void ddString_add_cstring(ddString* _d, const char* _s);
bool ddString_compare(const ddString _d, const ddString _s);
bool ddString_compare_cstring(const ddString _d, const char* _s);
void ddString_push_back(ddString* _d, const ddString);
void ddString_push_front(ddString* _d, const ddString);
void ddString_push_cstring_back(ddString* _d, const char* _ch);
void ddString_push_cstring_front(ddString* _d, const char* _ch);
void ddString_push_char_back(ddString* _d, const char _c);
void ddString_push_char_front(ddString* _d, const char _c);
int ddString_to_int(const ddString _ds);

void cstring_get_length(const char* _c, ddsize* _l);
void cstring_copy(char* _d, const char* _s, ddsize _len);
void cstring_copy_offset(char* _d, const char* _s, ddsize _do, ddsize _so, ddsize _l);
bool cstring_compare(const char* _d, const char* _s);
void __cstring_copy(char* _d, const char* _s, ddsize _len);
void __cstring_copy_offset(char* _d, const char* _s, ddsize _do, ddsize _so, ddsize _l);
bool __cstring_compare(const char* _d, const char* _s);


struct ddString
{
	char* cstr;
	ddsize length;
	ddsize capacity;
	DOStatus status;
	DODelete aDelete;
	ddStringTypes type;
};







#endif
