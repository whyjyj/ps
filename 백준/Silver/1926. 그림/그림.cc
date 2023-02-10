#include <bits/stdc++.h>
using namespace std;

int mp[500][500];
int vis[500][500];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0 , -1, 0};

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      cin >> mp[i][j];
    }
  }


  queue<pair<int, int> > q;
  int max_area = -1;
  int num=0;

  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      if(mp[i][j] != 1 || vis[i][j] == 1) continue;
      pair<int, int> cur  = {i,j};
      vis[i][j] = 1;
      num++;
      q.push(cur);
      int area = 0;

      while(!q.empty()) {
        cur = q.front();
        q.pop();
        for(int k=0;k<4;k++) {
          int nx = dx[k] + cur.first;
          int ny = dy[k] + cur.second;
          if(nx>=n || nx<0 || ny>=m || ny<0) continue;
          if(mp[nx][ny] == 1 && vis[nx][ny] != 1) {
            vis[nx][ny] = 1;
            q.push({nx,ny});
            area++;
          }
        }
      } // while
      if(area>=max_area) max_area = area;
    }
  }

  cout << num << "\n" << max_area + 1;
}