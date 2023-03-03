#include <bits/stdc++.h>
using namespace std;

bool arr[103][103]; // true = 외각
int dist[103][103];

int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    
    int charY = 2 * characterY;
    int charX = 2 * characterX;
    int endY = 2 * itemY;
    int endX = 2 * itemX;
    
    
    for(vector<int> rec: rectangle) {
        // 테두리 포함 b/c 겹치는 부분 밀고 다시 테두리 긋기 위해
        for(int i=2*rec[1];i<=2*rec[3];i++) {
            for(int j=2*rec[0];j<=2*rec[2];j++) {
                arr[i][j] = true;
            }
        }
    }
    
    // 테두리 제외하고 지우기 -> 입출력 1번 보면 일단 다 그리고 그 다음에 다 지우는 게 맞음
    for(vector<int> rec: rectangle) {
        for(int i=2*rec[1]+1; i<2*rec[3]; i++) {
            for(int j=2*rec[0]+1; j<2*rec[2]; j++) {
                arr[i][j] = false;
            }
        }
    }
    
   
    fill(&dist[0][0], &dist[102][103], -1);
    
    
    
    // 테두리 따라서 bfs
    queue<pair<int,int>> q;
    q.push({charY, charX});
    dist[charY][charX] = 0;
    
    while(!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        if(cur.first == endY && cur.second == endX) break;
        for(int i=0;i<4;i++) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];
            if(ny >= 102 || ny < 0 || nx >= 102 || nx < 0) continue;
            if(arr[ny][nx] && dist[ny][nx] == -1) {
                dist[ny][nx] = dist[cur.first][cur.second] + 1;
                q.push({ny,nx});
            }
        }
    }
    
    answer = dist[endY][endX] / 2;
    return answer;
}