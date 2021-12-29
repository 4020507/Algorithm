#include <iostream>
#include <string.h>
using namespace std;

int circle[51][51];
bool removed[51][51];
int x, d, k; //x번 원판을 d방향으로 k칸 회전, 0은 시계 1은 반시계
    //원판에 인접한 수를 모두 지우고 평균을 구하자
int N, M, T;

void shift()
{
    if (d == 1)
    {
        int temp;
        for (int X = x;X <= N;X += x)
        {
            for (int j = 0;j < k;j++)
            {
                temp = circle[X][0];

                for (int t = 0;t < M - 1;t++)
                {
                    circle[X][t] = circle[X][t + 1];
                }
                circle[X][M - 1] = temp;
            }
        }
        
    }
    else if (d == 0)
    {
        int temp;

        for (int X = x;X <= N; X += x)
        {
            for (int j = 0;j < k;j++)
            {
                temp = circle[X][M - 1];

                for (int t = M - 1;t > 0;t--)
                {
                    circle[X][t] = circle[X][t - 1];
                }
                circle[X][0] = temp;
            }
        }
        
    }
}

bool isRemove()
{
    memset(removed, false, sizeof(removed));
    bool check = false;
    for (int i = 1;i <= N;i++)
    {
        for (int j = 0;j < M;j++)
        {
            if (circle[i][j] != 0)
            {
                if (circle[i][j] == circle[i - 1][j] || circle[i][j] == circle[i + 1][j])
                {
                    check = true;
                    removed[i][j] = true;
                    continue;
                }

                if (j != 0 && j != M - 1)
                {
                    if (circle[i][j] == circle[i][j + 1] || circle[i][j] == circle[i][j - 1])
                    {
                        check = true;
                        removed[i][j] = true;
                    }
                }
                else if (j == 0)
                {
                    if (circle[i][j] == circle[i][j + 1] || circle[i][j] == circle[i][M - 1])
                    {
                        check = true;
                        removed[i][j] = true;
                    }
                }
                else if (j == M - 1)
                {
                    if (circle[i][j] == circle[i][j - 1] || circle[i][j] == circle[i][0])
                    {
                        check = true;
                        removed[i][j] = true;
                    }
                }
            }
        }
    }

    return check;
}

void removeNum()
{
    for (int i = 1;i <= N;i++)
    {
        for (int j = 0;j < M;j++)
        {
            if (removed[i][j])
                circle[i][j] = 0;
        }
    }
}

void modifyNum()
{
    float sum = 0;
    float cnt = 0;
    for (int i = 1;i <= N;i++)
    {
        for (int j = 0;j < M;j++)
        {
            if (circle[i][j] != 0)
            {
                sum += circle[i][j];
                cnt++;
            }
                
        }
    }

    sum /= cnt;

    for (int i = 1;i <= N;i++)
    {
        for (int j = 0;j < M;j++)
        {
            if (circle[i][j] != 0)
            {
                if (circle[i][j] > sum)
                    circle[i][j]--;
                else if (circle[i][j] < sum)
                    circle[i][j]++;
            }
        }
    }
}
int main() {
    
    cin >> N >> M >> T;
    memset(circle, 0, sizeof(circle));

    for (int i = 1;i <= N;i++)
    {
        for (int j = 0;j < M;j++)
        {
            cin >> circle[i][j];
        }
    }

    for (int i = 0;i < T;i++)
    {
        cin >> x >> d >> k;

        shift();

        if (isRemove())
        {
            removeNum();
        }
        else
            modifyNum();
    }

    int ans = 0;

    for (int i = 1;i <= N;i++)
        for (int j = 0;j < M;j++)
            ans += circle[i][j];

    cout << ans;

    return 0;
}
