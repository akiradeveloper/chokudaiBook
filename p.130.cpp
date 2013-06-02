/* FUCKing Code */
/* And Wrong */

#include <string>
#include <vector>
using namespace std;

int N, M, L;
vector<string> maze;
vector<int> moveRow, moveCol;

int max_ = 0;

bool visited[100][100] = {true};
int nr_remained;

class MazeMaker {
public:
	void visit(int x, int y, int n){
		if(x < 0 || y < 0 || x >= N || y >= M) return; // out bound
		if(visited[x][y]) return; // visited before
		if(nr_remained == 0) return; // nowhere to search.

		visited[x][y] = true;
		nr_remained--;

		if(n > max_){
			max_ = n;
		}
		for(int i=0; i<L; i++){
			visit(x + moveRow.at(i), y + moveCol.at(i), n+1);
		}

		visited[x][y] = false;
		nr_remained++;
	}

	int longestPath(vector<string> maze,
			int startRow,
			int startCol,
			vector<int> moveRow,
			vector<int> moveCol)
	{
		N = maze.size();
		M = maze.at(0).size();	
		L = moveRow.size();
		for(int i=0; i<N; i++){
			string s = maze.at(0);
			for(int j=0; j<M; j++){
				if(s[j] == '.'){
					visited[i][j] = false;
					nr_remained++;
				}
			}
		}

		visit(startRow, startCol, 0);
		
		if(nr_remained){
			// There is some point that Jim can not reach.
			return -1;
		}

		return max_;
	}
};

int main(void)
{
	return 0;
}
