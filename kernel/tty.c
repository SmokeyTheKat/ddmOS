#include "../include/kernel/tty.h"

struct ddtty make_ddtty(ddIVec2 topLeftPos, ddIVec2 size, ddIVec2 textSize, uint8t foregroundColor, uint8t backgroundColor)
{
	struct ddtty output;
	output.cursorPos = make_ddIVec2(0, 0);
	output.cursorColor = foregroundColor;
	output.cursorBGColor = backgroundColor;
	output.cursorVisible = true;
	output.fgColor = foregroundColor;
	output.bgColor = backgroundColor;
	output.textSize = textSize;
	output.position = topLeftPos;
	output.size = size;
	output.textBuffer = make(char, textSize.x * textSize.y * 3);

	ddtty_clear(&output);

	return output;
}

void raze_ddtty(struct ddtty* _dt)
{
	raze(_dt->textBuffer);
}


void ddtty_set_color(struct ddtty* _dt, uint8t foregroundColor, uint8t backgroundColor)
{
	_dt->cursorColor = foregroundColor;
	_dt->cursorBGColor = backgroundColor;
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
	if (x >= _dt->textSize.x)
	{
		if (_dt->cursorPos.y+1 >= _dt->textSize.y)
		{
			_dt->cursorPos.x = 0;
			//ddtty_pop_top(_dt);
		}
		else
		{
			_dt->cursorPos.x = 0;
			_dt->cursorPos.y++;
		}
	}
	else if (x < 0)
	{
		_dt->cursorPos.x = _dt->textSize.x-1;
		_dt->cursorPos.y--;
	}
	else
	{
		_dt->cursorPos.x = x;
		_dt->cursorPos.y = y;
		
	}
	ddtty_draw_cursor(_dt);
}

void ddtty_cursor_move(struct ddtty* _dt, int x, int y)
{
	ddtty_cursor_move_to(_dt, _dt->cursorPos.x+x, _dt->cursorPos.y+y);
}

void ddtty_delete_line(struct ddtty* _dt)
{
	for (int i = 0; i < _dt->textSize.x*3; i++)
		_dt->textBuffer[_dt->cursorPos.y * _dt->textSize.x + i] = 0;
	for (int y = 0; y < 5; y++)
		for (int x = 0; x < _dt->size.x; x++)
			vga_set_pixel(_dt->position.x + x,
					_dt->position.y + (_dt->cursorPos.y * 5) + y,
					_dt->bgColor);
}

void ddtty_write_char(struct ddtty* _dt, char _c)
{
	ddtty_undraw_cursor(_dt);
	if (_c == '\n')
	{
		ddtty_cursor_move_to(_dt, 0, _dt->cursorPos.y+1);
	}
	else if (_c == '\b')
	{
		ddtty_cursor_move_to(_dt, _dt->cursorPos.x-1, _dt->cursorPos.y);
		vga_draw_char(g_vgaFont[(int)(' ')], _dt->cursorPos.x * 5, _dt->cursorPos.y * 5, _dt->fgColor, _dt->bgColor);
	}
	else
	{
		vga_draw_char(g_vgaFont[(int)(_c)], _dt->cursorPos.x * 5, _dt->cursorPos.y * 5, _dt->cursorColor, _dt->cursorBGColor);
		_dt->textBuffer[(_dt->cursorPos.y * _dt->textSize.x*3) + (_dt->cursorPos.x*3) + 0] = _c;
		_dt->textBuffer[(_dt->cursorPos.y * _dt->textSize.x*3) + (_dt->cursorPos.x*3) + 1] = (char)(_dt->cursorColor);
		_dt->textBuffer[(_dt->cursorPos.y * _dt->textSize.x*3) + (_dt->cursorPos.x*3) + 2] = (char)(_dt->cursorBGColor);
		ddtty_cursor_move_to(_dt, _dt->cursorPos.x+1, _dt->cursorPos.y);
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
	for (int y = 0; y < _dt->textSize.y; y++)
		for (int x = 0; x < _dt->textSize.x * 3; x++)
			_dt->textBuffer[(y*_dt->textSize.x*3)+x] = 0;
	for (int i = 0; i < _dt->size.y; i++)
		for (int j = 0; j < _dt->size.x; j++)
			vga_set_pixel(j, i, _dt->bgColor);
	ddtty_cursor_move_to(_dt, 0, 0);
}

void ddtty_pop_top(struct ddtty* _dt)
{
	for (int y = 0; y < _dt->textSize.y-1; y++)
	{
		ddMem_copy_offset(_dt->textBuffer, _dt->textBuffer,
					(y*_dt->textSize.x*3), 
					(y*_dt->textSize.x*3)+(_dt->textSize.x*3),
					_dt->textSize.x*3);
	}
	ddtty_redraw(_dt);
}
void ddtty_redraw(struct ddtty* _dt)
{
	for (int y = 0; y < _dt->textSize.y-1; y++)
	{
		ddtty_redraw_line(_dt, y);
	}
}
void ddtty_redraw_line(struct ddtty* _dt, uint16t line)
{
	ddIVec2 popPos = _dt->cursorPos;
	uint8t popFGColor = _dt->cursorColor;
	uint8t popBGColor = _dt->cursorBGColor;
	_dt->cursorPos.x = 0;
	_dt->cursorPos.y = line;
	for (int x = 0; x < _dt->textSize.x * 3; x+=3)
	{
		ddtty_set_color(_dt, (uint8t)(_dt->textBuffer[(line * _dt->textSize.x * 3) + x + 1]),
					(uint8t)(_dt->textBuffer[(line * _dt->textSize.x * 3) + x + 2]));
		ddtty_write_char(_dt, _dt->textBuffer[(line * _dt->textSize.x * 3) + x]);
	}
	_dt->cursorPos = popPos;
	ddtty_set_color(_dt, popFGColor, popBGColor);
}
