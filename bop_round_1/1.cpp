//
//  main.cpp
//  bop_round_1
//
//  Created by Li Qiang on 15/4/25.
//  Copyright (c) 2015年 Li Qiang. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <set>
using namespace std;

class Node{
public:
    int color;
    set<int> neighbor;

    Node():color(0),neighbor() {
    }
};

Node nodes[100001];

int main(int argc, const char * argv[]) {

    int T;
    
    cin >> T;
    
    for (int t = 0; t < T; t++) {
        int N = 0;
        int result = 1;
        cin >> N;
        for (int n = 1; n <= N; n++) {
            nodes[n].color = 0;
            nodes[n].neighbor.clear();
        }
        
        for (int n = 1; n <= N - 1; n++) {
            int n1 = 0, n2 = 0;
            cin >> n1 >> n2;
            nodes[n1].neighbor.insert(n2);
            nodes[n2].neighbor.insert(n1);
        }
        
        int Q = 0;
        cin >> Q;
        
        cout << "Case #" << t+1 << ":" << endl;
        for (int q = 0; q < Q; q++) {
            int opcode = 0;
            cin >> opcode;
            switch (opcode) {
                case 1:
                    cout << result <<endl;
                    break;
                case 2:
                    int num, color;
                    cin >> num >> color;
                    set<int> & myset = nodes[num].neighbor;
                    int my_color = nodes[num].color;
                    
                    if (color == my_color)
                        break;
                    
                    for (set<int>::iterator it=myset.begin(); it!=myset.end(); ++it) {
                        if (nodes[*it].color == color)
                            result--;
                        else if (nodes[*it].color == my_color)
                            result++;
                    }
                    nodes[num].color = color;
                    break;
            }
        }
        
    }
    
    return 0;
}
