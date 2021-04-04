#ifndef __ddclib_ddcString_h__
#define __ddclib_ddcString_h__

#include <ddcLib/ddcDef.h>

typedef struct ddString
{
	char* cstr;
	long length;
	long capacity;
} ddString;

ddString make_constant_ddString(char* buf);
ddString make_ddString_from_buf(char* buf, long cap);
ddString make_ddString_from_buf_from_int(char* buf, long cap, long v);
void ddString_make_int(ddString* d, long v);
void ddString_push_char_back(ddString* d, char c);
void ddString_push_char_front(ddString* d, char c);
int ddString_to_int(const ddString _ds);

long cstring_length(char* data);
bool cstring_compare(char* s1, char* s2);
bool cstring_compare_length(char* s1, char* s2, long len);

#endif
