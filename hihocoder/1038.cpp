#include <iostream>
using namespace std;

int c[501] = {0};
int w[501] = {0};
long long f[100001] = {0};
int V = 0;
int N = 0;

void ZeroOnePack(int cost, int value) {
    for (int i = V; i >= cost; i--) {
            f[i] = max(f[i-1], f[i-cost]+value);
    }
}

int main() {
    cin >> N;
    cin >> V;
    
    for(int i = 1; i <= N; i++) {
        cin >> c[i] >> w[i];
    }
    
    for (int i = 0; i <= V; i++) {
        f[i] = 0;
    }

    for(int i = 1; i <= N; i++)
        ZeroOnePack(c[i], w[i]);

    cout << f[V] << endl;

    return 0;
}
