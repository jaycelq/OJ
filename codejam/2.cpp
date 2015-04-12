#include <fstream>
#include <map>
using namespace std;

int main() {
    map<int, int> frequency_map;
    int T = 0, length = 0;
    int pi = 0;
    
    ifstream fin("B-small-attempt5.in");
    ofstream fout("B-small-attempt5_right.out");
    
    fin >> T;
    
    for(int t = 0; t < T; t++) {
        fin >> length;
        
        for(int i = 0; i < length; i++) {
            fin >> pi;
            if (frequency_map.count(pi)>0)
                frequency_map[pi]++;
            else
                frequency_map[pi] = 1;
        }
        
        int max_pi = frequency_map.rbegin()->first;
        int result = max_pi;
        
        for (int i = 2; i <= max_pi; i++) {
            int tmp_result = i;
            
            for(map<int, int>::reverse_iterator rit = frequency_map.rbegin(); rit != frequency_map.rend(); rit++){
                if(rit->first <= i) {
                    break;
                }
                else {
                    tmp_result += (rit->first - 1) / i * rit->second;
                }
            }
            
            result = min(tmp_result, result);
        }
        
        frequency_map.clear();
        fout <<"Case #" << t + 1 << ": " << result << endl;
    }
}
