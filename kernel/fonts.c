#include "../include/kernel/fonts.h"

struct vgaFont g_vgaFont;

void init_fonts(void)
{
	g_vgaFont.A[0] = 2;
	g_vgaFont.A[1] = 5;
	g_vgaFont.A[2] = 7;
	g_vgaFont.A[3] = 5;

	g_vgaFont.B[0] = 3;
	g_vgaFont.B[1] = 7;
	g_vgaFont.B[2] = 5;
	g_vgaFont.B[3] = 3;

	g_vgaFont.C[0] = 6;
	g_vgaFont.C[1] = 1;
	g_vgaFont.C[2] = 1;
	g_vgaFont.C[3] = 6;

	g_vgaFont.D[0] = 3;
	g_vgaFont.D[1] = 5;
	g_vgaFont.D[2] = 5;
	g_vgaFont.D[3] = 3;

	g_vgaFont.E[0] = 7;
	g_vgaFont.E[1] = 3;
	g_vgaFont.E[2] = 1;
	g_vgaFont.E[3] = 7;

	g_vgaFont.F[0] = 7;
	g_vgaFont.F[1] = 1;
	g_vgaFont.F[2] = 3;
	g_vgaFont.F[3] = 1;

	g_vgaFont.G[0] = 6;
	g_vgaFont.G[1] = 1;
	g_vgaFont.G[2] = 13;
	g_vgaFont.G[3] = 6;

	g_vgaFont.H[0] = 5;
	g_vgaFont.H[1] = 7;
	g_vgaFont.H[2] = 5;
	g_vgaFont.H[3] = 5;

	g_vgaFont.I[0] = 7;
	g_vgaFont.I[1] = 2;
	g_vgaFont.I[2] = 2;
	g_vgaFont.I[3] = 7;

	g_vgaFont.J[0] = 7;
	g_vgaFont.J[1] = 2;
	g_vgaFont.J[2] = 2;
	g_vgaFont.J[3] = 3;

	g_vgaFont.K[0] = 5;
	g_vgaFont.K[1] = 3;
	g_vgaFont.K[2] = 5;
	g_vgaFont.K[3] = 5;

	g_vgaFont.L[0] = 1;
	g_vgaFont.L[1] = 1;
	g_vgaFont.L[2] = 1;
	g_vgaFont.L[3] = 7;

	g_vgaFont.M[0] = 6;
	g_vgaFont.M[1] = 15;
	g_vgaFont.M[2] = 9;
	g_vgaFont.M[3] = 9;

	g_vgaFont.N[0] = 9;
	g_vgaFont.N[1] = 11;
	g_vgaFont.N[2] = 13;
	g_vgaFont.N[3] = 9;

	g_vgaFont.O[0] = 6;
	g_vgaFont.O[1] = 9;
	g_vgaFont.O[2] = 9;
	g_vgaFont.O[3] = 6;

	g_vgaFont.P[0] = 3;
	g_vgaFont.P[1] = 5;
	g_vgaFont.P[2] = 3;
	g_vgaFont.P[3] = 1;

	g_vgaFont.Q[0] = 6;
	g_vgaFont.Q[1] = 9;
	g_vgaFont.Q[2] = 5;
	g_vgaFont.Q[3] = 10;

	g_vgaFont.R[0] = 3;
	g_vgaFont.R[1] = 5;
	g_vgaFont.R[2] = 3;
	g_vgaFont.R[3] = 5;

	g_vgaFont.S[0] = 3;
	g_vgaFont.S[1] = 1;
	g_vgaFont.S[2] = 2;
	g_vgaFont.S[3] = 3;

	g_vgaFont.T[0] = 7;
	g_vgaFont.T[1] = 2;
	g_vgaFont.T[2] = 2;
	g_vgaFont.T[3] = 2;

	g_vgaFont.U[0] = 5;
	g_vgaFont.U[1] = 5;
	g_vgaFont.U[2] = 5;
	g_vgaFont.U[3] = 6;

	g_vgaFont.V[0] = 5;
	g_vgaFont.V[1] = 5;
	g_vgaFont.V[2] = 5;
	g_vgaFont.V[3] = 2;

	g_vgaFont.W[0] = 9;
	g_vgaFont.W[1] = 9;
	g_vgaFont.W[2] = 11;
	g_vgaFont.W[3] = 13;

	g_vgaFont.X[0] = 5;
	g_vgaFont.X[1] = 2;
	g_vgaFont.X[2] = 2;
	g_vgaFont.X[3] = 5;

	g_vgaFont.Y[0] = 5;
	g_vgaFont.Y[1] = 5;
	g_vgaFont.Y[2] = 2;
	g_vgaFont.Y[3] = 2;

	g_vgaFont.Z[0] = 3;
	g_vgaFont.Z[1] = 2;
	g_vgaFont.Z[2] = 1;
	g_vgaFont.Z[3] = 3;





//lower

	g_vgaFont.a[0] = 0;
	g_vgaFont.a[1] = 6;
	g_vgaFont.a[2] = 5;
	g_vgaFont.a[3] = 6;

	g_vgaFont.b[0] = 1;
	g_vgaFont.b[1] = 3;
	g_vgaFont.b[2] = 5;
	g_vgaFont.b[3] = 3;

	g_vgaFont.c[0] = 0;
	g_vgaFont.c[1] = 2;
	g_vgaFont.c[2] = 1;
	g_vgaFont.c[3] = 3;

	g_vgaFont.d[0] = 4;
	g_vgaFont.d[1] = 6;
	g_vgaFont.d[2] = 5;
	g_vgaFont.d[3] = 6;

	g_vgaFont.e[0] = 0;
	g_vgaFont.e[1] = 6;
	g_vgaFont.e[2] = 3;
	g_vgaFont.e[3] = 6;

	g_vgaFont.f[0] = 6;
	g_vgaFont.f[1] = 2;
	g_vgaFont.f[2] = 7;
	g_vgaFont.f[3] = 2;

	g_vgaFont.g[0] = 2;
	g_vgaFont.g[1] = 7;
	g_vgaFont.g[2] = 4;
	g_vgaFont.g[3] = 6;

	g_vgaFont.h[0] = 1;
	g_vgaFont.h[1] = 1;
	g_vgaFont.h[2] = 7;
	g_vgaFont.h[3] = 5;

	g_vgaFont.i[0] = 2;
	g_vgaFont.i[1] = 0;
	g_vgaFont.i[2] = 2;
	g_vgaFont.i[3] = 2;

	g_vgaFont.j[0] = 2;
	g_vgaFont.j[1] = 0;
	g_vgaFont.j[2] = 2;
	g_vgaFont.j[3] = 3;

	g_vgaFont.k[0] = 0;
	g_vgaFont.k[1] = 5;
	g_vgaFont.k[2] = 3;
	g_vgaFont.k[3] = 5;

	g_vgaFont.l[0] = 2;
	g_vgaFont.l[1] = 2;
	g_vgaFont.l[2] = 2;
	g_vgaFont.l[3] = 2;

	g_vgaFont.m[0] = 0;
	g_vgaFont.m[1] = 0;
	g_vgaFont.m[2] = 15;
	g_vgaFont.m[3] = 13;

	g_vgaFont.n[0] = 0;
	g_vgaFont.n[1] = 3;
	g_vgaFont.n[2] = 5;
	g_vgaFont.n[3] = 5;

	g_vgaFont.o[0] = 0;
	g_vgaFont.o[1] = 6;
	g_vgaFont.o[2] = 5;
	g_vgaFont.o[3] = 3;

	g_vgaFont.p[0] = 2;
	g_vgaFont.p[1] = 5;
	g_vgaFont.p[2] = 3;
	g_vgaFont.p[3] = 1;

	g_vgaFont.q[0] = 2;
	g_vgaFont.q[1] = 5;
	g_vgaFont.q[2] = 6;
	g_vgaFont.q[3] = 12;

	g_vgaFont.r[0] = 0;
	g_vgaFont.r[1] = 6;
	g_vgaFont.r[2] = 2;
	g_vgaFont.r[3] = 2;

	g_vgaFont.s[0] = 2;
	g_vgaFont.s[1] = 1;
	g_vgaFont.s[2] = 2;
	g_vgaFont.s[3] = 3;

	g_vgaFont.t[0] = 2;
	g_vgaFont.t[1] = 7;
	g_vgaFont.t[2] = 2;
	g_vgaFont.t[3] = 2;

	g_vgaFont.u[0] = 0;
	g_vgaFont.u[1] = 5;
	g_vgaFont.u[2] = 5;
	g_vgaFont.u[3] = 6;

	g_vgaFont.v[0] = 0;
	g_vgaFont.v[1] = 5;
	g_vgaFont.v[2] = 5;
	g_vgaFont.v[3] = 2;

	g_vgaFont.w[0] = 0;
	g_vgaFont.w[1] = 9;
	g_vgaFont.w[2] = 15;
	g_vgaFont.w[3] = 6;

	g_vgaFont.x[0] = 0;
	g_vgaFont.x[1] = 5;
	g_vgaFont.x[2] = 2;
	g_vgaFont.x[3] = 5;

	g_vgaFont.y[0] = 5;
	g_vgaFont.y[1] = 6;
	g_vgaFont.y[2] = 4;
	g_vgaFont.y[3] = 6;

	g_vgaFont.z[0] = 0;
	g_vgaFont.z[1] = 3;
	g_vgaFont.z[2] = 2;
	g_vgaFont.z[3] = 6;








//spec

	g_vgaFont.explpnt[0] = 1;
	g_vgaFont.explpnt[1] = 1;
	g_vgaFont.explpnt[2] = 0;
	g_vgaFont.explpnt[3] = 1;

	g_vgaFont.questmk[0] = 3;
	g_vgaFont.questmk[1] = 2;
	g_vgaFont.questmk[2] = 0;
	g_vgaFont.questmk[3] = 1;

	g_vgaFont.dot[0] = 0;
	g_vgaFont.dot[1] = 0;
	g_vgaFont.dot[2] = 0;
	g_vgaFont.dot[3] = 1;

	g_vgaFont.comma[0] = 0;
	g_vgaFont.comma[1] = 0;
	g_vgaFont.comma[2] = 1;
	g_vgaFont.comma[3] = 1;

	g_vgaFont.scolon[0] = 1;
	g_vgaFont.scolon[1] = 0;
	g_vgaFont.scolon[2] = 1;
	g_vgaFont.scolon[3] = 1;

	g_vgaFont.colon[0] = 1;
	g_vgaFont.colon[1] = 0;
	g_vgaFont.colon[2] = 1;
	g_vgaFont.colon[3] = 0;

	g_vgaFont.dquote[0] = 5;
	g_vgaFont.dquote[1] = 5;
	g_vgaFont.dquote[2] = 0;
	g_vgaFont.dquote[3] = 0;

	g_vgaFont.fslash[0] = 2;
	g_vgaFont.fslash[1] = 2;
	g_vgaFont.fslash[2] = 1;
	g_vgaFont.fslash[3] = 1;

	g_vgaFont.bslash[0] = 1;
	g_vgaFont.bslash[1] = 1;
	g_vgaFont.bslash[2] = 2;
	g_vgaFont.bslash[3] = 2;

	g_vgaFont.opbracket[0] = 2;
	g_vgaFont.opbracket[1] = 1;
	g_vgaFont.opbracket[2] = 1;
	g_vgaFont.opbracket[3] = 2;

	g_vgaFont.cpbracket[0] = 1;
	g_vgaFont.cpbracket[1] = 2;
	g_vgaFont.cpbracket[2] = 2;
	g_vgaFont.cpbracket[3] = 1;

	g_vgaFont.osbracket[0] = 3;
	g_vgaFont.osbracket[1] = 1;
	g_vgaFont.osbracket[2] = 1;
	g_vgaFont.osbracket[3] = 3;

	g_vgaFont.csbracket[0] = 3;
	g_vgaFont.csbracket[1] = 2;
	g_vgaFont.csbracket[2] = 2;
	g_vgaFont.csbracket[3] = 3;

	g_vgaFont.ocbracket[0] = 6;
	g_vgaFont.ocbracket[1] = 3;
	g_vgaFont.ocbracket[2] = 3;
	g_vgaFont.ocbracket[3] = 6;

	g_vgaFont.ccbracket[0] = 3;
	g_vgaFont.ccbracket[1] = 6;
	g_vgaFont.ccbracket[2] = 6;
	g_vgaFont.ccbracket[3] = 3;

	g_vgaFont.otbracket[0] = 0;
	g_vgaFont.otbracket[1] = 2;
	g_vgaFont.otbracket[2] = 1;
	g_vgaFont.otbracket[3] = 2;

	g_vgaFont.ctbracket[0] = 0;
	g_vgaFont.ctbracket[1] = 1;
	g_vgaFont.ctbracket[2] = 2;
	g_vgaFont.ctbracket[3] = 1;

	g_vgaFont.at[0] = 6;
	g_vgaFont.at[1] = 9;
	g_vgaFont.at[2] = 5;
	g_vgaFont.at[3] = 6;

	g_vgaFont.hashtag[0] = 5;
	g_vgaFont.hashtag[1] = 10;
	g_vgaFont.hashtag[2] = 5;
	g_vgaFont.hashtag[3] = 10;

	g_vgaFont.moneysign[0] = 7;
	g_vgaFont.moneysign[1] = 3;
	g_vgaFont.moneysign[2] = 6;
	g_vgaFont.moneysign[3] = 7;

	g_vgaFont.percent[0] = 9;
	g_vgaFont.percent[1] = 4;
	g_vgaFont.percent[2] = 2;
	g_vgaFont.percent[3] = 9;

	g_vgaFont.caret[0] = 2;
	g_vgaFont.caret[1] = 5;
	g_vgaFont.caret[2] = 0;
	g_vgaFont.caret[3] = 0;

	g_vgaFont.amp[0] = 6;
	g_vgaFont.amp[1] = 5;
	g_vgaFont.amp[2] = 10;
	g_vgaFont.amp[3] = 14;

	g_vgaFont.star[0] = 5;
	g_vgaFont.star[1] = 2;
	g_vgaFont.star[2] = 5;
	g_vgaFont.star[3] = 0;

	g_vgaFont.aposth[0] = 1;
	g_vgaFont.aposth[1] = 2;
	g_vgaFont.aposth[2] = 0;
	g_vgaFont.aposth[3] = 0;

	g_vgaFont.tilde[0] = 0;
	g_vgaFont.tilde[1] = 10;
	g_vgaFont.tilde[2] = 5;
	g_vgaFont.tilde[3] = 0;

	g_vgaFont.dash[0] = 0;
	g_vgaFont.dash[1] = 7;
	g_vgaFont.dash[2] = 0;
	g_vgaFont.dash[3] = 0;

	g_vgaFont.underscore[0] = 0;
	g_vgaFont.underscore[1] = 0;
	g_vgaFont.underscore[2] = 0;
	g_vgaFont.underscore[3] = 15;

	g_vgaFont.plus[0] = 2;
	g_vgaFont.plus[1] = 7;
	g_vgaFont.plus[2] = 2;
	g_vgaFont.plus[3] = 0;

	g_vgaFont.equals[0] = 15;
	g_vgaFont.equals[1] = 0;
	g_vgaFont.equals[2] = 15;
	g_vgaFont.equals[3] = 0;

	g_vgaFont.D1[0] = 2;
	g_vgaFont.D1[1] = 3;
	g_vgaFont.D1[2] = 2;
	g_vgaFont.D1[3] = 7;

	g_vgaFont.D2[0] = 3;
	g_vgaFont.D2[1] = 4;
	g_vgaFont.D2[2] = 2;
	g_vgaFont.D2[3] = 7;

	g_vgaFont.D3[0] = 7;
	g_vgaFont.D3[1] = 2;
	g_vgaFont.D3[2] = 4;
	g_vgaFont.D3[3] = 3;

	g_vgaFont.D4[0] = 5;
	g_vgaFont.D4[1] = 5;
	g_vgaFont.D4[2] = 15;
	g_vgaFont.D4[3] = 4;

	g_vgaFont.D5[0] = 7;
	g_vgaFont.D5[1] = 3;
	g_vgaFont.D5[2] = 4;
	g_vgaFont.D5[3] = 3;

	g_vgaFont.D6[0] = 6;
	g_vgaFont.D6[1] = 3;
	g_vgaFont.D6[2] = 5;
	g_vgaFont.D6[3] = 3;

	g_vgaFont.D7[0] = 7;
	g_vgaFont.D7[1] = 4;
	g_vgaFont.D7[2] = 2;
	g_vgaFont.D7[3] = 2;

	g_vgaFont.D8[0] = 6;
	g_vgaFont.D8[1] = 10;
	g_vgaFont.D8[2] = 5;
	g_vgaFont.D8[3] = 6;

	g_vgaFont.D9[0] = 2;
	g_vgaFont.D9[1] = 5;
	g_vgaFont.D9[2] = 6;
	g_vgaFont.D9[3] = 3;

	g_vgaFont.D0[0] = 2;
	g_vgaFont.D0[1] = 5;
	g_vgaFont.D0[2] = 5;
	g_vgaFont.D0[3] = 2;






}
