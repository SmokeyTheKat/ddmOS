#include <ddcLib/ddcString.h>

ddString make_ddString_from_buf(char* buf, long cap)
{
	ddString output;
	output.cstr = buf;
	output.length = 0;
	output.capacity = cap;
	return output;
}
ddString make_ddString_from_buf_from_int(char* buf, long cap, long v)
{
	ddString output = make_ddString_from_buf(buf, cap);
	ddString_make_int(&output, v);
	return output;
}

void ddString_push_char_front(ddString* d, char c)
{
	if (d->length < d->capacity)
	{
		for (int i = d->length; i >= 1; i--)
			d->cstr[i] = d->cstr[i-1];
		d->cstr[0] = c;
		d->length++;
		d->cstr[d->length] = 0;
	}
}

void ddString_make_int(ddString* d, long v)
{
	d->length = 0;
	while (v)
	{
		long x = v % 10;
		v /= 10;
		ddString_push_char_front(d, (char)(x + '0'));
	}
}

long cstring_length(char* data)
{
	long len = 0;
	while (data[len++]);
	return len-1;
}
bool cstring_compare(char* s1, char* s2)
{
	while (*s1 && *s2)
	{
		if (*(s1++) != *(s2++)) return false;
	}
	if (*s1 != *s2) return false;
	return true;
}
