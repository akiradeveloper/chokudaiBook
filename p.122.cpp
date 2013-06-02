#include <iostream>
using namespace std;
bool grid[100][100] = {false}; // global data.
int vx[] = {1, -1, 0, 0};
int vy[] = {0, 0, 1, -1};
double prob[4];
class CrazyBot {
public:
	double getProbability(int n, int east, int west, int south, int north)
	{
		prob[0] = east / 100.0; // NOTE not 100. 
		prob[1] = west / 100.0;
		prob[2] = south / 100.0;
		prob[3] = north / 100.0;
		return visit(50, 50, n);
	}
	
	double visit(int x, int y, int n)
	{
		// cout << "hoge" << endl;
		if(grid[x][y]) return 0;
		if(n==0) return 1;

		grid[x][y] = true; // write

		double r = 0;
		for(int i=0; i<4; i++){
			r += visit(x + vx[i], y + vy[i], n-1) * prob[i];
		}

		grid[x][y] = false; // undo

		return r;
	}
};

int main(void){
	CrazyBot b = CrazyBot();
	cout << b.getProbability(3, 50, 50, 0, 0) << endl;
	cout << b.getProbability(14, 25, 25, 25, 25) << endl;
	return 0;
}
