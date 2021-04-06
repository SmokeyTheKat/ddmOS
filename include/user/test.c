#include <ddcLib/ddcPrint.h>

int test(int argc, char** argv)
{
	ddPrints("args are:\n");
	ddPrints(argv[1]);
	ddPrints("\n");
/*
	for (int i = 0; i < argc; i++)
	{
		ddPrints(argv[i]);
		ddPrints("\n");
	}
*/
	return 0;
}
