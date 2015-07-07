//
//  main.cpp
//  bop_1
//
//  Created by Li Qiang on 15/4/17.
//  Copyright (c) 2015年 Li Qiang. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>
using namespace std;

int MONTH_DATE[] = {31,29,31,30,31,30,31,31,30,31,30,31};

map<string, int> months {
    { "January", 0 },
    { "February", 1 },
    { "March", 2 },
    { "April", 3 },
    { "May", 4 },
    { "June", 5 },
    { "July", 6 },
    { "August", 7 },
    { "September", 8 },
    { "October", 9 },
    { "November", 10 },
    { "December", 11 }
};

bool is_leap_year(long long year) {
    bool result = false;
    
    if (year%100 == 0 && year%400 == 0)
        result = true;
    else if(year%100 != 0 && year % 4 == 0)
        result = true;
    
    return result;
}

int dayinyear(int month, int date) {
    int result = 0;
    for (int i = 0; i < month; i++){
        result += MONTH_DATE[i];
    }
    result += date;
    return result;
}

int main(int argc, const char * argv[]) {
    int T = 0;
    
    int start_month, start_date, end_month, end_date;
    long long start_year, end_year;
    string buffer;
    
    
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        cin >> buffer;
        start_month = months[buffer];
        
        getline(cin, buffer, ',');
        start_date = stoi(buffer);
        cin >> start_year;

        cin >> buffer;
        end_month = months[buffer];
        getline(cin, buffer, ',');
        end_date = stoi(buffer);
        cin >> end_year;
        
        long long leap_year_num = 0;
        
        if(start_year == end_year) {
            if(is_leap_year(start_year)) {
                int startdayofyear = dayinyear(start_month, start_date);
                int enddayofyear = dayinyear(end_month, end_date);
                if(startdayofyear <= 60 && enddayofyear >= 60) {
                    cout << "Case #" << i+1 << ": " << 1 << endl;
                }
                else {
                    cout << "Case #" << i+1 << ": " << 0 << endl;
                }
            }
            else
                cout << "Case #" << i+1 << ": " << 0 << endl;
        }
        else {
            long tmp_year = end_year - 1;
            leap_year_num = tmp_year / 4 - start_year / 4 - (tmp_year / 100 - start_year / 100)
                        + (tmp_year / 400 - start_year / 400);
            if(is_leap_year(start_year)) {
                int startdayofyear = dayinyear(start_month, start_date);
                if(startdayofyear <= 60) {
                    leap_year_num++;
                }
            }
            if(is_leap_year(end_year)) {
                int startdayofyear = dayinyear(end_month, end_date);
                if(startdayofyear >= 60) {
                    leap_year_num++;
                }
            }
            cout << "Case #" << i+1 << ": " << leap_year_num << endl;
        }
    }
    
    return 0;
}
