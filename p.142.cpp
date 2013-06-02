#include <iostream>
#include <string>
using namespace std;
int cards[4] = {
	0b0000000111111110,
	0b0001111000011110,
	0b0110011001100110,
	0b1010101010101010
};

class NumberMagicEasy {
	public:
	int theNumber(string answer){
		int n = 0b1111111111111110;		
		for(int i=0; i<4; i++){
			char a = answer[i];
			int m = cards[i];
			if(a == 'Y'){
				n &= m;
			}else{
				n &= ~m;
			}
		}

		bool b = false;
		int r = 16;
		for(int i=1; i<=15; i++){
			if( n & (1 << i) ){
				r = i;
				if(b){
					cout << "error" << endl;
				}
				b = true;
			}
		}
		return r;
	}
};

int main(void){
	for(int i=0; i<4; i++){
		cout << cards[i] << endl;
	}

	NumberMagicEasy o = NumberMagicEasy(); 
	cout << o.theNumber("YNYY") << endl;
	cout << o.theNumber("YNNN") << endl;
	cout << o.theNumber("NNNN") << endl;
	cout << o.theNumber("YYYY") << endl;
	cout << o.theNumber("NYNY") << endl;
	return 0;
}
