#include <iostream>
#include <cstring>
using namespace std;

int P[2000005];

string preProcess(string s) {
	int n = s.length();
	string ret;

	ret.push_back('$');
	for (int i = 0; i < n; ++i)
	{
		ret.push_back('#');
		ret.push_back(s[i]);
	}
	ret.push_back('#');
	ret.push_back('^');

	return ret;
}

int main(int argc, char const *argv[])
{
	int T;
	int n = 0;
	int id = 0, mx = 0;
	int res = 0;

	cin >> T;

	for (int i = 0; i < T; ++i)
	{
		string s,t;
		cin >> s;
		t = preProcess(s);
		n = t.length();

		memset(P, 0, sizeof(P));
		id = 0;
		mx = 0;
		res = 0;

		for(int j = 1; j < n; j++) {
			P[j] = mx > j ? min(mx - j - 1, P[2*id - j]) : 0;

			while (t[j + P[j] + 1] == t[j - P[j] - 1]) P[j]++;


			if(j + P[j] >= mx) {
				id = j;
				mx = j + P[j] + 1;
			}
		}

		for (int j = 0; j < n; ++j)
		{
			res = max(res, P[j]);
		}

		cout << res << endl;
	}
	system("read");
	return 0;
}