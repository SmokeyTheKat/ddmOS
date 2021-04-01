#ifndef __ddclib_ddcString_h__
#define __ddclib_ddcString_h__

long cstring_length(char* data)
{
	long len = 0;
	while (data[len++]);
	return len-1;
}

#endif
