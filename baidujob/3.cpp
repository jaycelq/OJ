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

int w[1001]= {0};
int a[1001]= {0};
int v[1001][10001]={0};

int main ()
{
    int T = 0;
    
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        int C_min = 0, C_max = 0;
        int rest_num = 0;
        
        cin >> rest_num >> C_min >> C_max;
        
        int result = 0;
        for (int j = 0; j < rest_num; j++) {
            int meal_num = 0;
            cin >> meal_num;
            
            for (int k = 1; k <= meal_num; k++) {
                cin >> w[k] >> a[k];
            }
            
            for (int m=0; m<=meal_num; m++) v[m][0]=0;
            for (int n=0; n<=C_max; n++) v[0][n]=0;
            
            int max_joy = 0;
            int cash = 0;
            
            for(int m=1; m<=meal_num; m++)
                for(int n=1; n<=C_max; n++){
                    if(n < w[m]){
                        v[m][n]=v[m-1][n];
                    }
                    else{
                        v[m][n]=(v[m-1][n]>=v[m-1][n-w[m]]+a[m])?v[m-1][n]:v[m-1][n-w[m]]+a[m];
                        if(v[m][n] > max_joy) {
                            cash = n;
                            max_joy = v[m][n];
                        }
                    }
                    
                }

            if(cash >= C_min)
                result = result > v[meal_num][C_max] ? result : v[meal_num][C_max];
        
        }
        cout << result <<endl;
        
        
    }
    
    return 0;
}