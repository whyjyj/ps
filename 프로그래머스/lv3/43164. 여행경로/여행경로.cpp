#include <bits/stdc++.h>
using namespace std;

int vis[10001];
vector<string> answer;


bool DFS(string cur, vector<vector<string>> &tickets, int cnt) {
    int ticket_num = tickets.size();
    if(cnt == ticket_num) {
        answer.push_back(cur);
        return true;
    }
        
    
    for(int i=0;i<ticket_num;i++) {
        if(tickets[i][0] == cur && vis[i] == 0) {
            vis[i] = 1;
            answer.push_back(tickets[i][0]);
            bool check = DFS(tickets[i][1], tickets, cnt + 1);
            if(check) return true;
            vis[i] = 0;
            answer.pop_back();
        }
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    
    DFS("ICN", tickets, 0);
    
    return answer;
}