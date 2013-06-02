// FAILED. I am not good for DP now.
//
#include <iostream>
#include <vector>
using namespace std;
class BadNeighbors {
	int i, j, k;
	int N;
	public:
	int maxDonations(vector<int> donations)
	{
		int ans = 0;
		N = donations.size();
		int *dp = new int[N];

		// start from 0
		for(i=0; i<N; i++) dp[i] = 0;
		for(i=0; i<N-1; i++){
			dp[i] = donations[i];
			if(i > 0) dp[i] = max( dp[i], dp[i-1] );
			if(i > 1) dp[i] = max( dp[i], dp[i-2] + donations[i] );
			ans = max( ans, dp[i] );
		}

//		for(i=0; i<N-1; i++){
//			dp[i] = donations[i+1];
//			if(i > 0) dp[i] = max( dp[i], dp[i-1] );
//			if(i > 1) dp[i] = max( dp[i], dp[i-2] + donations[i+1] );
//			ans = max( ans, dp[i] );
//		}

		// start from 1
		for(i=0; i<N; i++) dp[i] = 0;
		for(i=1; i<N; i++){
			dp[i] = donations[i];
			if(i > 1) dp[i] = max( dp[i], dp[i-1] );
			if(i > 2) dp[i] = max( dp[i], dp[i-2] + donations[i] );
			ans = max( ans, dp[i] );
		}
		delete [] dp;
		return ans;
	}
};

int main(void){
	BadNeighbors b = BadNeighbors();
	vector<int> i0;
	int xs[10] = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 };
	for(int i=0; i<10; i++){
		i0.push_back( xs[i] );
	}
	cout << b.maxDonations(i0) << endl;
	return 0;
}
