#include <iostream>
using namespace std;

char grid[100][100];

int N, M, S;

class pos {
public:
	int row;
	int column;

	bool equal(pos a) {
		return row == a.row && column == a.column;
	}

	pos(int row, int column) {
		this->row = row;
		this->column = column;
	}

	pos() {

	}
};

pos box_pos_org, player_pos_org, goal_pos;

bool has_box(pos & box_pos, int row, int column) {
	return box_pos.row == row && box_pos.column == column;
}

int calculate() {
  return 1;
}

int main(int argc, char const *argv[])
{
	cin >> N >> M >> S;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> grid[i][j];
			if(grid[i][j] == '1') {
				player_pos_org.row = i;
				player_pos_org.column = j;
			}
			else if(grid[i][j] == '2') {
				goal_pos.row = i;
				goal_pos.column = j;
			}
			else if(grid[i][j] == '3') {
				box_pos_org.row = i;
				box_pos_org.column = j;
			}
		}
	}
	
	for(int i = 0; i < S; i++) {
		int length = 0;
		string test_case;

		cin >> length;
		cin >> test_case;

		pos player_pos = player_pos_org;
		pos box_pos = box_pos_org;

		if(goal_pos.equal(box_pos)) {
				cout << "YES" << endl;
				break;
		}

		for(int j = 0; j < length; j++) {
			switch(test_case[j]) {
				case 'd':
					if(player_pos.row + 1 >= M)
						break;
					else if(has_box(box_pos, player_pos.row+1, player_pos.column)) {
						if(player_pos.row + 2 >= M || grid[player_pos.row+2][player_pos.column] == '4') 
							break;
						else {
							player_pos.row += 1;
							box_pos.row += 1;
						}
					}
					else {
						if(grid[player_pos.row+1][player_pos.column] == '4')
							break;
						else 
							player_pos.row += 1;
					}
					break;
				case 'u':
					if(player_pos.row - 1 < 0)
						break;
					else if(has_box(box_pos, player_pos.row-1, player_pos.column)) {
						if(player_pos.row - 2 < 0 || grid[player_pos.row-2][player_pos.column] == '4') 
							break;
						else {
							player_pos.row -= 1;
							box_pos.row -= 1;
						}
					}
					else {
						if(grid[player_pos.row-1][player_pos.column] == '4')
							break;
						else
							player_pos.row -= 1;
					}
					break;
				case 'l':
					if(player_pos.column - 1 < 0)
						break;
					else if(has_box(box_pos, player_pos.row, player_pos.column-1)) {
						if(player_pos.column - 2 < 0 || grid[player_pos.row][player_pos.column-2] == '4') 
							break;
						else {
							player_pos.column -= 1;
							box_pos.column -= 1;
						}
					}
					else {
						if(grid[player_pos.row][player_pos.column-1] == '4')
							break;
						else
							player_pos.column -= 1;
					}
					break;
				case 'r':
					if(player_pos.column + 1 >= N)
						break;
					else if(has_box(box_pos, player_pos.row, player_pos.column+1)) {
						if(player_pos.column + 2 >= N || grid[player_pos.row][player_pos.column+2] == '4') 
							break;
						else {
							player_pos.column += 1;
							box_pos.column += 1;
						}
					}
					else {
						if(grid[player_pos.row][player_pos.column+1] == '4')
							break;
						else
							player_pos.column += 1;
					}
					break;
				default:
					break;
			}
			if(goal_pos.equal(box_pos)) {
				cout << "YES" << endl;
				break;
			}
		}
		if(goal_pos.equal(box_pos) == false)
			cout << "NO" << endl;
	}
	return 0;
}
