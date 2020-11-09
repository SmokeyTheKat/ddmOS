#include "../include/kernel/tty.h"



struct ddtty make_ddtty(ddIVec2 _pos, ddIVec2 _size, ddIVec2 _ts, uint8t _fgc, uint8t _bgc)
{
	struct ddtty _o;
	_o.cursorPos = make_ddIVec2(0, 0);
	_o.cursorColor = _fgc;
	_o.cursorBGColor = _bgc;
	_o.cursorVisible = true;
	_o.fgColor = _fgc;
	_o.bgColor = _bgc;
	_o.textSize = _ts;
	_o.position = _pos;
	_o.size = _size;
	_o.textBuffer = make(char, _ts.x * _ts.y * 3);
	return _o;
}

void raze_ddtty(struct ddtty* _dt)
{
	raze(_dt->textBuffer);
}


void ddtty_set_color(struct ddtty* _dt, uint8t _fgc, uint8t _bgc)
{
	_dt->cursorColor = _fgc;
	_dt->cursorBGColor = _bgc;
}

void ddtty_draw_cursor(struct ddtty* _dt)
{
	if (_dt->cursorVisible)
		for (int i = 0; i < 5; i++)
			vga_set_pixel((_dt->cursorPos.x*5)+i, (_dt->cursorPos.y*5)+4, _dt->cursorColor);
}
void ddtty_undraw_cursor(struct ddtty* _dt)
{
	if (_dt->cursorVisible)
		for (int i = 0; i < 5; i++)
			vga_set_pixel((_dt->cursorPos.x*5)+i, (_dt->cursorPos.y*5)+4, _dt->cursorBGColor);
}

void ddtty_cursor_move_to(struct ddtty* _dt, int x, int y)
{
	ddtty_undraw_cursor(_dt);
	_dt->cursorPos.x = x;
	_dt->cursorPos.y = y;
	ddtty_draw_cursor(_dt);
}

void ddtty_delete_line(struct ddtty* _dt)
{
	for (int i = 0; i < _dt->textSize.x*3; i++)
		_dt->textBuffer[_dt->cursorPos.y * _dt->textSize.x + i] = 0;
	for (int y = 0; y < 5; y++)
		for (int x = 0; x < _dt->size.x; x++)
			vga_set_pixel(_dt->position.x + x,
					(_dt->cursorPos.y * _dt->size.x) + y,
					_dt->bgColor);
}

void ddtty_write_char(struct ddtty* _dt, char _c)
{
	ddtty_undraw_cursor(_dt);
	if (_c == '\n')
	{
		_dt->cursorPos.x = 0;
		_dt->cursorPos.y++;
	}
	else if (_c == '\b')
	{
		_dt->cursorPos.x--;
		vga_draw_char(g_vgaFont[226], _dt->cursorPos.x * 5, _dt->cursorPos.y * 5, _dt->bgColor);
	}
	else
	{
		vga_draw_char(g_vgaFont[(int)_c], _dt->cursorPos.x * 5, _dt->cursorPos.y * 5, _dt->cursorColor);
		_dt->textBuffer[(_dt->cursorPos.y * _dt->textSize.x*3) + (_dt->cursorPos.x*3) + 0] = _c;
		_dt->textBuffer[(_dt->cursorPos.y * _dt->textSize.x*3) + (_dt->cursorPos.x*3) + 1] = (char)(_dt->cursorColor);
		_dt->textBuffer[(_dt->cursorPos.y * _dt->textSize.x*3) + (_dt->cursorPos.x*3) + 2] = (char)(_dt->cursorBGColor);
		_dt->cursorPos.x++;
		if (_dt->cursorPos.x >= _dt->textSize.x)
		{
			if (_dt->cursorPos.y+1 >= _dt->textSize.y)
			{
				ddtty_pop_top(_dt);
				ddtty_cursor_move_to(_dt, 0, _dt->cursorPos.y);
			}
			else
				ddtty_cursor_move_to(_dt, 0, _dt->cursorPos.y+1);
		}
	}
	ddtty_draw_cursor(_dt);
}
void ddtty_write(struct ddtty* _dt, const char* _cs, sizet _len)
{
	for (sizet i = 0; i < _len; i++)
		ddtty_write_char(_dt, _cs[i]);
}
void ddtty_write_cstring(struct ddtty* _dt, const char* _c)
{
	ddsize _len = 0;
	cstring_get_length((const char*)_c, &_len);
	ddtty_write(_dt, _c, _len);
}


void ddtty_clear(struct ddtty* _dt)
{
	for (int i = 0; i < _dt->size.y; i++)
		for (int j = 0; j < _dt->size.x; j++)
			vga_set_pixel(j, i, _dt->bgColor);
	ddtty_cursor_move_to(_dt, 0, 0);
}

void ddtty_pop_top(struct ddtty* _dt)
{
	char line[_dt->textSize.x*3];
	for (int i = 1; i < _dt->textSize.y; i++)
	{
		for (int j = 0; j < _dt->textSize.x*3; j++)
		{
			line[j] = _dt->textBuffer[(i*_dt->textSize.x*3) + j];
		}
		for (int j = 0; j < _dt->textSize.x*3; j++)
		{
			_dt->textBuffer[((i-1)*_dt->textSize.x*3) + j] = line[j];
		}
	}
	for (int j = 0; j < _dt->textSize.x*3; j++)
	{
		_dt->textBuffer[((_dt->textSize.y-1) * _dt->textSize.x*3) + j] = 0;
	}
}
