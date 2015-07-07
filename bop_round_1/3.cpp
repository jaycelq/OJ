//
//  main.cpp
//  bop_round_1
//
//  Created by Li Qiang on 15/4/25.
//  Copyright (c) 2015年 Li Qiang. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

int number[1001];

bool IsPrime(int number)
{	// Given:   num an integer > 1
    // Returns: true if num is prime
    // 			false otherwise.
    
    int i;
    
    for (i=2; i<= (int)sqrt(number); i++)
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    
    return true;	
}

struct MAX_CLIQUE {
    static const int N=1000;
    
    bool G[N][N];
    int n, Max[N], Alt[N][N], ans;
    
    bool DFS(int cur, int tot) {
        if(cur==0) {
            if(tot>ans) {
                ans=tot;
                return 1;
            }
            return 0;
        }
        for(int i=0; i<cur; i++) {
            if(cur-i+tot<=ans) return 0;
            int u=Alt[tot][i];
            if(Max[u]+tot<=ans) return 0;
            int nxt=0;
            for(int j=i+1; j<cur; j++)
                if(G[u][Alt[tot][j]]) Alt[tot+1][nxt++]=Alt[tot][j];
            if(DFS(nxt, tot+1)) return 1;
        }
        return 0;
    }
    
    int MaxClique() {
        ans=0, memset(Max, 0, sizeof Max);
        for(int i=n-1; i>=0; i--) {
            int cur=0;
            for(int j=i+1; j<n; j++) if(G[i][j]) Alt[1][cur++]=j;
            DFS(cur, 1);
            Max[i]=ans;
        }
        return ans;
    }
};



int main() {
    int T;
    MAX_CLIQUE fuck;
    
    cin >> T;
    
    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;
        for (int n = 0; n < N; n++) {
            cin >> number[n];
        }
        fuck.n = N;
        for(int i=0; i<fuck.n; i++){
            for(int j=i; j<fuck.n; j++){
                int big = max(number[i], number[j]);
                int little = min(number[i], number[j]);
                if (big % little != 0){
                    fuck.G[i][j] = true;
                    fuck.G[j][i] = true;
                }
                else if (big / little < 2){
                    fuck.G[i][j] = true;
                    fuck.G[j][i] = true;
                }
                else if(IsPrime(big/little)) {
                    fuck.G[i][j] = false;
                    fuck.G[j][i] = false;
                }
                else {
                    fuck.G[i][j] = true;
                    fuck.G[j][i] = true;
                }
            }
        }
        
        cout << "Case #" << t+1 << ": " << fuck.MaxClique() << endl;
    }
    
    return 0;
}

