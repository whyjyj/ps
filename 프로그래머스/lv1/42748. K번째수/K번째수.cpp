#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(vector<int> command: commands) {
        vector<int> bak;
        int i = command[0];
        int j = command[1];
        int k = command[2];
        
        for(int p=i-1;p<j;p++) {
            bak.push_back(array[p]);
        }
        sort(bak.begin(), bak.end());
        answer.push_back(bak[k-1]);
    }
    return answer;
}