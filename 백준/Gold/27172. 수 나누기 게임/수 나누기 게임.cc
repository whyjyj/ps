#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int x[100001]; // 각 플레이어가 가지고 있는 카드 숫자
int score[100001];
int card[1000001]; // index 숫자 카드 가진 사람의 x 배열 index

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; // 플레이어 수
    fill(card, card + 1000001, -1);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        card[x[i]] = i;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 2 * x[i]; j <= 1000000; j += x[i])
        {
            // 배수인 카드 가지고 있는 사람 있으면 내 점수 +1, 상대 점수 -1
            if (card[j] != -1)
            {
                score[i]++;
                score[card[j]]--;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << score[i] << ' ';
    }
}