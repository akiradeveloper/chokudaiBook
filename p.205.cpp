#include <vector>
#include <iostream>
using namespace std;

int moveType[16][2] = {
	{0,1},{1,0},{0,-1},{-1,0},
	{1,1},{-1,-1},{1,-1},{-1,1},
	{1,2},{2,1},{2,-1},{1,-2},
	{-1,-2},{-2,-1},{-2,1},{-1,2},
};

class ChessMetrics {

	public:
	long long howMany(int size, vector<int> start, vector<int> end, int numMoves)
	{
		int countMap[size][size];
		int i, j;
		for(i=0; i<size; i++){ 
			for(j=0; j<size; j++) { 
				countMap[i][j] = 0;
			} 
		}

		bool latestLoc[size][size];
		latestLoc[start[0]][start[1]] = true;

		for(i=0; i<numMoves; i++){
			int x, y;
			for(x=0; x<size; x++){
				for(y=0; y<size; y++){
					if(latestLoc[x][y]){
						// BUG
						latestLoc[x][y] = false;
						for(j=0; j<16; j++){
							int _x, _y;
							_x = x + moveType[j][0];
							_y = y + moveType[j][1];
							bool b = (_x >= size || _x < 0 || _y >= size || _y < 0);
							if(! b){
								latestLoc[_x][_y] = true;
								countMap[_x][_y]++;
							}
						}
					}
				}
			}
		}

		return countMap[end[0]][end[1]];
	}

	public:
	long long howMany2(int size, vector<int> start, vector<int> end, int numMoves)
	{
		long long countMap[100][100][55] = {0};
		countMap[start[0]][start[1]][0] = 1;

		int i, j, x, y;
		for(i=1; i<=numMoves; i++){
			for(x=0; x<size; x++){
				for(y=0; y<size; y++){
					for(j=0; j<16; j++){
						int _x = x + moveType[j][0];
						int _y = y + moveType[j][1];
						bool b = (_x >= size || _x < 0 || _y >= size || _y < 0);
						if(b) continue;
						countMap[_x][_y][i] += countMap[x][y][i-1];					
					}
				}
			}
		}
		return countMap[end[0]][end[1]][numMoves];
	}
};

int main(void)
{
	ChessMetrics o = ChessMetrics();
	vector<int> a, b;
	a.push_back(0); a.push_back(0);
	b.push_back(0); b.push_back(99);
	cout << o.howMany2(100, a, b, 50) << endl;

	return 0;
}
