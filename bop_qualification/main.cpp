//
//  main.cpp
//  bop_1
//
//  Created by Li Qiang on 15/4/17.
//  Copyright (c) 2015年 Li Qiang. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;

class point{
public:
    long long row;
    long long column;
};

point user[1000];
point company[100];

int main() {
    int T = 0;
    long long N = 0, M = 0, A = 0, B = 0;
    
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        cin >> N >> M >> A >> B;
        
        for(int j = 0; j < A; j++) {
            cin >> user[j].row;
            cin >> user[j].column;
        }
        
        for (int j = 0; j < B; j++) {
            cin >> company[j].row;
            cin >> company[j].column;
        }
        
        long long min_row_distance = N * N;
        for (int j = 1; j <= N; j++) {
            long long distance = 0;
            for(int k = 0; k < A; k++) {
                distance += (user[k].row - j) * (user[k].row - j);
            }
            long long min_mhd_distance = max(M, N);
            for (int k = 0; k < B; k++) {
                long long current_mhd_distance = abs(company[k].row - j);
                if( current_mhd_distance < min_mhd_distance)
                    min_mhd_distance = current_mhd_distance;
            }
            distance += min_mhd_distance;
            if(distance < min_row_distance)
                min_row_distance = distance;
        }
        
        long long min_column_distance = M * M;
        for (int j = 1; j <= M; j++) {
            long long distance = 0;
            for(int k = 0; k < A; k++) {
                distance += (user[k].column - j) * (user[k].column - j);
            }
            long long min_mhd_distance = max(M, N);
            for (int k = 0; k < B; k++) {
                long long current_mhd_distance = abs(company[k].column - j);
                if( current_mhd_distance < min_mhd_distance)
                    min_mhd_distance = current_mhd_distance;
            }
            distance += min_mhd_distance;
            if(distance < min_column_distance)
                min_column_distance = distance;
        }
        
        cout << "Case #" << i+1 << ": " << min_column_distance + min_row_distance << endl;
        
    }
    return 0;
}