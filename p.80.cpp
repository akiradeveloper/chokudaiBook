#include <vector>
using namespace std;
class InterestingDigits {
public:
	vector<int> digits(int base)
	{
		vector<int> r;
		for(int n=2; n<base; n++){
			bool ok = true;
			for(int i=0; i<=9; i++){
				for(int j=0; j<=9; j++){
					for(int k=0; k<=9; k++){
						if( 
							(i * base * base + j * base + k) % n == 0 &&
							(i + j + k) % n != 0)
						{
							ok = false;
							break;
						}
					}
				}
			}
			if(ok) r.push_back(n);
		}
		return r;
	}
};

int main(void){ return 0; }
