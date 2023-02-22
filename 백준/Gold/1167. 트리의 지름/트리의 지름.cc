#include <bits/stdc++.h>
using namespace std;

// {v2, w}
vector<vector<pair<int, int>>> T;
int vis[100001];
int diameter = -1;
int endNode = -1;

void DFS(int start, int sum) {
    vis[start] = 1;
    // cout << start << "visited" << '\n';
    
    if(diameter<sum) {
        diameter = sum;
        endNode = start;
    }
    
    for(auto node:T[start]) {
        int target = node.first;
        int weight = node.second;
        if(!vis[target]) DFS(target, sum + weight);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    T.resize(n+1);
    
    while(n--) {
        int v1, v2, w;
        cin >> v1;
        while(1) {
            cin >> v2;
            if(v2 == -1) break;
            cin >> w;
            T[v1].push_back({v2,w});
        }
    }
    DFS(1,0);
    memset(vis, 0, sizeof(vis));
    DFS(endNode, 0);
    
    cout << diameter;

    return 0;
}