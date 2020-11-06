#include "../include/kernel/fonts.h"

struct vgaFont g_vgaFont;

void init_fonts(void)
{
	

	g_vgaFont.A[0] = 0;
	g_vgaFont.A[1] = 0;
	g_vgaFont.A[2] = 60;
	g_vgaFont.A[3] = 102;
	g_vgaFont.A[4] = 102;
	g_vgaFont.A[5] = 126;
	g_vgaFont.A[6] = 102;
	g_vgaFont.A[7] = 102;

	g_vgaFont.B[0] = 0;
	g_vgaFont.B[1] = 0;
	g_vgaFont.B[2] = 62;
	g_vgaFont.B[3] = 102;
	g_vgaFont.B[4] = 62;
	g_vgaFont.B[5] = 102;
	g_vgaFont.B[6] = 102;
	g_vgaFont.B[7] = 62;

	g_vgaFont.C[0] = 0;
	g_vgaFont.C[1] = 0;
	g_vgaFont.C[2] = 60;
	g_vgaFont.C[3] = 102;
	g_vgaFont.C[4] = 6;
	g_vgaFont.C[5] = 6;
	g_vgaFont.C[6] = 102;
	g_vgaFont.C[7] = 60;

	g_vgaFont.D[0] = 0;
	g_vgaFont.D[1] = 0;
	g_vgaFont.D[2] = 62;
	g_vgaFont.D[3] = 102;
	g_vgaFont.D[4] = 102;
	g_vgaFont.D[5] = 102;
	g_vgaFont.D[6] = 102;
	g_vgaFont.D[7] = 62;

	g_vgaFont.E[0] = 0;
	g_vgaFont.E[1] = 0;
	g_vgaFont.E[2] = 126;
	g_vgaFont.E[3] = 6;
	g_vgaFont.E[4] = 62;
	g_vgaFont.E[5] = 6;
	g_vgaFont.E[6] = 6;
	g_vgaFont.E[7] = 126;

	g_vgaFont.F[0] = 0;
	g_vgaFont.F[1] = 0;
	g_vgaFont.F[2] = 126;
	g_vgaFont.F[3] = 6;
	g_vgaFont.F[4] = 6;
	g_vgaFont.F[5] = 62;
	g_vgaFont.F[6] = 6;
	g_vgaFont.F[7] = 6;

	g_vgaFont.G[0] = 0;
	g_vgaFont.G[1] = 0;
	g_vgaFont.G[2] = 60;
	g_vgaFont.G[3] = 102;
	g_vgaFont.G[4] = 6;
	g_vgaFont.G[5] = 118;
	g_vgaFont.G[6] = 102;
	g_vgaFont.G[7] = 124;

	g_vgaFont.H[0] = 0;
	g_vgaFont.H[1] = 0;
	g_vgaFont.H[2] = 102;
	g_vgaFont.H[3] = 102;
	g_vgaFont.H[4] = 126;
	g_vgaFont.H[5] = 102;
	g_vgaFont.H[6] = 102;
	g_vgaFont.H[7] = 102;

	g_vgaFont.I[0] = 0;
	g_vgaFont.I[1] = 0;
	g_vgaFont.I[2] = 60;
	g_vgaFont.I[3] = 24;
	g_vgaFont.I[4] = 24;
	g_vgaFont.I[5] = 24;
	g_vgaFont.I[6] = 24;
	g_vgaFont.I[7] = 60;

	g_vgaFont.J[0] = 0;
	g_vgaFont.J[1] = 0;
	g_vgaFont.J[2] = 112;
	g_vgaFont.J[3] = 96;
	g_vgaFont.J[4] = 96;
	g_vgaFont.J[5] = 96;
	g_vgaFont.J[6] = 102;
	g_vgaFont.J[7] = 60;

	g_vgaFont.K[0] = 0;
	g_vgaFont.K[1] = 0;
	g_vgaFont.K[2] = 102;
	g_vgaFont.K[3] = 54;
	g_vgaFont.K[4] = 30;
	g_vgaFont.K[5] = 30;
	g_vgaFont.K[6] = 54;
	g_vgaFont.K[7] = 102;

	g_vgaFont.L[0] = 0;
	g_vgaFont.L[1] = 0;
	g_vgaFont.L[2] = 6;
	g_vgaFont.L[3] = 6;
	g_vgaFont.L[4] = 6;
	g_vgaFont.L[5] = 6;
	g_vgaFont.L[6] = 6;
	g_vgaFont.L[7] = 126;

	g_vgaFont.M[0] = 0;
	g_vgaFont.M[1] = 0;
	g_vgaFont.M[2] = 70;
	g_vgaFont.M[3] = 110;
	g_vgaFont.M[4] = 126;
	g_vgaFont.M[5] = 86;
	g_vgaFont.M[6] = 70;
	g_vgaFont.M[7] = 70;

	g_vgaFont.N[0] = 0;
	g_vgaFont.N[1] = 0;
	g_vgaFont.N[2] = 70;
	g_vgaFont.N[3] = 78;
	g_vgaFont.N[4] = 94;
	g_vgaFont.N[5] = 118;
	g_vgaFont.N[6] = 102;
	g_vgaFont.N[7] = 70;

	g_vgaFont.O[0] = 0;
	g_vgaFont.O[1] = 0;
	g_vgaFont.O[2] = 60;
	g_vgaFont.O[3] = 102;
	g_vgaFont.O[4] = 102;
	g_vgaFont.O[5] = 102;
	g_vgaFont.O[6] = 102;
	g_vgaFont.O[7] = 60;

	g_vgaFont.P[0] = 0;
	g_vgaFont.P[1] = 0;
	g_vgaFont.P[2] = 62;
	g_vgaFont.P[3] = 102;
	g_vgaFont.P[4] = 102;
	g_vgaFont.P[5] = 62;
	g_vgaFont.P[6] = 6;
	g_vgaFont.P[7] = 6;

	g_vgaFont.Q[0] = 0;
	g_vgaFont.Q[1] = 0;
	g_vgaFont.Q[2] = 60;
	g_vgaFont.Q[3] = 102;
	g_vgaFont.Q[4] = 70;
	g_vgaFont.Q[5] = 86;
	g_vgaFont.Q[6] = 38;
	g_vgaFont.Q[7] = 92;

	g_vgaFont.R[0] = 0;
	g_vgaFont.R[1] = 0;
	g_vgaFont.R[2] = 62;
	g_vgaFont.R[3] = 102;
	g_vgaFont.R[4] = 102;
	g_vgaFont.R[5] = 62;
	g_vgaFont.R[6] = 102;
	g_vgaFont.R[7] = 102;

	g_vgaFont.S[0] = 0;
	g_vgaFont.S[1] = 0;
	g_vgaFont.S[2] = 60;
	g_vgaFont.S[3] = 6;
	g_vgaFont.S[4] = 60;
	g_vgaFont.S[5] = 96;
	g_vgaFont.S[6] = 102;
	g_vgaFont.S[7] = 60;

	g_vgaFont.T[0] = 0;
	g_vgaFont.T[1] = 0;
	g_vgaFont.T[2] = 126;
	g_vgaFont.T[3] = 24;
	g_vgaFont.T[4] = 24;
	g_vgaFont.T[5] = 24;
	g_vgaFont.T[6] = 24;
	g_vgaFont.T[7] = 24;

	g_vgaFont.U[0] = 0;
	g_vgaFont.U[1] = 0;
	g_vgaFont.U[2] = 102;
	g_vgaFont.U[3] = 102;
	g_vgaFont.U[4] = 102;
	g_vgaFont.U[5] = 102;
	g_vgaFont.U[6] = 102;
	g_vgaFont.U[7] = 60;

	g_vgaFont.V[0] = 0;
	g_vgaFont.V[1] = 0;
	g_vgaFont.V[2] = 102;
	g_vgaFont.V[3] = 102;
	g_vgaFont.V[4] = 102;
	g_vgaFont.V[5] = 102;
	g_vgaFont.V[6] = 60;
	g_vgaFont.V[7] = 24;

	g_vgaFont.W[0] = 0;
	g_vgaFont.W[1] = 0;
	g_vgaFont.W[2] = 70;
	g_vgaFont.W[3] = 70;
	g_vgaFont.W[4] = 86;
	g_vgaFont.W[5] = 126;
	g_vgaFont.W[6] = 110;
	g_vgaFont.W[7] = 70;

	g_vgaFont.X[0] = 0;
	g_vgaFont.X[1] = 0;
	g_vgaFont.X[2] = 102;
	g_vgaFont.X[3] = 102;
	g_vgaFont.X[4] = 60;
	g_vgaFont.X[5] = 60;
	g_vgaFont.X[6] = 102;
	g_vgaFont.X[7] = 102;

	g_vgaFont.Y[0] = 0;
	g_vgaFont.Y[1] = 0;
	g_vgaFont.Y[2] = 102;
	g_vgaFont.Y[3] = 102;
	g_vgaFont.Y[4] = 102;
	g_vgaFont.Y[5] = 60;
	g_vgaFont.Y[6] = 24;
	g_vgaFont.Y[7] = 24;

	g_vgaFont.Z[0] = 0;
	g_vgaFont.Z[1] = 0;
	g_vgaFont.Z[2] = 126;
	g_vgaFont.Z[3] = 112;
	g_vgaFont.Z[4] = 56;
	g_vgaFont.Z[5] = 28;
	g_vgaFont.Z[6] = 14;
	g_vgaFont.Z[7] = 126;


}
