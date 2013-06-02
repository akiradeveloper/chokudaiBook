#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CorporationSalary {
	int N;
	long long Salaries[100];
	vector<string> Relations;

	public:
	long long calcSalaries(int i)
	{
		string s = Relations.at(i);
		bool b = true;
		for(int j=0; j<N; j++)
		{
			if(s[j] == 'Y'){
				b = false;
			}
		}
		if(b) return 1; /* all N */

		if(Salaries[i]) return Salaries[i];
		long long t = 0;
		for(int j=0; j<N; j++){
			if(s[j] == 'Y'){
				t += calcSalaries(j);
			}
		}
		if(! Salaries[i]){ 
			if(Salaries[i] > t){
				cout << Salaries[i] << " > " << t << endl;
			}
			Salaries[i] = t;
		}

		return t;
	}
	long long totalSalary(vector<string> relations)
	{
		/* Init */
		Relations = relations;
		N = Relations.size();
		for(int i=0; i<100; i++){
			Salaries[i] = 0;
		}

		for(int i=0; i<N; i++){
			Salaries[i] = calcSalaries(i);
		}
		
		long long r = 0;
		for(int i=0; i<N; i++){
			r += Salaries[i];
		}
		return r;
	}
};

int main(void)
{
	CorporationSalary o = CorporationSalary();
	vector<string> i0, i1;
	i0.push_back("N");
	cout << o.totalSalary(i0) << endl;

	i1.push_back("NNNNNN");
	i1.push_back("YNYNNY");
	i1.push_back("YNNNNY");
	i1.push_back("NNNNNN");
	i1.push_back("YNYNNN");
	i1.push_back("YNNYNN");
	cout << o.totalSalary(i1) << endl;

	return 0;
}
