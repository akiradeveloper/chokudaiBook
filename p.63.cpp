#include <iostream>
#include <vector>
#include <map>
using namespace std;

class InterestingParty {
public:
	int bestInvitation(vector<string> first, vector<string> second)
	{
		int N = first.size();
		map<string, int> cardi;
		for(int i; i<N; i++){
			cardi[first[i]]++;
			if(cardi[first[i]] == cardi[second[i]]){
				continue;
			}
			cardi[second[i]]++;
		}
		int max = 0;
		map<string, int>::iterator it = cardi.begin();
		while(it != cardi.end()){
			int count = it->second;
			if(count > max){	
				max = count;
			}
			it++;
		}
		return max;
	}
};

int main(void){
	return 0;
}
