#pragma warning(disable:4996)
#include <iostream>
#include <string>

using namespace std;

char map[3][3];
string input;
int oCount;
int xCount;
bool X;
bool O;

bool checkX() {

    for (int i = 0; i < 3; i++) {

        if (map[i][0] == 'X' && map[i][1] == 'X' && map[i][2] == 'X')
            return true;

        if (map[0][i] == 'X' && map[1][i] == 'X' && map[2][i] == 'X')
            return true;
    }

    if (map[0][0] == 'X' && map[1][1] == 'X' && map[2][2] == 'X')
        return true;
    if (map[0][2] == 'X' && map[1][1] == 'X' && map[2][0] == 'X')
        return true;

    return false;
}

bool checkO() {

    for (int i = 0; i < 3; i++) {

        if (map[i][0] == 'O' && map[i][1] == 'O' && map[i][2] == 'O')
            return true;

        if (map[0][i] == 'O' && map[1][i] == 'O' && map[2][i] == 'O')
            return true;
    }

    if (map[0][0] == 'O' && map[1][1] == 'O' && map[2][2] == 'O')
        return true;
    if (map[0][2] == 'O' && map[1][1] == 'O' && map[2][0] == 'O')
        return true;

    return false;
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> input;

    while (input != "end") {
        oCount = 0;
        xCount = 0;
        for (int i = 0; i < 9; i++) {
            map[i / 3][i % 3] = input[i];

            if (input[i] == 'O')
                oCount++;
            if (input[i] == 'X')
                xCount++;
        }

        X = checkX();
        O = checkO();

        if (X && !O && xCount == oCount + 1)
            cout << "valid" << '\n';
        else if (!X && O && xCount == oCount)
            cout << "valid" << '\n';
        else if (!X && !O && xCount == 5 && oCount == 4)
            cout << "valid" << '\n';
        else
            cout << "invalid" << '\n';


        cin >> input;
    }
    return 0;

}
