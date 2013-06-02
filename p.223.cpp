#include <iostream>
using namespace std;

class ColorfulBoxesAndBalls {
	public:
	int getMaximum(int numRed, int numBlue, int onlyRed, int onlyBlue, int bothColors)
	{
		int scoreA, scoreB, N, M;
		if(numRed < numBlue){
			scoreA = onlyRed;
			scoreB = onlyBlue;
			N = numRed;
			M = numBlue;
		}else{
			scoreA = onlyBlue;
			scoreB = onlyRed;
			N = numBlue;
			M = numRed;
		}

		int *dp = new int[N + 1];

		int i;
		for(i=0; i<=N; i++){
			int a, b, c;	

			a = scoreA * i;
			b = scoreB * (M - (N-i));
			c = bothColors * 2 * (N-i);

			dp[i] = a + b + c;
		}

		int r = -99999;
		for(i=0; i<=N; i++){
			r = max(dp[i], r);	
		}

		return r;
	}
};

int main(void){
	ColorfulBoxesAndBalls c = ColorfulBoxesAndBalls();

	cout << c.getMaximum(2, 3, 100, 400, 200) << endl;
	cout << c.getMaximum(1, 4, 20, -30, -10) << endl;
	cout << c.getMaximum(9, 1, -1, -10, 4) << endl;

	cout << c.getMaximum(100, 100, -1, -10, 4) << endl;

	return 0;
}
