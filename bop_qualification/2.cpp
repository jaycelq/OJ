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

int palindrome_table[1000][1000] = {0};

int main() {
    int T = 0;
    unsigned long length = 0;
    
    cin >> T;
    string str;
    
    for (int i = 0; i < T; i++) {
        cin >> str;
        length = str.length();

        memset(palindrome_table, 0, sizeof(palindrome_table));
        
        for (int j = 0; j < length; j++) {
            palindrome_table[j][j] = 1;
        }
        
        for (int j = 1; j < length; j++) {
            for (int k = 0; k + j < length; k++) {
                if(str[k] == str[k+j])
                    palindrome_table[k][k+j] = (palindrome_table[k][k+j-1] + palindrome_table[k+1][k+j] + 1)%100007;
                else
                    palindrome_table[k][k+j] = (palindrome_table[k+1][k+j] + palindrome_table[k][k+j-1] - palindrome_table[k+1][k+j-1])%100007;
            }
        }
        
        cout << "Case #" << i+1 << ": " << palindrome_table[0][length - 1] << endl;
    }

    system("read");
    return 0;
}