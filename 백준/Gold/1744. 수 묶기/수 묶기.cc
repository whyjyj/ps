#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    /**
     * 0. 음수, 양수, 0 따로 입력받기 -> 절댓값 큰 것부터 봐야 한다
     * 1. 양수 내림차순 정렬, 음수 오름차순 정렬
     * 2. 0은 음수 홀수개일 때 하나 없애주는 용도로 사용한다. 음수 홀수개면 0을 음수 가장 절댓값 작은 애와 곱한다
     * 3. 음수 짝수개면 0 그냥 더한다.
     * 4. 양수의 경우 어차피 1 따로 핸들링 해야 해서 짝수개/홀수개 나누는 거 의미 없다.
     * 5. 음수는 -1 있으면 곱해서 양수 되는 게 이득이니까 -1 따로 핸들링 할 필요 없다.
     */

    int n, sum = 0;
    int num_zero = 0;
    vector<int> plus;
    vector<int> minus;

    cin >> n;

    for (size_t i = 0; i < n; i++)
    {
        int input_;
        cin >> input_;
        if (input_ > 0)
        {
            plus.emplace_back(input_);
        }
        else if (input_ == 0)
        {
            num_zero++;
        }
        else if (input_ < 0)
        {
            minus.emplace_back(input_);
        }
    }

    int size_plus = plus.size();
    int size_minus = minus.size();

    // edge case
    if (n == 1)
    {
        if (size_plus == 0 && size_minus == 0)
            sum = 0;
        else
            sum = (size_plus == 0) ? minus[0] : plus[0];
    }
    else
    {
        if (size_plus != 0)
            sort(plus.begin(), plus.end(), greater<>()); // 내림차순
        if (size_minus != 0)
            sort(minus.begin(), minus.end()); // 오름차순

        // 양수 처리
        if (size_plus == 1)
            sum += plus[0];
        else if (size_plus > 1)
        {
            for (size_t i = 1; i < size_plus; i++)
            {
                if (plus[i - 1] != 1 && plus[i] != 1)
                {
                    sum += (plus[i - 1] * plus[i]);
                    i++;
                    if (i == (size_plus - 1))
                    {
                        sum += plus[i];
                        break;
                    }
                }
                else if (plus[i - 1] == 1) // 뒤에도 1일 수밖에 없음
                {
                    sum += plus[i - 1];
                    sum += plus[i];
                    i++;
                    if (i == (size_plus - 1))
                    {
                        sum += plus[i];
                        break;
                    }
                }
                else if (plus[i] == 1)
                {
                    sum += plus[i - 1];
                    sum += plus[i];
                    i++;
                    if (i == (size_plus - 1))
                    {
                        sum += plus[i];
                        break;
                    }
                }
            }
        }

        // 음수 처리
        if (size_minus == 1 && num_zero == 0)
        {
            sum += minus[0];
        }

        else if (size_minus > 1)
        {
            if (size_minus % 2 == 0)
            {
                for (size_t i = 1; i < size_minus; i++)
                {
                    sum += (minus[i - 1] * minus[i]);
                    i++;
                }
            }
            else
            {
                for (size_t i = 1; i < size_minus; i++)
                {
                    sum += (minus[i - 1] * minus[i]);
                    i++;
                    if (i == (size_minus - 1))
                    {
                        if (num_zero == 0)
                            sum += minus[i];
                        break;
                    }
                }
            }
        }
    }

    cout << sum;
}