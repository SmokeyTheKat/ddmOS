#include "../../include/kernel/kernel.h"
#include "../../include/kernel/drivers/tty.h"


static void err(const char* msg)
{
	ddtty_write_cstring(&g_selectedTerm, msg);
}

static int str_len(const char* _c)
{
	int _o = 0;
	for (; _c[_o] != '\0'; _o++);
	return _o;
}

static void int_to_cstring(int v, char* o, int len)
{
	if (v == 0)
	{
		o[0] = '0';
		o[1] = '\0';
		return;
	}
	char sg = '+';
	if (v < 0)
	{
		sg = '-';
		v *= -1;
	}
	for (int i = 0; i < len; i++)
		o[i] = '0';
	o[len-1] = '\0';
	int pos = len-2;
	while (v)
	{
		int x = v % 10;
		v /= 10;
		o[pos] = '0' + x;
		pos--;
	}
	o[pos] = sg;
}

#define MSIZE 100

int bf_compute(const char* v)
{
	int l = str_len(v);
	int p[500] = {0};
	char ch[8];
	int po = 0;
	int ifp = -1;
	bool skg = false;
	for (int i = 3; i < l; i++)
	{
		if (skg && v[i] != ']') continue;
		else if (skg && v[i] == ']') { skg = false; continue; };
		switch (v[i])
		{
			case '>':
			{
				if (po >= MSIZE) err("OUT OF BOUNDS");
				po++;
				break;
			}

			case '[':
			{
				ifp = i;
				if (p[po] == 0) skg = true;
				break;
			}
			case ']':
			{
				i = ifp - 1;
				continue;
				break;
			}


			case '<':
			{
				if (po == 0) err("OUT OF BOUNDS");
				po--;
				break;
			}

			case '+':
			{
				p[po]++;
				break;
			}

			case '-':
			{
				p[po]--;
				break;
			}

			case '.':
			{
				ddtty_write_char(&g_selectedTerm, (char)(p[po]));
				break;
			}
			case '?':
			{
				int_to_cstring(p[po], ch, 8);
				ddtty_write_cstring(&g_selectedTerm, ch);
				ddtty_write_char(&g_selectedTerm, '\n');
				break;
			}
			case 'T':
			{
				p[po] *= 10;
				break;
			}
			case 'A':
			{
				p[po] = 65;
				break;
			}
			default:
			{
				ddtty_set_color(&g_selectedTerm, 15, 0);
				ddtty_write_cstring(&g_selectedTerm, "BF: ");
				ddtty_set_color(&g_selectedTerm, 4, 0);
				ddtty_write_cstring(&g_selectedTerm, "SYNTAX ERROR:\n");
				ddtty_set_color(&g_selectedTerm, 15, 0);
				ddtty_write_cstring(&g_selectedTerm, "    UNIDENTIFIED CHARACTER \"");
				ddtty_write_char(&g_selectedTerm, v[i]);
				ddtty_write_char(&g_selectedTerm, '"');
				return 1;
			}
		}
	}
	return 0;
}
