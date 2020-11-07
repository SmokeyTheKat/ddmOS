#include "../../include/kernel/kernel.h"
#include "../../include/kernel/tty.h"


static void err(const char* msg)
{
	ddtty_write_cstring(&g_mainTerm, msg);
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
			case 'A':
			{
				p[po] = 'A';
				break;
			}
			case '>':
			{
				if (po >= MSIZE) err("OUT OF BOUNDS");
				po++;
				break;
			}
			case 'R':
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
			case 'L':
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
			case 'I':
			{
				p[po]++;
				break;
			}


			case '-':
			{
				p[po]--;
				break;
			}
			case 'D':
			{
				p[po]--;
				break;
			}


			case '.':
			{
				ddtty_write_char(&g_mainTerm, (char)(p[po]));
				break;
			}
			case '?':
			{
				int_to_cstring(p[po], ch, 8);
				ddtty_write_cstring(&g_mainTerm, ch);
				ddtty_write_char(&g_mainTerm, '\n');
				break;
			}
			case 'P':
			{
				ddtty_write_char(&g_mainTerm, (char)(p[po]+48));
				break;
			}
			case 'T':
			{
				p[po] *= 10;
				break;
			}
		}
	}
	return 0;
}
