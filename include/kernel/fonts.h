#ifndef __ddmos_fonts_h__
#define __ddmos_fonts_h__

#include "../ddcDef.h"

struct vgaFont
{
	uint8t A[8];
	uint8t B[8];
	uint8t C[8];
	uint8t D[8];
	uint8t E[8];
	uint8t F[8];
	uint8t G[8];
	uint8t H[8];
	uint8t I[8];
	uint8t J[8];
	uint8t K[8];
	uint8t L[8];
	uint8t M[8];
	uint8t N[8];
	uint8t O[8];
	uint8t P[8];
	uint8t Q[8];
	uint8t R[8];
	uint8t S[8];
	uint8t T[8];
	uint8t U[8];
	uint8t V[8];
	uint8t W[8];
	uint8t X[8];
	uint8t Y[8];
	uint8t Z[8];
	uint8t a[8];
	uint8t b[8];
	uint8t c[8];
	uint8t d[8];
	uint8t e[8];
	uint8t f[8];
	uint8t g[8];
	uint8t h[8];
	uint8t i[8];
	uint8t j[8];
	uint8t k[8];
	uint8t l[8];
	uint8t m[8];
	uint8t n[8];
	uint8t o[8];
	uint8t p[8];
	uint8t q[8];
	uint8t r[8];
	uint8t s[8];
	uint8t t[8];
	uint8t u[8];
	uint8t v[8];
	uint8t w[8];
	uint8t x[8];
	uint8t y[8];
	uint8t z[8];
	uint8t D0[8];
	uint8t D1[8];
	uint8t D2[8];
	uint8t D3[8];
	uint8t D4[8];
	uint8t D5[8];
	uint8t D6[8];
	uint8t D7[8];
	uint8t D8[8];
	uint8t D9[8];

	uint8t explpnt[8];
	uint8t questmk[8];
	uint8t dot[8];
	uint8t comma[8];
	uint8t scolon[8];
	uint8t colon[8];
	uint8t dquote[8];
	uint8t quote[8];
	uint8t fslash[8];
	uint8t bslash[8];
	uint8t opbracket[8];
	uint8t cpbracket[8];
	uint8t osbracket[8];
	uint8t csbracket[8];
	uint8t ocbracket[8];
	uint8t ccbracket[8];
	uint8t otbracket[8];
	uint8t ctbracket[8];

	uint8t at[8];
	uint8t hashtag[8];
	uint8t moneysign[8];
	uint8t percent[8];
	uint8t caret[8];
	uint8t amp[8];
	uint8t star[8];
	uint8t aposth[8];
	uint8t tilde[8];
	uint8t dash[8];
	uint8t underscore[8];
	uint8t plus[8];
	uint8t equals[8];
};


void init_fonts(void);

extern struct vgaFont g_vgaFont;






#endif
