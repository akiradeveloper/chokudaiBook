#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <bitset>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <memory>
#include <utility>
#include <stack>
#include <queue>
#include <assert.h>
#include <climits>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <ctime>

using namespace std;

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

#define MP make_pair
#define ALL(v) v.begin(), v.end()
#define REP(i, n) for(unsigned long long i=0; i<(n); i++)
#define REP2(i, from, to) for(long long i=(from); i<=(to); i++)
#define SIGN(n) (n==0?0:(n>0 ? 1 : -1))
#define ABS(n) ((n)<0?(-(n)):(n))
#define P(x) { cout << x << endl; }
#define PF(...) printf(__VA_ARGS__)
#define TOI(s, var) sscanf((s).c_str(), "%d", &(var))
#define TOD(s, var) sscanf((s).c_str(), "%lf", &(var))
#define POW2(x) ((x) * (x))
#define IT(i, size) for(i=0; i<(size); i++) /* obsolete */

#define mk_vector(name, type, ...) \
	const int n = sizeof( (type[]){__VA_ARGS__} ) / sizeof( type );\
	type ___name___[n] = {__VA_ARGS__};\
	vector<type> name(___name___, ___name___ + n);

typedef long long ll;

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
	//int x[3] = { 1, 2, -1 };
	//vector<int> v(x, x+3);
	mk_vector(v, int, 1, 2, -1);
	//vector<int> v = {1,2,-1};	
	L::show(v);

	int max_value = *std::max_element(ALL(v));
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

	stable_sort(ALL(p), PL::comp_by_value<string, int>);
	PL::show(p);

	vector<pair<int, string> > r = PL::flip(p);
	PL::show(r);
	PL::show(PL::flip(p));

	REP(k, 3) P(k);
	REP2(z, -1, 2) P(z);
	
	return 0;
}
