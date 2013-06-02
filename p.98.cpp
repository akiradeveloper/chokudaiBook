#include <vector>
#include <string>
using namespace std;
class Solver {
	public:
	vector<string> friends;
	int N;
	Solver(vector<string> friends){
		friends = friends;
		N = friends.size();
	}

	bool indirectFriend(int a, int b){
		string s_a = friends.at(a);
		string s_b = friends.at(b);
		for(int i; i<N; i++){
			if(i == b){
				continue;
			}
			if(s_a[i] == 'Y' && s_b[i] == 'Y'){
				return true;
			}
		}
		return false;
	}

	int solve(){
		int counts[N];
		for(int i=0; i<N; i++){
			counts[i] = 0;
		}
		for(int a=0; a<N; a++){
			string arr = friends.at(a);
			for(int b; b<N; b++){
				if(arr[b] == 'Y'){ 
					counts[a]++; 
					continue;
				}
				if(indirectFriend(a, b)){
					counts[a]++;
					continue;
				}
			}
		}
		int max = 0;
		for(int i=0; i<N; i++){
			if(max < counts[i]){
				max = counts[i];
			}
		}
		return max;
	}
};

class FriendScore {
	public:
	int highestScore(vector<string> friends)
	{
		return Solver(friends).solve();	
	}
};

int main(void){ return 0; }
