#include <ddcLib/ddcString.h>

ddString make_constant_ddString(char* buf)
{
	ddString output;
	output.cstr = buf;
	output.length = cstring_length(buf);
	output.capacity = output.length;
	return output;
}
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

void ddString_push_char_back(ddString* d, char c)
{
	if (d->length < d->capacity)
	{
		d->cstr[d->length++] = c;
	}
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

int ddString_to_int(const ddString _ds)
{
	char* st = _ds.cstr;
	int out = 0;
	int sign = 1 - ((*st == 45)*2);
	while(*st)
	{
		if (!(*st >= 48 && *st <=57))
		{
			st++;
			continue;
		}
		out = (out*10) + (*st++ - 48);
	}
	return out * sign;
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
bool cstring_compare_length(char* s1, char* s2, long len)
{
	for (long i = 0; i < len; i++)
		if ((s1[i] != s2[i]) ||
		   (s1[i] == 0 && s2[i] != 0) ||
		   (s1[i] != 0 && s2[i] == 0))
			return false;
	return true;
}
