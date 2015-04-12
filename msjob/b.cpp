#include <iostream>
#include <map>
#include <list>
using namespace std;

map<int, list<int> > signal_module;
int* module_times;
map<int, list<int> > module_signal_pointer;

void send_signal(int signal){
    if(signal_module.find(signal) == signal_module.end())
        return;
    else {
        list<int> module_list = signal_module[signal];
        for (list < int > ::iterator module = module_list.begin(); module != module_list.end(); ++ module){
            module_times[*module]++;
            list<int> signal_list = module_signal_pointer[*module];
        
            for (list < int > ::iterator it = signal_list.begin(); it != signal_list.end(); ++ it){
                send_signal(*it);
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    int T = 0;
    int N = 0, M = 0;
    int signal = 0;
    int signal_num = 0;
    int* signal_org;
    
    cin >> T;
    for(int t = 0; t < T; t++){
        scanf("%d %d", &N, &M);
        signal_org = new int [M];
        module_times = new int [N];
        for (int m = 0; m < M; m++) {
            scanf("%d", &signal_org[m]);
        }
        
        for (int n = 0; n < N; n++) {
            module_times[n] = 0;
            scanf("%d", &signal);
            signal_module[signal].push_back(n);
            scanf("%d", &signal_num);
            for(int i = 0; i < signal_num; i++){
                scanf("%d", &signal);
                module_signal_pointer[n].push_back(signal);
            }
        }
        for(int i = 0; i < M; i++){
            send_signal(signal_org[i]);
        }
        for(int i = 0; i < N; i++){
            cout << module_times[i] << " ";
        }
        cout << endl;
        delete [] signal_org;
        delete [] module_times;
        module_signal_pointer.clear();
        signal_module.clear();
    }
    
    return 0;
}
