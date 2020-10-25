#include <string.h>

void* memmove(void* _d, const void* _s, size_t _l)
{
	unsigned char* dp = (unsigned char*)_d;
	const unsigned char* sp = (const unsigned char*)_d;
	if (dp < sp)
	{
		for (size_t i = 0; i < _l; i++)
			dp[i] = sp[i];
	}
	else
	{
		for (size_t i = _l; i != 0; i--)
			dp[i-1] = sp[i-1];
	}
	return _d;
}

size_t strlen(const char* _c)
{
	size_t _o = 0;
	while (_c[_o]) _o++;
	return _o;
}

int memcmp(const void* _a, const void* _b, size_t _l)
{
	const unsigned char* a = (const unsigned char*)_a;
	const unsigned char* b = (const unsigned char*)_b;
	for (size_t i = 0; i < _l; i++)
	{
		if (a[i] < b[i])
			return -1;
		else if (b[i] < a[i])
			return 1;
	}
	return 0;
}

void* memset(void* _d, int _v, size_t _l)
{
	unsigned char* d = (unsigned char*)_d;
	for (size_t i = 0; i < _l; i++)
	{
		d[i] = (unsigned char)_v;
	}
	return _d;
}

void* memcpy(void* restrict _d, const void* restrict _s, size_t _l)
{
	unsigned char* d = (unsigned char*)_d;
	const unsigned char* s = (const unsigned char*)_s;
	for (size_t i = 0; i < _l; i++)
	{
		d[i] = s[i];
	}
	return _d;
}
