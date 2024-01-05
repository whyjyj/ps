#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int NOT_VISITED = 0;
const int VISITED = 1;
const int IN_CYCLE = 2;
const int NOT_IN_CYCLE = 3;

int adj[100003];
int state[100003];
int n;

void task(int start)
{
    int cur = start;

    while (true)
    {
        state[cur] = VISITED;

        // next
        cur = adj[cur];
        // case 1
        // cur까지 모두 NOT_IN_CYCLE 처리
        if (state[cur] == IN_CYCLE || state[cur] == NOT_IN_CYCLE)
        {
            cur = start;
            while (state[cur] == VISITED)
            {
                state[cur] = NOT_IN_CYCLE;
                cur = adj[cur];
            }
            return;
        }
        // case 2
        else if (state[cur] == VISITED && cur != start)
        {
            while (state[cur] != IN_CYCLE)
            {
                state[cur] = IN_CYCLE;
                cur = adj[cur];
            }

            cur = start;
            while (state[cur] != IN_CYCLE)
            {
                state[cur] = NOT_IN_CYCLE;
                cur = adj[cur];
            }
            return;
        }
        // case 3
        else if (state[cur] == VISITED && cur == start)
        {
            while (state[cur] == VISITED)
            {
                state[cur] = IN_CYCLE;
                cur = adj[cur];
            }
            return;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int cnt = 0;
        cin >> n;

        for (size_t i = 1; i <= n; i++)
        {
            cin >> adj[i];
            state[i] = NOT_VISITED;
        }

        for (size_t i = 1; i <= n; i++)
        {
            if (state[i] == NOT_VISITED)
                task(i);
        }

        for (size_t i = 1; i <= n; i++)
        {
            if (state[i] != IN_CYCLE)
                cnt++;
        }

        cout << cnt << '\n';
    }
}