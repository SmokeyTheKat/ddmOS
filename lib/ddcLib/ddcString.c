#include "../../include/ddcLib/ddcString.h"

void cstring_get_length(const char* _c, ddsize* _l)
{
	for (*_l = 0; _c[*_l] != '\0'; (*_l)++);
}
void cstring_copy(char* _d, const char* _s, ddsize _len)
{
	for (ddsize i = 0; i < _len; i++)
	{
		*_d = *_s;
		_d++;
		_s++;
	}
}
void cstring_copy_offset(char* _d, const char* _s, ddsize _do, ddsize _so, ddsize _l)
{
	_d += _do;
	_s += _so;
	for (ddsize i = 0; i < _l; i++)
	{
		*_d = *_s;
		_d++;
		_s++;
	}
}
bool cstring_compare(const char* _d, const char* _s)
{
	ddsize _dl;
	cstring_get_length(_d, &_dl);
	ddsize _sl;
	cstring_get_length(_s, &_sl);
	if (_sl != _dl)  return false;
	for (ddsize i = 0; i < _dl; i++)
	{
		if (_d[i] != _s[i])  return false;
	}
	return true;
}

void cstring_delete_at(char* _d, ddsize _i,  ddsize _l)
{
	for (ddsize i = _i; i < _l; i++)
	{
		_d[i] = _d[i+1];
	}
}

void cstring_insert_char_at(char* _d, char _c, ddsize _i,  ddsize _l)
{
	for (ddsize i = _l; i > _i; i--)
	{
		_d[i] = _d[i-1];
	}
	_d[_i] = _c;
}

void ddString_copy(ddString* _d, const ddString _s)
{
	cstring_copy_offset(_d->cstr, _s.cstr, 0,0,_d->length);
	if (_d->capacity < _s.length)
		ddString_resize(_d, _s.length + __BYINC);
	cstring_copy(_d->cstr, _s.cstr, _s.length);
	_d->status = DOS_ACTIVE;
}
void ddString_resize(ddString* _d, ddsize _nl)
{
	char* _t = make(char, _nl);
	cstring_copy(_t, _d->cstr, _d->length);

	raze_ddString(_d);

	_d->capacity = _nl;
	_d->cstr = _t;
}

void ddString_add(ddString* _d, const ddString _s)
{
	char* _n = make(char, _d->length + _s.length);
	cstring_copy_offset(_n, _d->cstr, 0, 0, _d->length);
	cstring_copy_offset(_n, _s.cstr, _d->length, 0, _s.length);

	raze_ddString(_d);

	_d->cstr = _n;
	_d->length += _s.length;
	_d->status = DOS_ACTIVE;
}

bool ddString_compare(const ddString _d, const ddString _s)
{
	if (_d.length != _s.length)
		return false;
	for (ddsize i = 0; i < _d.length; i++)
		if (_d.cstr[i] != _s.cstr[i])
			return false;
	return true;
}

bool ddString_compare_cstring(const ddString _d, const char* _s)
{
	ddsize _len;
	cstring_get_length(_s, &_len);
	if (_d.length != _len)
		return false;
	for (ddsize i = 0; i < _d.length; i++)
		if (_d.cstr[i] != _s[i])
			return false;
	return true;
}

void ddString_push_cstring_back(ddString* _d, const char* _ch)
{
	ddsize _clen;
	cstring_get_length(_ch, &_clen);
	if (_d->capacity < _d->length + _clen)
		ddString_resize(_d, _d->length + _clen + __BYINC);
	cstring_copy_offset(_d->cstr, _ch, _d->length, 0, _clen);
	_d->length += _clen;
	_d->status = DOS_ACTIVE;
}
void ddString_push_back(ddString* _d, const ddString _s)
{
	if (_d->capacity < _d->length + _s.length)
		ddString_resize(_d, _d->length + _s.length + __BYINC);
	cstring_copy_offset(_d->cstr, _s.cstr, _d->length, 0, _s.length);
	_d->length += _s.length;
	_d->status = DOS_ACTIVE;
}
void ddString_push_char_back(ddString* _d, const char _c)
{
	if (_d->capacity < _d->length + 1)
		ddString_resize(_d, _d->length + 1 + __BYINC);
	_d->cstr[_d->length] = _c;
	_d->length += 1;
	_d->status = DOS_ACTIVE;
}


