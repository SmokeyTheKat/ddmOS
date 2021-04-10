#ifndef __ddcColors__
#define __ddcColors__

#define CFRGB(r,g,b) "\x1b[38;2;" #r ";" #g ";" #b "m"
#define CBRGB(r,g,b) "\x1b[48;2;" #r ";" #g ";" #b "m"

#define CFWHITE "\x1b[38;5;15m"
#define CFBLACK "\x1b[38;5;0m"
#define CFGREEN "\x1b[38;5;2m"

struct color
{
	union
	{
		struct { int r, g, b; };
		struct { int h, s, v; };
	};
};

struct color make_color(int r, int g, int b)
{
	struct color output;
	output.r = r;
	output.g = g;
	output.b = b;
	return output;
}


#endif
