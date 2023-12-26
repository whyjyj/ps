#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // only 2, 5
    int n;
    int cnt = 0;
    cin >> n;

    if (n == 1 || n == 3)
    {
        cout << -1;
        return 0;
    }
    // 일단 5로 쭉 가보고 나머지가 2의 배수 아니면 다시 5 돌려주는 식으로
    // 근데 5로 한번에 가는 게 맞겠지? 그치 굳이 1번씩 뺄 이유는 없어
    // 그러면 5, 2로 거슬러 줄 수 없는 경우는 뭘까? -> n이 0인지 아닌지

    int mok = n / 5;
    n -= (5 * mok);
    cnt += mok;
    if (n % 2 == 0)
    {
        mok = n / 2;
        cnt += mok;
        n -= (2 * mok);
    }
    else
    {
        cnt--;
        n += 5; // 이제 다시 짝수

        mok = n / 2;
        cnt += mok;
        n -= (2 * mok);
    }

    if (n == 0)
        cout << cnt;
    else
        cout << -1;
}