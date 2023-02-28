#include <bits/stdc++.h>
using namespace std;

int vis[10001];
vector<string> answer;

bool DFS(string cur, vector<vector<string>> &tickets, int used_cnt) {
    if(used_cnt == tickets.size()) return true; // final end condition
    
    int num_tickets = tickets.size();
    
    for(int i=0; i<num_tickets; i++) {
        if(tickets[i][0] == cur && vis[i] == 0) {
            vis[i] = 1;
            answer.push_back(tickets[i][1]);
            bool check = DFS(tickets[i][1], tickets, used_cnt + 1);
            if(check) return true;
            
            vis[i] = 0;
            answer.pop_back();
        }
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    answer.push_back("ICN");
    
    sort(tickets.begin(), tickets.end());
    
    DFS("ICN", tickets, 0);

    return answer;
}