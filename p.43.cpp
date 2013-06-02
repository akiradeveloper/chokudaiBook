#include <iostream>
#include <vector>

using namespace std;

class KiwiJuiceEasy {
public:
	vector<int> thePouring(
			vector<int> capacities,
			vector<int> bottles,
			vector<int> fromId,
			vector<int> toId)
	{
		int N = capacities.size();
		int M = fromId.size();

		int i;
		for(i=0; i<M; i++){
			int from = fromId[i];
			int to = toId[i];

			int pour = bottles[from];
			if(capacities[to] > pour){
				pour = capacities[to] - bottles[to];
			}

			bottles[from] -= pour;
			bottles[to] += pour;
		}

		return bottles;
	}
};

int main(void){
	return 0;
}
