#include <vector>
using namespace std;
class Cryptography {
public:
	long long encrypt(vector<int> numbers)
	{
		int min = 1111;
		int j = 0;
		for(int i=0; i<numbers.size(); i++){
			if(numbers[i] < min){
				j = i;
				min = numbers[i];
			}
		}
		long long r = 1;
		for(int i=0; i<numbers.size(); i++){
			int n = numbers[i];
			if(i == j){
				n += 1;
			}
			r *= n;
		}
		return r;
	}
};

int main(void){
	return 0;
}