void ddString_push_cstring_front(ddString* _d, const char* _ch)
{
	ddsize _clen;
	cstring_get_length(_ch, &_clen);
	if (_d->capacity < _d->length + _clen)
		ddString_resize(_d, _d->length + _clen + __BYINC);
	char* _t = make(char, _d->length + _clen);
	cstring_copy(_t, _ch, _clen);
	cstring_copy_offset(_t, _d->cstr, _clen, 0, _d->length);
	raze_ddString(_d);
	_d->length += _clen;
	_d->cstr = _t;
	_d->status = DOS_ACTIVE;
}
void ddString_push_front(ddString* _d, const ddString _s)
{
	if (_d->capacity < _d->length + _s.length)
		ddString_resize(_d, _d->length + _s.length + __BYINC);
	char* _t = make(char, _d->length + _s.length);
	cstring_copy(_t, _s.cstr, _s.length);
	cstring_copy_offset(_t, _d->cstr, _s.length, 0, _d->length);
	raze_ddString(_d);
	_d->length += _s.length;
	_d->cstr = _t;
	_d->status = DOS_ACTIVE;
}

void ddString_push_char_front(ddString* _d, const char _c)
{
	if (_d->capacity < _d->length + 1)
		ddString_resize(_d, _d->length + 1 + __BYINC);
	char* _t = make(char, _d->length + 1);
	_t[0] = _c;
	cstring_copy_offset(_t, _d->cstr, 1, 0, _d->length);
	raze_ddString(_d);
	_d->length += 1;
	_d->cstr = _t;
	_d->status = DOS_ACTIVE;
}

void ddString_pop_back(ddString* _d, ddsize _n)
{
	for (ddsize i = 1; i < _n+1; i++)
	{
		_d->cstr[_d->length-i] = '\0';
	}
	_d->length -= _n;
}

ddString make_ddString_from_int(int32t _v)
{
	if (_v == 0) return make_ddString("0");
	char sign;
	if (_v < 0) 
	{
		sign = '-';
		_v *= -1;
	}
	ddString _o = make_empty_ddString();
	while (_v)
	{       
		ddsize x = _v % 10;
		_v /= 10; 
		ddString_push_char_front(&_o, (char)('0' + x));
	}
	if (_o.length == 0) remake_ddString(&_o, "0");
	if (sign == '-') ddString_push_char_front(&_o, sign);
	return _o;
}

void ddString_delete_at(ddString* _d, ddsize i)
{
	for (; i < _d->length; i++)
	{
		_d->cstr[i] = _d->cstr[i+1];
	}
	_d->length--;
}

void ddString_insert_char_at(ddString* _d, char _c, ddsize _i)
{
	for (ddsize i = _d->length; i > _i; i--)
	{
		_d->cstr[i] = _d->cstr[i-1];
	}
	_d->cstr[_i] = _c;
	_d->length++;
}

static int32t __floatTdsCount(int32t n, int32t c)
{
    int32t _o = 1;
    while(c-- > 0)
        _o *= n;

    return _o;
}

ddString make_ddString_from_float(float _f)
{
	long long int l1;
	long long int l2;
	long long int i;
	long long int n1;
	long long int pos;
	long long int sign;
	float n2;

	sign = -1;
	if (_f < 0)
	{
		sign = '-';
		_f *= -1;
	}

	n2 = _f;
	n1 = _f;
	l1 = 0;
	l2 = 0;

	while( (n2 - (float)n1) != 0.0 && !((n2 - (float)n1) < 0.0) )
	{
		n2 = _f * (__floatTdsCount(10.0, l2 + 1));
		n1 = n2;
		l2++;
	}

	for (l1 = (_f > 1) ? 0 : 1; _f > 1; l1++)
		_f /= 10;

	pos = l1;
	l1 = l1 + 1 + l2;
	n1 = n2;
	if (sign == '-')
	{
		l1++;
		pos++;
	}
	
	ddString _o =  make_multi_ddString_cstring("0", l1);

	for (i = l1; i >= 0 ; i--)
	{
		if (i == (l1))
			_o.cstr[i] = '\0';
		else if(i == (pos))
			_o.cstr[i] = '.';
		else if(sign == '-' && i == 0)
			_o.cstr[i] = '-';
		else
		{
			_o.cstr[i] = (n1 % 10) + '0';
			n1 /= 10;
		}
	}
	if (_o.cstr[0] == '0' && _o.cstr[_o.length-1] == '.')
	{
		ddString_push_char_front(&_o, '1');
	}
	return _o;
}

