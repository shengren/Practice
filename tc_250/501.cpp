#include <iostream>

using namespace std;

const double INF = 1e12;

double smax[51][51];
double smin[51][51];

class FoxPlayingGame
{
public:
	double theMax(int nA, int nB, int pA, int pB)
	{
		double sA = pA / 1000.0;
		double sB = pB / 1000.0;
		for (int i = 0; i <= nA; ++i)
		{
			for (int j = 0; j <= nB; ++j)
			{
				smax[i][j] = -INF;
				smin[i][j] = INF;
			}
		}
		smax[0][0] = smin[0][0] = 0.0;
		for (int i = 0; i <= nA; ++i)
		{
			for (int j = 0; j <= nB; ++j)
			{
				double val = smax[i][j] + sA;
				if (i < nA && val > smax[i + 1][j])
				{
					smax[i + 1][j] = val;
				}
				if (i < nA && val < smin[i + 1][j])
				{
					smin[i + 1][j] = val;
				}
				val = smin[i][j] + sA;
				if (i < nA && val > smax[i + 1][j])
				{
					smax[i + 1][j] = val;
				}
				if (i < nA && val < smin[i + 1][j])
				{
					smin[i + 1][j] = val;
				}
				val = smax[i][j] * sB;
				if (j < nB && val > smax[i][j + 1])
				{
					smax[i][j + 1] = val;
				}
				if (j < nB && val < smin[i][j + 1])
				{
					smin[i][j + 1] = val;
				}
				val = smin[i][j] * sB;
				if (j < nB && val > smax[i][j + 1])
				{
					smax[i][j + 1] = val;
				}
				if (j < nB && val < smin[i][j + 1])
				{
					smin[i][j + 1] = val;
				}
			}
		}
		return smax[nA][nB] > smin[nA][nB] ? smax[nA][nB] : smin[nA][nB];
	}
};