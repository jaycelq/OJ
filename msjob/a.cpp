//
//  main.cpp
//  msjob
//
//  Created by Li Qiang on 15/4/2.
//  Copyright (c) 2015年 Li Qiang. All rights reserved.
//

#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int cr = 0, cy = 0, cb = 0;
    int x = 0, y = 0, z = 0;
    unsigned long max = 0, length = 0;
    string input;
    
    cin >> x >> y >> z;
    cin >> input;
    length = input.length();
    
    
    for(int i = 0; i < input.length(); i++){
        switch (input[i]) {
            case 'R':
                cr++;
                break;
            case 'Y':
                cy++;
                break;
            case 'B':
                cb++;
                break;
            default:
                break;
        }
        if((abs(cr-cy)==x&&abs(cr-cb)==y&&abs(cy-cb)==z)||
           (abs(cr-cy)==x&&abs(cr-cb)==z&&abs(cy-cb)==y)||
           (abs(cr-cy)==y&&abs(cr-cb)==z&&abs(cy-cb)==x)||
           (abs(cr-cy)==y&&abs(cr-cb)==x&&abs(cy-cb)==z)||
           (abs(cr-cy)==z&&abs(cr-cb)==x&&abs(cy-cb)==y)||
           (abs(cr-cy)==z&&abs(cr-cb)==y&&abs(cy-cb)==x)){
            int tmp = cr + cb + cy;
            length -= tmp;
            max = tmp > max ? tmp : max;
            cr = 0;
            cb = 0;
            cy = 0;
        }
    }
    
    max = length > max ? length : max;
    
    cout << max;
    
    return 0;
}
