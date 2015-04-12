#include <iostream>
using namespace std;

char grid[3][3];

bool x_win = false, o_win = false;

int num_x = 0;
int num_o = 0;

int S;

void judge() {
	for(int i = 0; i < 3; i++) {
		if(grid[i][0] == grid[i][1] && grid[i][0] == grid[i][2]) {
			if(grid[i][0] == 'X')
				x_win = true;
			else if(grid[i][0] == 'O')
				o_win = true;
		}

		if(grid[0][i] == grid[1][i] && grid[0][i] == grid[2][i]) {
			if(grid[0][i] == 'X')
				x_win = true;
			else if(grid[0][i] == 'O')
				o_win = true;
		}
	}

	if(grid[0][0] == grid[1][1] && grid[0][0] == grid[2][2]) {
		if(grid[0][0] == 'X')
			x_win = true;
		else if(grid[0][0] == 'O')
			o_win = true;
	}

	if(grid[0][2] == grid[1][1] && grid[0][2] == grid[2][0]) {
		if(grid[0][2] == 'X')
			x_win = true;
		else if(grid[0][2] == 'O')
			o_win = true;
	}

}

void next_step() {
	char next;

	if(num_x == num_o)
		next = 'X';
	else
		next = 'O';

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if(grid[i][j] == '_') {
				grid[i][j] = next;
				judge();
				if(x_win || o_win) {
					cout << "Next win" << endl;
					return;
				}
				else {
					grid[i][j] = '_';
				}
			}
		}
	}

	cout << "Next cannot win" << endl;
}

int main(int argc, char const *argv[])
{
	cin >> S;

	for(int n = 0; n < S; n++){
		num_x = 0;
		num_o = 0;
		x_win = false;
		o_win = false;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> grid[i][j];
				if(grid[i][j] == 'O') 
					num_o++;
				else if(grid[i][j] == 'X') 
					num_x++;
			}
		}

		if(num_x < num_o || num_x > num_o + 1) {
			cout << "Invalid" << endl;
			continue;
		}

		judge();

		if(x_win) {
			if(o_win || num_x == num_o) {
				cout << "Invalid" << endl;
				continue;
			}
			else {
				cout << "X win" << endl;
				continue;
			}
		}
		else {
			if(o_win && num_x == num_o + 1) {
				cout << "Invalid" << endl;
				continue;
			}
			else if(o_win){
				cout << "O win" << endl;
				continue;
			}
		}

		if(num_x + num_o == 9) {
			cout << "Draw" << endl;
			continue;
		}

		next_step();

	}

	return 0;
}