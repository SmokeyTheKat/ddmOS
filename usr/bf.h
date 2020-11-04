#include "../include/kernel/tty.h"


static void err(const char* msg)
{
	term_write_cstring(msg);
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
	for (int i = 3; i < l; i++)
	{
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
				term_write_char((char)(p[po]));
				break;
			}
			case '?':
			{
				int_to_cstring(p[po], ch, 8);
				term_write_cstring(ch);
				break;
			}
			case 'P':
			{
				term_write_char((char)(p[po]+48));
				break;
			}
		}
	}
	return 0;
}
