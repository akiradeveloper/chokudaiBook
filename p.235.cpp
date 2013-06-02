#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <memory>
#include <cstring>
#include <stack>
#include <queue>
#include <assert.h>
using namespace std;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>

vector<string> split(string str, string delim)
{
	vector<string> result;
	int cutAt;
	while( (cutAt = str.find_first_of(delim)) != str.npos )
	{
		if(cutAt > 0){
			result.push_back(str.substr(0, cutAt));
		}
		str = str.substr(cutAt + 1);
	}
	if(str.length() > 0){
		result.push_back(str);		
	}
	return result;
}

#define IT(i, size) for(i=0; i<(size); i++)
#define SIGN(n) (n==0?0:(n>0 ? 1 : -1))
#define ABS(n) ((n)<0?(-(n)):(n))
#define P(x) { cout << x << endl; }
#define PF(...) printf(__VA_ARGS__)
#define TOI(s, var) sscanf((s).c_str(), "%d", &(var))
#define TOD(s, var) sscanf((s).c_str(), "%lf", &(var))

class StockHistory {
	public:
	int maximumEarnings(
			int initialInvestment,
			int monthlyContribution,
			vector<string> stockPrices)
	{
		vector<string> s = split(stockPrices[0], " ");
		P("split");
		int M = s.size();
		int N = stockPrices.size();
		int i, j;
		int stockTab[N][M];
		double rateTab[N-1][M];
		double maxRateTab[N-1][M];
		int maxRateIdx[N-1][M];

		P("start");
		IT(i, N){
			string s = stockPrices[i];			
			vector<string> ss = split(s, " ");
			IT(j, M){
				TOI(ss[j], stockTab[i][j]);
			}
		}
		IT(i, N) { IT(j, M) P(stockTab[i][j]) }

		IT(i, N-1) { IT(j, M) rateTab[i][j] = stockTab[N-1][j] / ((double) stockTab[i][j]); }
		IT(i, N-1) { IT(j, M) P(rateTab[i][j]) }

		double curMax[M];
		int curIdx[M];
		IT(j, M){ curMax[j] = 0; curIdx[j] = N; };
		for(i=N-1; i>=0; i--){
			IT(j, M){
				double r = rateTab[i][j];
				if(r > curMax[j]){
					curMax[j] = r;
					curIdx[j] = i;
				}
				maxRateTab[i][j] = curMax[j];
				maxRateIdx[i][j] = curIdx[j];
			}
		}
		P("ratetab");
		IT(i, N-1) { IT(j, M) P(maxRateTab[i][j]); }
		P("rateidx");
		IT(i, N-1) { IT(j, M) P(maxRateIdx[i][j]); }

		double dMax;
		int iMax;
		double money = initialInvestment;
		double inMoney = money + (N-1) * monthlyContribution;
		double lastMoney = 0;
		IT(i, N-1){
			iMax = N-2;
			dMax = 0;
			IT(j, M){
				P("max");
				if(maxRateTab[i][j] > dMax){
					P("change");
					dMax = maxRateTab[i][j];
					iMax = maxRateIdx[i][j];
					P(dMax);
				}
			}

			// jump to iMax
			money += (iMax - i) * monthlyContribution; 
			if(dMax > 1){
				P("buy");
				P(iMax);
				P(money);
				// P(dMax);
				// P(lastMoney);
				lastMoney += dMax * money;
				money = 0;
			}

			i = iMax;
			money += monthlyContribution;
		}
		lastMoney += money;
		P(inMoney);
		P(lastMoney);

		return (lastMoney - inMoney);
	}
};


int main(void){
	StockHistory s = StockHistory();
	string arr[2] = {"10 20 30", "15 24 32"};
	vector<string> ss(arr, arr+2);
	P(s.maximumEarnings(1000, 0, ss));


	P("P2");
	string arr2[8] = {"40 50 60", "37 48 55", "100 48 50", "105 48 47", "110 50 52", "110 50 52", "110 51 54", "109 49 53"};
	vector<string> ss2(arr2, arr2+8);
	P(s.maximumEarnings(100, 20, ss2));
	return 0;
}
