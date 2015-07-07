#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

long long b_minites[1000] = {0};

class event {
public:
    int b_num;
    long long event_time;
    
    event(int b_num, long long time) {
        this->b_num = b_num;
        this->event_time = time;
    }
    
    bool operator > (const event& d) const
    {
        bool result = false;
        
        if(this->event_time > d.event_time)
            result = true;
        else if(this->event_time == d.event_time && this->b_num > d.b_num)
            result = true;
        
        return result;
    }
    
};


int main() {
    int T = 0;
    int B = 0, N = 0;
    long long event_time = 0;

    //ifstream fin("test.in");
    //ofstream fout("test.out");
    
    cin >> T;
    
    for (int t = 0; t < T; t++) {
        cin >> B >> N;
        
        vector<event> event_vector;
        
        for (int i = 0; i < B; i++) {
            cin >> event_time;
            b_minites[i] = event_time;
            event event(i+1, event_time);
            event_vector.push_back(event);
        }
        
        make_heap(event_vector.begin(), event_vector.end(),greater<event>());
        
        for(int i = 1; i <= N; i++) {
            event e = event_vector.front();
            
            cout << "event " << e.b_num << " " << e.event_time << endl;
            
            pop_heap(event_vector.begin(), event_vector.end(),greater<event>());
            event_vector.pop_back();
            
            event e2(e.b_num, e.event_time + b_minites[e.b_num - 1]);
            event_vector.push_back(e2);
            push_heap(event_vector.begin(), event_vector.end(),greater<event>());

        }
        
        cout << "Case #" << t + 1 << ": " <<  event_vector.front().b_num << endl;
    }
    
    //fout.close();
    
    return 0;
}