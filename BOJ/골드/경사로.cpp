#include <iostream>

using namespace std;

int N, L;
int map[100][100];

int main() {
    
    cin >> N >> L;

    for (int i = 0;i < N;i++)
        for (int j = 0;j < N;j++)
            cin >> map[i][j];

    int ans = 0;
    int L_same, R_same;
    for (int i = 0;i < N;i++)
    {
        L_same = 1;
        R_same = -1;
        for (int j = 1;j < N;j++)
        {
            //차이가 1 이상이면 x
            if (abs(map[i][j] - map[i][j - 1]) > 1) {
                L_same = -2;
                break;
            }
            //왼쪽 경사와 같고, 올라가는 경우,
            if (map[i][j] == map[i][j-1] && R_same == -1)
            {
                if (L_same > 0)
                    L_same++;
                else
                    L_same += 2;
            }
            //왼쪽 경사와 같고 내려가는 경우
            else if (map[i][j] == map[i][j - 1] && R_same != -1)
            {
                R_same++;

                //L의 갯수와 같으면 경사로 놓기
                if (R_same == L)
                    R_same = -1;
            }
            //높이 차이가 발생 했을 경우, 올라가는 경우
            else if (map[i][j] - map[i][j - 1] == 1)
            {
                //경사를 놓을 수 있으면 패스
                if (L_same >= L)
                {
                    L_same = 1;
                }
                else {
                    L_same = -2;
                    break;
                }
            }
            //높이 차이가 발생하면서 내려가는 경우
            else if (map[i][j - 1] - map[i][j] == 1)
            {
                if (R_same == -1) {
                    L_same = -1;
                    R_same = 1;

                    if (R_same == L)
                        R_same = -1;
                }
                else
                {
                    L_same = -2;
                    break;
                }
            }
        }

        if (R_same == -1 && L_same != -2)
            ans++;
    }

    int U_same;
    int D_same;
    for (int j = 0;j < N;j++)
    {
        U_same = 1;
        D_same = -1;

        for (int i = 1;i < N;i++)
        {
            if (abs(map[i][j] - map[i - 1][j]) > 1) {
                U_same = -2;
                break;
            }
            //내려가는 경우의 수
            if (map[i][j] == map[i-1][j] && D_same == -1)
            {
                if (U_same > 0)
                    U_same++;
                else
                    U_same += 2;
            }
            //올라가는 경우의 수
            else if (map[i][j] == map[i-1][j] && D_same != -1)
            {
                D_same++;

                if (D_same == L)
                    D_same = -1;
            }
            else if (map[i][j] - map[i-1][j] == 1)
            {
                if (U_same >= L)
                {
                    U_same = 1;
                }
                else {
                    U_same = -2;
                    break;
                }
            }
            else if (map[i-1][j] - map[i][j] == 1)
            {
                if (D_same == -1) {
                    U_same = -1;
                    D_same = 1;

                    if (D_same == L)
                        D_same = -1;
                }
                else
                {
                    U_same = -2;
                    break;
                }
            }
        }

        if (U_same != -2 && D_same == -1)
            ans++;
    }

    cout << ans;
    return 0;
}
