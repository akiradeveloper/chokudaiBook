#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <memory>
#include <cstring>
#include <cmath>
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

#define POW2(x) ((x) * (x))

class CirclesCountry {
	public:
	int N;
	int levelTab[51];		
	bool inclusionTab[51][51];
	vector<int> mX, mY, mR;

	// ! includes 2
	bool includeC(int X1, int Y1, int R1, int X2, int Y2, int R2)
	{
		bool apart = sqrt( POW2(X1-X2) + POW2(Y1-Y2) ) > (R1 + R2);
		return !apart && (R1 >= R2);
	}

	bool include(int X, int Y, int R, int x, int y)
	{
		return sqrt( POW2(X-x) + POW2(Y-y) ) < R;
	}

	int circleID(int x, int y)
	{
		int level = -1;
		int ID = -1;
		int i;
		IT(i, N){
			if(include(mX[i], mY[i], mR[i], x, y)){
				if(levelTab[i] > level){
					level = levelTab[i];
					ID = i;
				}
			}
		}
		assert(ID != -1);
		return ID;
	}

	int leastBorders(vector<int> X, vector<int> Y, vector<int> R, int x1, int y1, int x2, int y2)
	{

		/*
		 * Nested Set Model.
		 */

		int i, j;

		mX=X; mY=Y; mR=R;

		mX.push_back(5000);
		mY.push_back(5000);
		mR.push_back(100000);
		N = mX.size();

		IT(i, N) { IT(j, N) inclusionTab[i][j] = false; }

		P("start set inclusion tab");
		IT(i, N){
			IT(j, N){
				bool in = includeC(mX[j], mY[j], mR[j], mX[i], mY[i], mR[i]);
				if(in){
					if(i==8){
						P(i); P(j);
					}
					inclusionTab[i][j] = true;
				}
			}
		}
		P("set inclusion tab");

		IT(i, N){
			int n = 0;
			IT(j, N){
				if(inclusionTab[i][j]) n++;
			}
			levelTab[i] = n;
			P(n);
		}
		P("set level tab");

		// deeepst circle the point is included.
		int ID1 = circleID(x1, y1);
		int ID2 = circleID(x2, y2);	
		P(ID1); P(ID2);
		P(levelTab[ID1]);
		P(levelTab[ID2]);

		vector<int> commonParent;
		IT(j, N){
			if(inclusionTab[ID1][j] && inclusionTab[ID2][j]){
				commonParent.push_back(j);
			}
		}
		L::show(commonParent);

		// search the deepest parent 
		int ID = -1; 
		int level = -1;
		IT(i, commonParent.size()){
			int id = commonParent[i];
			if(levelTab[id] > level){
				level = levelTab[id];
				ID = id;
			}
		}
		assert(ID != -1);
		P(level);

		return (levelTab[ID1] - level) + (levelTab[ID2] - level);
	}
};

int main(void){

	CirclesCountry c = CirclesCountry();

	P(c.include(0, 0, 3, 1, 0));
	P(c.include(0, 0, 3, 3, 2));

	int _X[8] = {-3, 2, 2, 0, -4, 12, 12, 12}; vector<int> X(_X, _X+8);
	int _Y[8] = {-1, 2, 3, 1, 5, 1, 1, 1}; vector<int> Y(_Y, _Y+8);
	int _R[8] = {1, 3, 1, 7, 1, 1, 2, 3}; vector<int> R(_R, _R+8);

	P(c.leastBorders(X, Y, R, 2, 3, 13, 2));

	return 0;
}
