#include "../include/kernel/fonts.h"

struct vgaFont vgaFontDefault;

void init_fonts(void)
{
	

	vgaFontDefault.A[0] = 0;
	vgaFontDefault.A[1] = 0;
	vgaFontDefault.A[2] = 60;
	vgaFontDefault.A[3] = 102;
	vgaFontDefault.A[4] = 102;
	vgaFontDefault.A[5] = 126;
	vgaFontDefault.A[6] = 102;
	vgaFontDefault.A[7] = 102;

	vgaFontDefault.B[0] = 0;
	vgaFontDefault.B[1] = 0;
	vgaFontDefault.B[2] = 62;
	vgaFontDefault.B[3] = 102;
	vgaFontDefault.B[4] = 62;
	vgaFontDefault.B[5] = 102;
	vgaFontDefault.B[6] = 102;
	vgaFontDefault.B[7] = 62;

	vgaFontDefault.C[0] = 0;
	vgaFontDefault.C[1] = 0;
	vgaFontDefault.C[2] = 60;
	vgaFontDefault.C[3] = 102;
	vgaFontDefault.C[4] = 6;
	vgaFontDefault.C[5] = 6;
	vgaFontDefault.C[6] = 102;
	vgaFontDefault.C[7] = 60;

	vgaFontDefault.D[0] = 0;
	vgaFontDefault.D[1] = 0;
	vgaFontDefault.D[2] = 62;
	vgaFontDefault.D[3] = 102;
	vgaFontDefault.D[4] = 102;
	vgaFontDefault.D[5] = 102;
	vgaFontDefault.D[6] = 102;
	vgaFontDefault.D[7] = 62;

	vgaFontDefault.E[0] = 0;
	vgaFontDefault.E[1] = 0;
	vgaFontDefault.E[2] = 126;
	vgaFontDefault.E[3] = 6;
	vgaFontDefault.E[4] = 62;
	vgaFontDefault.E[5] = 6;
	vgaFontDefault.E[6] = 6;
	vgaFontDefault.E[7] = 126;

	vgaFontDefault.F[0] = 0;
	vgaFontDefault.F[1] = 0;
	vgaFontDefault.F[2] = 126;
	vgaFontDefault.F[3] = 6;
	vgaFontDefault.F[4] = 6;
	vgaFontDefault.F[5] = 62;
	vgaFontDefault.F[6] = 6;
	vgaFontDefault.F[7] = 6;

	vgaFontDefault.G[0] = 0;
	vgaFontDefault.G[1] = 0;
	vgaFontDefault.G[2] = 60;
	vgaFontDefault.G[3] = 102;
	vgaFontDefault.G[4] = 6;
	vgaFontDefault.G[5] = 118;
	vgaFontDefault.G[6] = 102;
	vgaFontDefault.G[7] = 124;

	vgaFontDefault.H[0] = 0;
	vgaFontDefault.H[1] = 0;
	vgaFontDefault.H[2] = 102;
	vgaFontDefault.H[3] = 102;
	vgaFontDefault.H[4] = 126;
	vgaFontDefault.H[5] = 102;
	vgaFontDefault.H[6] = 102;
	vgaFontDefault.H[7] = 102;

	vgaFontDefault.I[0] = 0;
	vgaFontDefault.I[1] = 0;
	vgaFontDefault.I[2] = 60;
	vgaFontDefault.I[3] = 24;
	vgaFontDefault.I[4] = 24;
	vgaFontDefault.I[5] = 24;
	vgaFontDefault.I[6] = 24;
	vgaFontDefault.I[7] = 60;

	vgaFontDefault.J[0] = 0;
	vgaFontDefault.J[1] = 0;
	vgaFontDefault.J[2] = 112;
	vgaFontDefault.J[3] = 96;
	vgaFontDefault.J[4] = 96;
	vgaFontDefault.J[5] = 96;
	vgaFontDefault.J[6] = 102;
	vgaFontDefault.J[7] = 60;

	vgaFontDefault.K[0] = 0;
	vgaFontDefault.K[1] = 0;
	vgaFontDefault.K[2] = 102;
	vgaFontDefault.K[3] = 54;
	vgaFontDefault.K[4] = 30;
	vgaFontDefault.K[5] = 30;
	vgaFontDefault.K[6] = 54;
	vgaFontDefault.K[7] = 102;

	vgaFontDefault.L[0] = 0;
	vgaFontDefault.L[1] = 0;
	vgaFontDefault.L[2] = 6;
	vgaFontDefault.L[3] = 6;
	vgaFontDefault.L[4] = 6;
	vgaFontDefault.L[5] = 6;
	vgaFontDefault.L[6] = 6;
	vgaFontDefault.L[7] = 126;

	vgaFontDefault.M[0] = 0;
	vgaFontDefault.M[1] = 0;
	vgaFontDefault.M[2] = 70;
	vgaFontDefault.M[3] = 110;
	vgaFontDefault.M[4] = 126;
	vgaFontDefault.M[5] = 86;
	vgaFontDefault.M[6] = 70;
	vgaFontDefault.M[7] = 70;

	vgaFontDefault.N[0] = 0;
	vgaFontDefault.N[1] = 0;
	vgaFontDefault.N[2] = 70;
	vgaFontDefault.N[3] = 78;
	vgaFontDefault.N[4] = 94;
	vgaFontDefault.N[5] = 118;
	vgaFontDefault.N[6] = 102;
	vgaFontDefault.N[7] = 70;

	vgaFontDefault.O[0] = 0;
	vgaFontDefault.O[1] = 0;
	vgaFontDefault.O[2] = 60;
	vgaFontDefault.O[3] = 102;
	vgaFontDefault.O[4] = 102;
	vgaFontDefault.O[5] = 102;
	vgaFontDefault.O[6] = 102;
	vgaFontDefault.O[7] = 60;

	vgaFontDefault.P[0] = 0;
	vgaFontDefault.P[1] = 0;
	vgaFontDefault.P[2] = 62;
	vgaFontDefault.P[3] = 102;
	vgaFontDefault.P[4] = 102;
	vgaFontDefault.P[5] = 62;
	vgaFontDefault.P[6] = 6;
	vgaFontDefault.P[7] = 6;

	vgaFontDefault.Q[0] = 0;
	vgaFontDefault.Q[1] = 0;
	vgaFontDefault.Q[2] = 60;
	vgaFontDefault.Q[3] = 102;
	vgaFontDefault.Q[4] = 70;
	vgaFontDefault.Q[5] = 86;
	vgaFontDefault.Q[6] = 38;
	vgaFontDefault.Q[7] = 92;

	vgaFontDefault.R[0] = 0;
	vgaFontDefault.R[1] = 0;
	vgaFontDefault.R[2] = 62;
	vgaFontDefault.R[3] = 102;
	vgaFontDefault.R[4] = 102;
	vgaFontDefault.R[5] = 62;
	vgaFontDefault.R[6] = 102;
	vgaFontDefault.R[7] = 102;

	vgaFontDefault.S[0] = 0;
	vgaFontDefault.S[1] = 0;
	vgaFontDefault.S[2] = 60;
	vgaFontDefault.S[3] = 6;
	vgaFontDefault.S[4] = 60;
	vgaFontDefault.S[5] = 96;
	vgaFontDefault.S[6] = 102;
	vgaFontDefault.S[7] = 60;

	vgaFontDefault.T[0] = 0;
	vgaFontDefault.T[1] = 0;
	vgaFontDefault.T[2] = 126;
	vgaFontDefault.T[3] = 24;
	vgaFontDefault.T[4] = 24;
	vgaFontDefault.T[5] = 24;
	vgaFontDefault.T[6] = 24;
	vgaFontDefault.T[7] = 24;

	vgaFontDefault.U[0] = 0;
	vgaFontDefault.U[1] = 0;
	vgaFontDefault.U[2] = 102;
	vgaFontDefault.U[3] = 102;
	vgaFontDefault.U[4] = 102;
	vgaFontDefault.U[5] = 102;
	vgaFontDefault.U[6] = 102;
	vgaFontDefault.U[7] = 60;

	vgaFontDefault.V[0] = 0;
	vgaFontDefault.V[1] = 0;
	vgaFontDefault.V[2] = 102;
	vgaFontDefault.V[3] = 102;
	vgaFontDefault.V[4] = 102;
	vgaFontDefault.V[5] = 102;
	vgaFontDefault.V[6] = 60;
	vgaFontDefault.V[7] = 24;

	vgaFontDefault.W[0] = 0;
	vgaFontDefault.W[1] = 0;
	vgaFontDefault.W[2] = 70;
	vgaFontDefault.W[3] = 70;
	vgaFontDefault.W[4] = 86;
	vgaFontDefault.W[5] = 126;
	vgaFontDefault.W[6] = 110;
	vgaFontDefault.W[7] = 70;

	vgaFontDefault.X[0] = 0;
	vgaFontDefault.X[1] = 0;
	vgaFontDefault.X[2] = 102;
	vgaFontDefault.X[3] = 102;
	vgaFontDefault.X[4] = 60;
	vgaFontDefault.X[5] = 60;
	vgaFontDefault.X[6] = 102;
	vgaFontDefault.X[7] = 102;

	vgaFontDefault.Y[0] = 0;
	vgaFontDefault.Y[1] = 0;
	vgaFontDefault.Y[2] = 102;
	vgaFontDefault.Y[3] = 102;
	vgaFontDefault.Y[4] = 102;
	vgaFontDefault.Y[5] = 60;
	vgaFontDefault.Y[6] = 24;
	vgaFontDefault.Y[7] = 24;

	vgaFontDefault.Z[0] = 0;
	vgaFontDefault.Z[1] = 0;
	vgaFontDefault.Z[2] = 126;
	vgaFontDefault.Z[3] = 112;
	vgaFontDefault.Z[4] = 56;
	vgaFontDefault.Z[5] = 28;
	vgaFontDefault.Z[6] = 14;
	vgaFontDefault.Z[7] = 126;


}
