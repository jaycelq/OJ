#include <fstream>
using namespace std;

int main() {
	int T = 0;
	int Smax = 0;
	int result = 0;
	string info;
	ifstream fin("A-large.in");
	ofstream fout("A-large.out");

	fin >> T;

	for (int t = 0; t < T; t++) {
		fin >> Smax;

		fin >> info;

		int current = 0;

		for (int i = 0; i <= Smax; i++) {
			if(current < i) {
				result += i - current;
				current += i - current;
			}
			current += info[i] - '0';
		}

		fout << "Case #" << t + 1 << ": " << result << endl;

		result = 0;
	}

	fout.close();

	return 0;
}