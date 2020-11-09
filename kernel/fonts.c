#include "../include/kernel/fonts.h"

byte g_vgaFont[255][4];

void init_fonts(void)
{
	g_vgaFont[65][0] = 2;
	g_vgaFont[65][1] = 5;
	g_vgaFont[65][2] = 7;
	g_vgaFont[65][3] = 5;

	g_vgaFont[66][0] = 3;
	g_vgaFont[66][1] = 7;
	g_vgaFont[66][2] = 5;
	g_vgaFont[66][3] = 3;

	g_vgaFont[67][0] = 6;
	g_vgaFont[67][1] = 1;
	g_vgaFont[67][2] = 1;
	g_vgaFont[67][3] = 6;

	g_vgaFont[68][0] = 3;
	g_vgaFont[68][1] = 5;
	g_vgaFont[68][2] = 5;
	g_vgaFont[68][3] = 3;

	g_vgaFont[69][0] = 7;
	g_vgaFont[69][1] = 3;
	g_vgaFont[69][2] = 1;
	g_vgaFont[69][3] = 7;

	g_vgaFont[70][0] = 7;
	g_vgaFont[70][1] = 1;
	g_vgaFont[70][2] = 3;
	g_vgaFont[70][3] = 1;

	g_vgaFont[71][0] = 6;
	g_vgaFont[71][1] = 1;
	g_vgaFont[71][2] = 13;
	g_vgaFont[71][3] = 6;

	g_vgaFont[72][0] = 5;
	g_vgaFont[72][1] = 7;
	g_vgaFont[72][2] = 5;
	g_vgaFont[72][3] = 5;

	g_vgaFont[73][0] = 7;
	g_vgaFont[73][1] = 2;
	g_vgaFont[73][2] = 2;
	g_vgaFont[73][3] = 7;

	g_vgaFont[74][0] = 7;
	g_vgaFont[74][1] = 2;
	g_vgaFont[74][2] = 2;
	g_vgaFont[74][3] = 3;

	g_vgaFont[75][0] = 5;
	g_vgaFont[75][1] = 3;
	g_vgaFont[75][2] = 5;
	g_vgaFont[75][3] = 5;

	g_vgaFont[76][0] = 1;
	g_vgaFont[76][1] = 1;
	g_vgaFont[76][2] = 1;
	g_vgaFont[76][3] = 7;

	g_vgaFont[77][0] = 6;
	g_vgaFont[77][1] = 15;
	g_vgaFont[77][2] = 9;
	g_vgaFont[77][3] = 9;

	g_vgaFont[78][0] = 9;
	g_vgaFont[78][1] = 11;
	g_vgaFont[78][2] = 13;
	g_vgaFont[78][3] = 9;

	g_vgaFont[79][0] = 6;
	g_vgaFont[79][1] = 9;
	g_vgaFont[79][2] = 9;
	g_vgaFont[79][3] = 6;

	g_vgaFont[80][0] = 3;
	g_vgaFont[80][1] = 5;
	g_vgaFont[80][2] = 3;
	g_vgaFont[80][3] = 1;

	g_vgaFont[81][0] = 6;
	g_vgaFont[81][1] = 9;
	g_vgaFont[81][2] = 5;
	g_vgaFont[81][3] = 10;

	g_vgaFont[82][0] = 3;
	g_vgaFont[82][1] = 5;
	g_vgaFont[82][2] = 3;
	g_vgaFont[82][3] = 5;

	g_vgaFont[83][0] = 3;
	g_vgaFont[83][1] = 1;
	g_vgaFont[83][2] = 2;
	g_vgaFont[83][3] = 3;

	g_vgaFont[84][0] = 7;
	g_vgaFont[84][1] = 2;
	g_vgaFont[84][2] = 2;
	g_vgaFont[84][3] = 2;

	g_vgaFont[85][0] = 5;
	g_vgaFont[85][1] = 5;
	g_vgaFont[85][2] = 5;
	g_vgaFont[85][3] = 6;

	g_vgaFont[86][0] = 5;
	g_vgaFont[86][1] = 5;
	g_vgaFont[86][2] = 5;
	g_vgaFont[86][3] = 2;

	g_vgaFont[87][0] = 9;
	g_vgaFont[87][1] = 9;
	g_vgaFont[87][2] = 11;
	g_vgaFont[87][3] = 13;

	g_vgaFont[88][0] = 5;
	g_vgaFont[88][1] = 2;
	g_vgaFont[88][2] = 2;
	g_vgaFont[88][3] = 5;

	g_vgaFont[89][0] = 5;
	g_vgaFont[89][1] = 5;
	g_vgaFont[89][2] = 2;
	g_vgaFont[89][3] = 2;

	g_vgaFont[90][0] = 3;
	g_vgaFont[90][1] = 2;
	g_vgaFont[90][2] = 1;
	g_vgaFont[90][3] = 3;





//lower

	g_vgaFont[97][0] = 0;
	g_vgaFont[97][1] = 6;
	g_vgaFont[97][2] = 5;
	g_vgaFont[97][3] = 6;

	g_vgaFont[98][0] = 1;
	g_vgaFont[98][1] = 3;
	g_vgaFont[98][2] = 5;
	g_vgaFont[98][3] = 3;

	g_vgaFont[99][0] = 0;
	g_vgaFont[99][1] = 2;
	g_vgaFont[99][2] = 1;
	g_vgaFont[99][3] = 3;

	g_vgaFont[100][0] = 4;
	g_vgaFont[100][1] = 6;
	g_vgaFont[100][2] = 5;
	g_vgaFont[100][3] = 6;

	g_vgaFont[101][0] = 0;
	g_vgaFont[101][1] = 6;
	g_vgaFont[101][2] = 3;
	g_vgaFont[101][3] = 6;

	g_vgaFont[102][0] = 6;
	g_vgaFont[102][1] = 2;
	g_vgaFont[102][2] = 7;
	g_vgaFont[103][3] = 2;

	g_vgaFont[103][0] = 2;
	g_vgaFont[103][1] = 7;
	g_vgaFont[103][2] = 4;
	g_vgaFont[103][3] = 6;

	g_vgaFont[104][0] = 1;
	g_vgaFont[104][1] = 1;
	g_vgaFont[104][2] = 7;
	g_vgaFont[104][3] = 5;

	g_vgaFont[105][0] = 2;
	g_vgaFont[105][1] = 0;
	g_vgaFont[105][2] = 2;
	g_vgaFont[105][3] = 2;

	g_vgaFont[106][0] = 2;
	g_vgaFont[106][1] = 0;
	g_vgaFont[106][2] = 2;
	g_vgaFont[106][3] = 3;

	g_vgaFont[107][0] = 0;
	g_vgaFont[107][1] = 5;
	g_vgaFont[107][2] = 3;
	g_vgaFont[107][3] = 5;

	g_vgaFont[108][0] = 2;
	g_vgaFont[108][1] = 2;
	g_vgaFont[108][2] = 2;
	g_vgaFont[108][3] = 2;

	g_vgaFont[109][0] = 0;
	g_vgaFont[109][1] = 0;
	g_vgaFont[109][2] = 15;
	g_vgaFont[109][3] = 13;

	g_vgaFont[110][0] = 0;
	g_vgaFont[110][1] = 3;
	g_vgaFont[110][2] = 5;
	g_vgaFont[110][3] = 5;

	g_vgaFont[111][0] = 0;
	g_vgaFont[111][1] = 6;
	g_vgaFont[111][2] = 5;
	g_vgaFont[111][3] = 3;

	g_vgaFont[112][0] = 2;
	g_vgaFont[112][1] = 5;
	g_vgaFont[112][2] = 3;
	g_vgaFont[112][3] = 1;

	g_vgaFont[113][0] = 2;
	g_vgaFont[113][1] = 5;
	g_vgaFont[113][2] = 6;
	g_vgaFont[113][3] = 12;

	g_vgaFont[114][0] = 0;
	g_vgaFont[114][1] = 6;
	g_vgaFont[114][2] = 2;
	g_vgaFont[114][3] = 2;

	g_vgaFont[115][0] = 2;
	g_vgaFont[115][1] = 1;
	g_vgaFont[115][2] = 2;
	g_vgaFont[115][3] = 3;

	g_vgaFont[116][0] = 2;
	g_vgaFont[116][1] = 7;
	g_vgaFont[116][2] = 2;
	g_vgaFont[116][3] = 2;

	g_vgaFont[117][0] = 0;
	g_vgaFont[117][1] = 5;
	g_vgaFont[117][2] = 5;
	g_vgaFont[117][3] = 6;

	g_vgaFont[118][0] = 0;
	g_vgaFont[118][1] = 5;
	g_vgaFont[118][2] = 5;
	g_vgaFont[118][3] = 2;

	g_vgaFont[119][0] = 0;
	g_vgaFont[119][1] = 9;
	g_vgaFont[119][2] = 15;
	g_vgaFont[119][3] = 6;

	g_vgaFont[120][0] = 0;
	g_vgaFont[120][1] = 5;
	g_vgaFont[120][2] = 2;
	g_vgaFont[120][3] = 5;

	g_vgaFont[121][0] = 5;
	g_vgaFont[121][1] = 6;
	g_vgaFont[121][2] = 4;
	g_vgaFont[121][3] = 6;

	g_vgaFont[122][0] = 0;
	g_vgaFont[122][1] = 3;
	g_vgaFont[122][2] = 2;
	g_vgaFont[122][3] = 6;








//spec

	g_vgaFont[0][0] = 0;
	g_vgaFont[0][1] = 0;
	g_vgaFont[0][2] = 0;
	g_vgaFont[0][3] = 0;

	g_vgaFont[32][0] = 0;
	g_vgaFont[32][1] = 0;
	g_vgaFont[32][2] = 0;
	g_vgaFont[32][3] = 0;

	g_vgaFont[33][0] = 1;
	g_vgaFont[33][1] = 1;
	g_vgaFont[33][2] = 0;
	g_vgaFont[33][3] = 1;

	g_vgaFont[63][0] = 3;
	g_vgaFont[63][1] = 2;
	g_vgaFont[63][2] = 0;
	g_vgaFont[63][3] = 1;

	g_vgaFont[46][0] = 0;
	g_vgaFont[46][1] = 0;
	g_vgaFont[46][2] = 0;
	g_vgaFont[46][3] = 1;

	g_vgaFont[44][0] = 0;
	g_vgaFont[44][1] = 0;
	g_vgaFont[44][2] = 1;
	g_vgaFont[44][3] = 1;

	g_vgaFont[59][0] = 1;
	g_vgaFont[59][1] = 0;
	g_vgaFont[59][2] = 1;
	g_vgaFont[59][3] = 1;

	g_vgaFont[58][0] = 1;
	g_vgaFont[58][1] = 0;
	g_vgaFont[58][2] = 1;
	g_vgaFont[58][3] = 0;

	g_vgaFont[34][0] = 5;
	g_vgaFont[34][1] = 5;
	g_vgaFont[34][2] = 0;
	g_vgaFont[34][3] = 0;

	g_vgaFont[47][0] = 2;
	g_vgaFont[47][1] = 2;
	g_vgaFont[47][2] = 1;
	g_vgaFont[47][3] = 1;

	g_vgaFont[92][0] = 1;
	g_vgaFont[92][1] = 1;
	g_vgaFont[92][2] = 2;
	g_vgaFont[92][3] = 2;

	g_vgaFont[40][0] = 2;
	g_vgaFont[40][1] = 1;
	g_vgaFont[40][2] = 1;
	g_vgaFont[40][3] = 2;

	g_vgaFont[41][0] = 1;
	g_vgaFont[41][1] = 2;
	g_vgaFont[41][2] = 2;
	g_vgaFont[41][3] = 1;

	g_vgaFont[91][0] = 3;
	g_vgaFont[91][1] = 1;
	g_vgaFont[91][2] = 1;
	g_vgaFont[91][3] = 3;

	g_vgaFont[93][0] = 3;
	g_vgaFont[93][1] = 2;
	g_vgaFont[93][2] = 2;
	g_vgaFont[93][3] = 3;

	g_vgaFont[123][0] = 6;
	g_vgaFont[123][1] = 3;
	g_vgaFont[123][2] = 3;
	g_vgaFont[123][3] = 6;

	g_vgaFont[125][0] = 3;
	g_vgaFont[125][1] = 6;
	g_vgaFont[125][2] = 6;
	g_vgaFont[125][3] = 3;

	g_vgaFont[60][0] = 0;
	g_vgaFont[60][1] = 2;
	g_vgaFont[60][2] = 1;
	g_vgaFont[60][3] = 2;

	g_vgaFont[62][0] = 0;
	g_vgaFont[62][1] = 1;
	g_vgaFont[62][2] = 2;
	g_vgaFont[62][3] = 1;

	g_vgaFont[64][0] = 6;
	g_vgaFont[64][1] = 9;
	g_vgaFont[64][2] = 5;
	g_vgaFont[64][3] = 6;

	g_vgaFont[35][0] = 5;
	g_vgaFont[35][1] = 10;
	g_vgaFont[35][2] = 5;
	g_vgaFont[35][3] = 10;

	g_vgaFont[36][0] = 7;
	g_vgaFont[36][1] = 3;
	g_vgaFont[36][2] = 6;
	g_vgaFont[36][3] = 7;

	g_vgaFont[37][0] = 9;
	g_vgaFont[37][1] = 4;
	g_vgaFont[37][2] = 2;
	g_vgaFont[37][3] = 9;

	g_vgaFont[94][0] = 2;
	g_vgaFont[94][1] = 5;
	g_vgaFont[94][2] = 0;
	g_vgaFont[94][3] = 0;

	g_vgaFont[38][0] = 6;
	g_vgaFont[38][1] = 5;
	g_vgaFont[38][2] = 10;
	g_vgaFont[38][3] = 14;

	g_vgaFont[42][0] = 5;
	g_vgaFont[42][1] = 2;
	g_vgaFont[42][2] = 5;
	g_vgaFont[42][3] = 0;

	g_vgaFont[96][0] = 1;
	g_vgaFont[96][1] = 2;
	g_vgaFont[96][2] = 0;
	g_vgaFont[96][3] = 0;

	g_vgaFont[126][0] = 0;
	g_vgaFont[126][1] = 10;
	g_vgaFont[126][2] = 5;
	g_vgaFont[126][3] = 0;

	g_vgaFont[45][0] = 0;
	g_vgaFont[45][1] = 7;
	g_vgaFont[45][2] = 0;
	g_vgaFont[45][3] = 0;

	g_vgaFont[95][0] = 0;
	g_vgaFont[95][1] = 0;
	g_vgaFont[95][2] = 0;
	g_vgaFont[95][3] = 15;

	g_vgaFont[43][0] = 2;
	g_vgaFont[43][1] = 7;
	g_vgaFont[43][2] = 2;
	g_vgaFont[43][3] = 0;

	g_vgaFont[61][0] = 15;
	g_vgaFont[61][1] = 0;
	g_vgaFont[61][2] = 15;
	g_vgaFont[61][3] = 0;

	g_vgaFont[49][0] = 2;
	g_vgaFont[49][1] = 3;
	g_vgaFont[49][2] = 2;
	g_vgaFont[49][3] = 7;

	g_vgaFont[50][0] = 3;
	g_vgaFont[50][1] = 4;
	g_vgaFont[50][2] = 2;
	g_vgaFont[50][3] = 7;

	g_vgaFont[51][0] = 7;
	g_vgaFont[51][1] = 2;
	g_vgaFont[51][2] = 4;
	g_vgaFont[51][3] = 3;

	g_vgaFont[52][0] = 5;
	g_vgaFont[52][1] = 5;
	g_vgaFont[52][2] = 15;
	g_vgaFont[52][3] = 4;

	g_vgaFont[53][0] = 7;
	g_vgaFont[53][1] = 3;
	g_vgaFont[53][2] = 4;
	g_vgaFont[53][3] = 3;

	g_vgaFont[54][0] = 6;
	g_vgaFont[54][1] = 3;
	g_vgaFont[54][2] = 5;
	g_vgaFont[54][3] = 3;

	g_vgaFont[55][0] = 7;
	g_vgaFont[55][1] = 4;
	g_vgaFont[55][2] = 2;
	g_vgaFont[55][3] = 2;

	g_vgaFont[56][0] = 6;
	g_vgaFont[56][1] = 10;
	g_vgaFont[56][2] = 5;
	g_vgaFont[56][3] = 6;

	g_vgaFont[57][0] = 2;
	g_vgaFont[57][1] = 5;
	g_vgaFont[57][2] = 6;
	g_vgaFont[57][3] = 3;

	g_vgaFont[48][0] = 2;
	g_vgaFont[48][1] = 5;
	g_vgaFont[48][2] = 5;
	g_vgaFont[48][3] = 2;

	g_vgaFont[226][0] = 15;
	g_vgaFont[226][1] = 15;
	g_vgaFont[226][2] = 15;
	g_vgaFont[226][3] = 15;


}
