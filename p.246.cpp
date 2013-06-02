#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <memory>
#include <cstring>
#include <stack>
#include <queue>
#include <assert.h>
using namespace std;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>

namespace String {
vector<string> split(string str, string delim)
{
	vector<string> result;
	int cutAt;
	while( (cutAt = str.find_first_of(delim)) != str.npos )
	{
		if(cutAt > 0){
			result.push_back(str.substr(0, cutAt));
		}
		str = str.substr(cutAt + 1);
	}
	if(str.length() > 0){
		result.push_back(str);		
	}
	return result;
}
};

#define IT(i, size) for(i=0; i<(size); i++)
#define SIGN(n) (n==0?0:(n>0 ? 1 : -1))
#define ABS(n) ((n)<0?(-(n)):(n))
#define P(x) { cout << x << endl; }
#define PF(...) printf(__VA_ARGS__)
#define TOI(s, var) sscanf((s).c_str(), "%d", &(var))
#define TOD(s, var) sscanf((s).c_str(), "%lf", &(var))

namespace L { /* List */
template <typename T>
void show(const vector<T>& v)
{
	cout << "[";
	int i;
	IT(i, v.size() - 1){
		cout << v[i] << ", ";
	}
	cout << v[v.size() - 1] << "]" << endl;
}
};

namespace PL { /* Pair List */
template <typename K, typename V>
vector<pair<V, K> > flip(const vector<pair<K, V> >& v)
{
	vector<pair<V, K> > r;	
	int i;
	IT(i, v.size()){
		pair<K, V> p = v[i];
		r.push_back(make_pair(p.second, p.first));
	}
	return r;
}
template <typename K, typename V>
void show(const vector<pair<K, V> >& v)
{
	int i;
	cout << "[";
	IT(i, v.size() - 1){
		pair<K, V> p = v[i];
		cout << "(" << p.first << "," << p.second << "), ";
	}
	pair<K, V> last = v[v.size() - 1];
	cout << "(" << last.first << "," << last.second << ")]" << endl;
}

template <typename K, typename V>
bool comp_by_value(const pair<K, V>& p1, const pair<K, V>& p2)
{
	return p1.second < p2.second;
}
};

namespace M { /* Map */
template <typename K, typename V>
vector<pair<K, V> > toList(map<K, V>& m)
{
	vector<pair<K, V> > v;
	typename map<K, V>::iterator it;
	for(it = m.begin(); it != m.end(); ++it){
		v.push_back(make_pair(it->first, it->second));
	}
	return v;
}
template <typename K, typename V>
vector<pair<K, V> > find(map<K, V>& m, K key)
{
	vector<pair<K, V> > v;
	typename map<K, V>::iterator it = m.find(key);
	for(it = m.begin(); it != m.end(); ++it){
		v.push_back(make_pair(it->first, it->second));
	}
	P(v.size());
	return v;
}
}; // end of M

namespace S { /* Set */
};

class BatchSystem {
	public:
	vector<int> schedule(vector<int> duration, vector<string> user)
	{
		// Should use long long to avoid overflow
		map<string, int> m;	
		int N = duration.size();
		int i, j;
		IT(i, N){
			m[user[i]] = 0;
		}
		IT(i, N){
			m[user[i]] += duration[i];
		}
		vector<pair<string, int> > l = M::toList(m);
		sort(l.begin(), l.end(), PL::comp_by_value<string, int>);
		PL::show(l);
		vector<int> ans;

		IT(i, l.size()){
			pair<string, int> pa = l[i];
			string name = pa.first;
			P(name);
			IT(j, N){
				if(user[j] == name){
					ans.push_back(j);
				}
			}
		}
		L::show(ans);
		return ans;
	}
};

int main(void){
	BatchSystem b = BatchSystem();

	int _d1[4] =  {400, 100, 100, 100};
	vector<int> d1 = vector<int>(_d1, _d1+4);
	string _u1[4] =  {"D", "S", "S", "M"};
	vector<string> u1 = vector<string>(_u1, _u1+4);
	b.schedule(d1, u1);

	return 0;
}
