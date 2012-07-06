#include <iostream>
#include <string>
#include <vector>

using namespace std;

double num[10] = {0, 1e8, 1e7, 1e6, 1e5, 1e4, 1e3, 1e2, 10.0, 1.0};

class TheLotteryBothDivs
{
	public:
		double find(vector<string> suffix)
		{
			int n = suffix.size();
			for (int i = 0; i < n; ++i)
			{
				reverse(suffix[i].begin(), suffix[i].end());
			}
			sort(suffix.begin(), suffix.end());
			for (int i = 0; i < n - 1; ++i)
			{
				if (suffix[i][0] != '$')
				{
					for (int j = i + 1; j < n; ++j)
					{
						if (suffix[j].find(suffix[i]) == 0)
						{
							suffix[j][0] = '$';
						}
						else
						{
							break;
						}
					}
				}
			}
			double ans = 0.0;
			for (int i = 0; i < n; ++i)
			{
				if (suffix[i][0] != '$')
				{
					ans += num[suffix[i].size()];
				}
			}
			return ans / 1e9;
		}
};