#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, cnt = 0;
    cin >> n;

    /**
     * 우선 O(N^2)으로 통과 못 한다.
     * input을 tuple로 받는다
     * 시작 시간, 끝 시간 순으로 정렬한다
     * 순차적으로 배정. 만약 배정된 애들 중에서 가장 먼저 끝나는 회의실보다 시작하는 시간 빠르다면 새로 배정, 끝나는 시간 priority queue에 넣기
     *
     * 앞에서부터 배정하면서 앞에 배정한 회의실들의 끝나는 시간보다 일찍 시작할 경우 회의실 하나씩 늘려야 한다
     * 근데 그러면 회의실 늘릴 때마다 그 회의실 언제 끝나는지 기록해둬야 하고 배정할 때마다 다 읽어봐야 하는데 그러면 N^2이다.
     * 아니면 끝나는 시간만 priority queue에 저장해뒀다가 그거아고 계속 비교해서 배정, 새 회의실 배정 반복하면 되려나?
     * 일단 무조건 먼저 끝나는 회의실에 대기중인 애들 중에서 먼저 시작하는 애들 넣어야 하는 건 확정이고(안 그러면 시간 낭비가 생기지)
     *
     */

    vector<pair<int, int>> input_;
    priority_queue<int, vector<int>, greater<int>> end_time;

    pair<int, int> input;
    for (size_t i = 0; i < n; i++)
    {
        cin >> input.first >> input.second;
        input_.emplace_back(input.first, input.second);
    }

    sort(input_.begin(), input_.end());

    int len = input_.size();
    for (size_t i = 0; i < len; i++)
    {
        int start_time = input_[i].first;
        if (end_time.empty() || start_time < end_time.top())
        {
            // 배정된 회의실 사용 끝나는 시각이 모두 새 회의 시작 시간보다 늦어서 새로 배정해야 하는 경우
            cnt++;                           // 회의실 새로 배정
            end_time.push(input_[i].second); // 회의 끝나는 시각 pq에 추가
        }
        else
        {
            // 기존 먼저 끝나는 회의 끝나면 시작할 수 있는 경우
            end_time.pop();
            end_time.push(input_[i].second);
        }
    }
    cout << cnt;
}