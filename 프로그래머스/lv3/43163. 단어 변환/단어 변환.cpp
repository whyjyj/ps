#include <bits/stdc++.h>
using namespace std;

int dist[52]; // 0 ~ 51 -> 51:begin

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
        
    auto p = find(words.begin(), words.end(), target);
    if(p == words.end()) return 0;
    
    int words_cnt = words.size();
    int words_len = words[0].length();
    
    queue< pair<int, string>> q;
    q.push({51, begin});
    
    // bfs
    while(!q.empty()) {
        int cur_idx = q.front().first;
        string cur = q.front().second; q.pop();
        if(cur == target) return dist[cur_idx];
        
        for(int i=0;i<words_cnt;i++) {

            int similar = 0;
            for(int j=0;j<words_len;j++) {
                if(cur[j] == words[i][j]) similar++;
            }
            
            if(similar >= words_len-1 && dist[i] == 0) {
                dist[i] = dist[cur_idx] + 1;
                q.push({i, words[i]});
            }
        } // for
    } // while
    
    
    return 0;
}