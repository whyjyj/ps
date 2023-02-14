#include <bits/stdc++.h>
using namespace std;

int dist[100002];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  queue<int> q;
  cin >> n >> k;

  fill( dist, dist + 100001, -1);
  dist[n] = 0;
  q.push(n);

  while(!q.empty()) {
    int cur = q.front();
    q.pop();

    for(int new_: {cur-1, cur+1, cur*2}) {
      if(new_<0 || new_>100000) continue;
      if(dist[new_] != -1) continue;
      dist[new_] = dist[cur] + 1;
      q.push(new_);
    }
  }
  cout << dist[k];
  
  

  
}