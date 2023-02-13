#include <bits/stdc++.h>
using namespace std;
int vis[201];

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0;i<n;i++) {
        if(vis[i] != 0) continue;
        answer++;
        queue<int> q;
        q.push(i);
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for(int j=0;j<n;j++) {
                if(computers[cur][j] != 1 || vis[j] != 0) continue;
                vis[j] = 1;
                q.push(j);
            } 
        }
        
    }
    return answer;
}