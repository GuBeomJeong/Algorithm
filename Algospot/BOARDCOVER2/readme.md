# BOARDCOVER2

블록의 왼쪽 위 (y,x)를 기준으로 상대위치를 저장한다. 4방향 회전한 것에 대해서도 모두 저장한다.
그 이후 모든 경우에 대해 전부 대입해보고 가장 많이 들어가는 경우의 수를 찾는다.

<b>이 때 최적화의 핵심은 남은 빈칸의 수가 현재 찾은 최적해 이하라면 탐색할 필요가 없고 탈출해야 한다는 점이다.  </b>

```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<pair<int, int>>> rotations;

int blockSize;

vector<string> rotate(vector<string>& arr) {
	vector<string> ret(arr[0].size(), string(arr.size(), ' '));
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[0].size(); j++) {
			ret[j][arr.size() - i - 1] = arr[i][j];
		}
	}

	return ret;
}

void generateRotations(vector<string> block) {
	rotations.clear();
	rotations.resize(4);
	for (int rot = 0; rot < 4; rot++) {
		int originY = -1;
		int originX = -1;

		for (int i = 0; i < block.size(); i++) {
			for (int j = 0; j < block[i].size(); j++) {
				if (block[i][j] == '#') {
					if (originY == -1) {
						originY = i;
						originX = j;
					}
				}

				rotations[rot].push_back({ i - originY,j - originX });
			}
		}

		block = rotate(block);
	}

	sort(rotations.begin(), rotations.end());
	rotations.erase(unique(rotations.begin(), rotations.end()), rotations.end());

	blockSize = rotations[0].size();
}

int boardH, boardW;
vector<string> board;

int covered[10][10];

int best;

bool set(int y, int x, const vector<pair<int, int>>& block, int delta) {

	if (delta == 1) {
		int ty = y;
		int tx = x;
		for (int i = 0; i < block.size(); i++) {
			if (covered[ty][tx] == 1) {
				delta = -1;
				break;
			}
			covered[ty][tx] = 1;
			ty += block[i].first;
			tx += block[i].second;
		}
	}

	if (delta == -1) {
		for (int i = 0; i < block.size(); i++) {
			covered[y][x] = 0;
		}

		return false;
	}

	return true;
	
}

void search(int placed) {
	int y = -1, x = -1;
	for (int i = 0; i < boardH; i++) {
		for (int j = 0; j < boardW; j++) {
			if (covered[i][j] == 0) {
				y = i;
				x = j;
				break;
			}
		}
		if (y != -1) {
			break;
		}
	}

	if (y == -1) {
		best = max(best, placed);
		return;
	}

	for (int i = 0; i < rotations.size(); i++) {
		if (set(y, x, rotations[i], 1)) {
			search(placed + 1);
		}
		set(y, x, rotations[i], -1);
	}

	covered[y][x] = 1;
	search(placed);
	covered[y][x] = 0;
}

int solve() {
	best = 0;

	for (int i = 0; i < boardH; i++) {
		for (int j = 0; j < boardW; j++) {
			covered[i][j] = (board[i][j] == '#' ? 1 : 0);
		}
	}

	search(0);
	return best;
}

int main() {

}
```