void ddString_make_constant(ddString* _ds)
{
	const char* _t = _ds->cstr;
	_ds->cstr = make(char, _ds->capacity);
	cstring_copy(_ds->cstr, _t, _ds->length);
	_ds->type = DDSTRING_DYNAMIC;
}


ddString make_multi_ddString_cstring(const char* _c, ddsize _n)
{
	ddsize _len;
	cstring_get_length(_c, &_len);
	char* _t = make(char, (_len*_n) + __BYINC);
	for (ddsize i = 0; i < _n*_len; i += _len)
		for (ddsize j = 0; j < _len; j++)
			_t[i+j] = _c[j];
	ddString _o;
	_o.capacity = (_len*_n) + __BYINC;
	_o.length = _len*_n;
	_o.cstr = _t;
	_o.status = DOS_ACTIVE;
	_o.aDelete = DOD_MANUAL;
	_o.type = DDSTRING_DYNAMIC;
	return _o;
}

void ddString_empty(ddString* _ds)
{
	raze_ddString(_ds);
	*(_ds) = make_ddString_length("", 0);
}

void remake_ddString(ddString* _ds, const char* _c)
{
	raze_ddString(_ds);
	*_ds = make_ddString(_c);
}
ddString make_constant_ddString(const char* _c)
{
	ddString _o;
	ddsize _len = 0;
	cstring_get_length(_c, &_len);
	_o.length = _len;
	_o.capacity = _len + __BYINC;

	_o.cstr = (char*)_c;
	
	_o.status = DOS_ACTIVE;
	_o.aDelete = DOD_MANUAL;
	_o.type = DDSTRING_CONSTANT;

	return _o;
}

//const ddString make_full_constant_ddString(const char* _c)
//{
//	ddString _o;
//	ddsize _len = 0;
//	cstring_get_length(_c, &_len);
//	_o.length = _len;
//	_o.capacity = _len + __BYINC;
//
//	_o.cstr = (char*)_c;
//	
//	_o.status = DOS_ACTIVE;
//	_o.aDelete = DOD_MANUAL;
//	_o.type = DDSTRING_CONSTANT;
//
//	return _o;
//}

ddString make_ddString_length(const char* _c, ddsize _l)
{
	ddString _o;
	_o.status = DOS_ACTIVE;
	_o.aDelete = DOD_MANUAL;
	_o.type = DDSTRING_DYNAMIC;

	_o.length = _l;
	_o.capacity = _l + __BYINC;

	_o.cstr = make(char, _o.capacity);
	cstring_copy(_o.cstr, _c, _o.length);

	return _o;

}
ddString make_ddString(const char* _c)
{
	ddString _o;
	ddsize _len = 0;
	cstring_get_length(_c, &_len);

	_o.status = DOS_ACTIVE;
	_o.aDelete = DOD_MANUAL;
	_o.type = DDSTRING_DYNAMIC;

	_o.length = _len;
	_o.capacity = _len + __BYINC;

	_o.cstr = make(char, _o.capacity);
	cstring_copy(_o.cstr, _c, _o.length);

	return _o;
}

ddString make_empty_ddString()
{
	ddString _o;

	_o.length = 0;
	_o.capacity = __BYINC;

	_o.status = DOS_INACTIVE;
	_o.aDelete = DOD_MANUAL;
	_o.type = DDSTRING_DYNAMIC;

	_o.cstr = make(char, _o.capacity);

	return _o;
}

ddString make_auto_ddString(const char* _c)
{
	ddString _o = make_ddString(_c);
	_o.aDelete = DOD_AUTO;
	return _o;
}

void raze_ddString(ddString* _d)
{
	if (_d->status != DOS_DELETED && _d->type != DDSTRING_CONSTANT)
	{
		raze(_d->cstr);
	}
	_d->status = DOS_DELETED;
}
void raze_constant_ddString(ddString* ds)
{
	ds->status = DOS_DELETED;
}
void raze_auto_ddString(ddString* _d)
{
	if (_d->aDelete == DOD_AUTO && _d->type != DDSTRING_CONSTANT)
		raze_ddString(_d);
}

int32t ddString_to_int(const ddString _ds)
{
	char* st = _ds.cstr;
	int32t out = 0;
	int32t sign = 1 - ((*st == 45)*2);
	while(*st)
	{
		out = (out*10) + (*st++ - 48);
	}
	return out * sign;
}
