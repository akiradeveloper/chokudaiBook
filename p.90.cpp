// ceil
// clone copy()
// slice string#substr(start, len)
//
// BUG
#include <string>
#include <iostream>
using namespace std;
class ThePalindrome {
	public:
	int find(string s)
	{
		//cout << string::npos << endl;
		string a = "ak";
		string b = "ar";
		//cout << a.rfind(b.c_str()) << endl;
		int N = s.size();	
		int ans = 2*N - 1;
		for(int n=N-2; n>0; n--){
			int len = (N-1) - n;
			string mirror = s.substr(n+1, len);
			// cout << mirror << endl;
			string rev = string(mirror.rbegin(), mirror.rend());
			// cout << rev << endl;
			string ss = s.substr(0, n);
			cout << "ss :" << ss << endl;
			cout << "rev:" << rev << endl;
			// XXX
			// cout << ss.rfind(rev) << endl;
			int pos = ss.rfind(rev);	
			cout << "pos :" << pos << endl;
			if(pos == string::npos){
				continue;
			}
	 		bool ok = ( ss.rfind(rev) == (n-len) );	// XXX
			if(ok){
				cout << "OK" << endl;
				ans = 2*n+1;
			}
		}
		return ans;
	}
};

int main(void){ 
	ThePalindrome p = ThePalindrome();
	cout << "answer: " << p.find("akira") << endl;
	cout << "answer: " << p.find("ak") << endl;
	cout << "answer: " << p.find("abcdcb") << endl;
	return 0;
}
