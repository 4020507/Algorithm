#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
using namespace std;

int N, K, k;
int belt[201];
bool isRobot[101];

void moveBelt() {

    int temp = belt[N * 2];

    for (int i = N*2;i >= 2;i--) 
        belt[i] = belt[i - 1];
    
    belt[1] = temp;
    
    for (int i = N;i >= 1;i--)
        isRobot[i] = isRobot[i - 1];
}

void moveRobots() {

    isRobot[N] = false;

    for (int i = N-1;i >= 1;i--) {
        if (isRobot[i] && !isRobot[i + 1] && belt[i + 1] > 0) {
            belt[i + 1]--;
            isRobot[i] = false;
            isRobot[i + 1] = true;

            if (belt[i + 1] == 0)
                k++;
        }
    }
}

void putRobot() {
    if (belt[1] > 0 && !isRobot[1]) {
        isRobot[1] = true;
        belt[1]--;

        if (belt[1] == 0)
            k++;
    }
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> N >> K;

    for (int i = 1;i <= N * 2;i++)
        cin >> belt[i];

    memset(isRobot, false, sizeof(isRobot));
    k = 0;
    int steps = 0;
    while (k < K) {
        moveBelt();
        moveRobots();
        putRobot();
        steps++;
    }

    cout << steps;

    return 0;

}
