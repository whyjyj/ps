#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Compare
{
    bool operator()(const std::pair<int, int> &a, const std::pair<int, int> &b)
    {
        return a > b; // 내림차순 정렬
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, cnt = 0;
    cin >> n >> k;

    vector<int> sched;
    vector<int> plug;
    sched.resize(k);
    plug.resize(n);

    for (size_t i = 0; i < k; i++)
    {
        cin >> sched[i];
    }

    /**
     * 플러그를 빼는 횟수를 최소화 -> 플러그 배열 값 교환 횟수 최소화
     * 우선 2초에다가 1 <= n,k <= 100이므로 n^4정도까지는 가능 -> 완전탐색도 고려할 것
     * 1. sched 순회하면서 빈 자리 있으면 넣고(처음 n개) 빈 자리없으면
     * 2. sched에서 "뒤에 n개" 살펴서 없으면 그거 빼고 아니면 최소(?)로 사용되는 거 빼기(경계 처리 주의)
     * - 만약 다음 n개의 sched에 대해서 사용되는 횟수가 같다면? -> 가장 늦게 사용되는 애 빼야 하나? 아니면 뒤에 더 살펴봐야 하나?
     * - 가장 늦게 사용되는 애를 뽑아야 한다. 왜냐면 얘가 플러그 자리 차지하고 있으면 또 다른 놈 뽑던가하는 일이 일어나서 최적해에서 멀어지기 때문
     * - plug에 이미 있는 애들에 대해서 각각이 뒤에 n개 내에 얼마나 사용되는지 각각 구해야 한다.
     * - plug 각 pos에 대해서 flag 배열 관리해야 하나? -> 그럴 거 같은데?
     * 가장 적게 쓰이는 걸 뽑아야 하나 가장 늦게 쓰이는 걸 뽑아야 하나?
     * 가장 적게 쓰이는 걸 뽑으면 worst 쓰이는 횟수만큼 교체 필요
     * 가장 늦게 쓰이는 걸 뽑으면
     */

    // 처음 n개 꽂기 -> 동일한 거 있을 때 주의

    for (int sched_idx = 0, plug_idx = 0; plug_idx < n; sched_idx++)
    {
        int exist_flag = false;
        for (int j = 0; j < sched_idx; j++)
        {
            if (plug[j] == sched[sched_idx])
            {
                exist_flag = true;
            }
        }
        if (!exist_flag)
            plug[plug_idx++] = sched[sched_idx];
    }

    // n+1번째부터는 안 꽂혀져 있으면 위의 방식대로 원래꺼 뽑고 꽂기
    for (int i = n; i < k; i++)
    {
        // 1. 이미 꽂혀 있는지 체크
        bool exist_flag = false;
        for (int j = 0; j < n; j++)
        {
            if (sched[i] == plug[j])
            {
                exist_flag = true;
                break;
            }
        }

        // 2. 꽂혀 있지 않은 경우에 대한 처리
        if (!exist_flag)
        {
            // 가장 늦게 사용되는 제품 뽑기
            // plug에 꽂힌 제품에 대해 다음으로 사용되는 시점 구하기
            vector<pair<int, int>> future;
            for (int target_idx = 0; target_idx < n; target_idx++)
            {
                bool found = false;
                for (int pos = i + 1; pos < k; pos++)
                    if (plug[target_idx] == sched[pos])
                    {
                        found = true;
                        future.emplace_back(pos, target_idx); // {idx in plug(pos), target}
                        break;
                    }
                // 꽂혀 있는데 더이상 사용되지 않는 경우
                // 그냥 바로 얘로 바꾸던가 아니면 INT_MAX 등으로 처리하고 뒤에서 처리하기
                if (!found)
                {
                    future.emplace_back(INT_MAX, target_idx);
                }
            }

            if (!future.empty())
            {
                // 내림차순 정렬
                sort(future.begin(), future.end(), Compare());

                // 가장 늦게 사용되는 제품 빼고 그 자리에 꽂기

                int min_idx = future[0].second;

                plug[min_idx] = sched[i];
                cnt++;
            }
            else
            {
                plug[0] = sched[i];
                cnt++;
            }
        }
    }
    cout << cnt;
}
