//
//  main.cpp
//  baidujob
//
//  Created by Li Qiang on 15/4/19.
//  Copyright (c) 2015年 Li Qiang. All rights reserved.
//

#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int height[1000] = {0};


int main(int argc, const char * argv[]) {

    int T;
    
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        int num = 0;
        
        cin >> num;
        
        height[0] = 0;
        for (int i = 1; i <= num; i++) {
            cin >> height[i];
        }
        height[num + 1] = 0;
        long long result = 0;
        for (int i = 1; i <= num + 1; i++) {
            result += 2 * abs(height[i] - height[i-1]);
        }
        
        cout << result << endl;
        
    }
    
    return 0;
}
