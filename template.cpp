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

/* end of template */

/* Test */
int main(void){
	int x[3] = { 1, 2, -1 };
	vector<int> v(x, x+3);
	L::show(v);

	int max_value = *std::max_element(v.begin(), v.end());
	P(max_value);
	int i;
	string s0("10");
	TOI(s0, i); P(i);

	double f;
	string s1("10.232");
	TOD(s1, f); P(f);
	PF("%lf\n", f);

	map<string, int> m;
	m["hoge"] = 100;
	m["hige"] = 200;
	M::find(m, string("hoge"));

	vector<pair<string, int> > p = M::toList(m);
	PL::show(p);

	stable_sort(p.begin(), p.end(), PL::comp_by_value<string, int>);
	PL::show(p);

	vector<pair<int, string> > r = PL::flip(p);
	PL::show(r);
	PL::show(PL::flip(p));
	
	return 0;
}
