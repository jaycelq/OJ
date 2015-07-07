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

bool isUpperCase(char x) {
    return x >= 'A' && x <= 'Z';
}

char tolowerchar(char x) {
    if(x >= 'A' && x <= 'Z')
        return x - 'A' + 'a';
    else
        return x;
}

int main(int argc, const char * argv[]) {

    int T;
    
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        string str;
        cin >> str;
        
        long long j = 0;
        long long result = 0;
        while(j < str.length()) {
            char start = tolowerchar(str[j]);
            long long distance = 0;
            
            while(str[j] == start || start == tolowerchar(str[j])) {
                if(isUpperCase(str[j]))
                    distance += 2;
                else
                    distance += 1;
                
                j++;
            }
            
            result += (start - 'a' + 1) * distance * distance;
        }
        
        cout << result << endl;
    }
    
    return 0;
}
