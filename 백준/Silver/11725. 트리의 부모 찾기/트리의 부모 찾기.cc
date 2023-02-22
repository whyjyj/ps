#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
int p[100001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;

  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  stack<int> s;
  s.push(1);
  while (!s.empty()) {
    int cur = s.top();
    s.pop();

    for (int nxt : adj[cur]) {
      if (p[cur] == nxt)
        continue;
      p[nxt] = cur;
      s.push(nxt);
    }
  }

  for (int i = 2; i <= n; i++) {
    cout << p[i] << '\n';
  }
}