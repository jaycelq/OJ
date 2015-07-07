#include <fstream>
using namespace std;

int m_amouts[10000];

int main() {
    int T = 0;
    int m_num = 0;

    ifstream fin("A-large.in");
    ofstream fout("A-large.out");
    
    fin >> T;
    
    for (int t = 0; t < T; t++) {
        fin >> m_num;
        
        int result_1 = 0, result_2 = 0;
        int diff_max = 0;
        
        for (int i = 0; i < m_num; i++) {
            fin >> m_amouts[i];
            if(i > 0 && m_amouts[i] < m_amouts[i-1]) {
                int diff = m_amouts[i-1] - m_amouts[i];
                result_1 += diff;
                diff_max = max(diff, diff_max);
            }
        }
        
        for (int i = 0; i < m_num-1; i++) {
            if(m_amouts[i] >= diff_max) {
                result_2 += diff_max;
            }
            else {
                result_2 += m_amouts[i];
            }
        }
        
        fout << "Case #" << t + 1 << ": " << result_1 << " " << result_2 << endl;
    }
    
    fout.close();
    
    return 0;
}