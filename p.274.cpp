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

/* for testing */
#define mk_vector(name, type, ...) \
	const int n = sizeof( (type[]){__VA_ARGS__} ) / sizeof( type );\
	type ___name___[n] = {__VA_ARGS__};\
	vector<type> name(___name___, ___name___ + n);

typedef long long ll;

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

bool visited[50] = {false};
int connect[50] = {0};
bool t[50][50] = {false};
int nr_grp = 0; 
int nr_free = 0;

class HamiltonPath {
int N, M;

	public:
	int countPaths(vector<string> roads)
	{
		N = roads.size();
		M = roads[0].size();
		// P(N); P(M);

		REP(i, N) { REP(j, M) {
			if(roads[i][j] == 'Y'){
				t[i][j] = true;
			}
		}}

		REP(i, N){ 
			int cnt = 0;
			REP(j, M) { 
				if(t[i][j]){
					if(++cnt > 2){
						return 0;
					}
				}
			}
			// P(cnt);
			connect[i] = cnt;
		}
		// REP(i, N) P(connect[i]);

		REP(i, N){
			P("---");
			P(i)
			P(connect[i]);
			if(connect[i] == 0){
				visited[i] = true;
				nr_free++;
			}else if(connect[i] == 1 && !visited[i]){
				// P(i);
				nr_grp++;
				dfs(i);
			}
		}
		P("***");
		P(nr_grp);
		P(nr_free);

		long long sum = 1;
		long long mod = 10000007;

		REP(i, N){ P(visited[i]); }
		REP(i, N){
			if(! visited[i]) {
				P("not visited");
				return 0;
			}
		}

		REP(i, nr_grp + nr_free){
			sum = sum * (i+1) % mod;
		}

		REP(i, nr_grp){
			sum = sum * 2 % mod;
		}

		return (int) sum;
	}

	void dfs(int i){
		P(i);
		visited[i] = true;
		REP(j, M){
			if(t[i][j] && !visited[j]) dfs(j);
		}
	}
};

int main(void)
{
	HamiltonPath h = HamiltonPath();	
	// mk_vector(r, string, "NYY", "YNY", "YYN");
	mk_vector(r, string, "NNNNNY", "NNNNYN", "NNNNYN", "NNNNNN", "NYYNNN", "YNNNNN");
	L::show(r);
	P(h.countPaths(r));

	return 0;
}
