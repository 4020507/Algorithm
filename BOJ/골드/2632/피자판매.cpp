#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;

int pizzaA[1000];
int pizzaB[1000];
int sumA[1000001];
int sumB[1000001];

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int weight, cntA, cntB;

    cin >> weight >> cntA >> cntB;

    int i, j;
    int sum = 0;
    for (i = 0; i < cntA; i++) {
        cin >> pizzaA[i];

        sum += pizzaA[i];
    }

    sumA[sum]++;
    sum = 0;

    for (i = 0; i < cntB; i++) {
        cin >> pizzaB[i];

        sum += pizzaB[i];
    }

    sumB[sum]++;

    sumA[0] = 1;
    sumB[0] = 1;

    for (i = 0; i < cntA; i++) {
        sum = 0;
        for (j = 0; j < cntA - 1; j++) {
            sum += pizzaA[(i + j) % cntA];
            sumA[sum]++;
        }
    }

    for (i = 0; i < cntB; i++) {
        sum = 0;
        for (j = 0; j < cntB - 1; j++) {
            sum += pizzaB[(i + j) % cntB];
            sumB[sum]++;
        }
    }

    int cnt = 0;

    for (i = 0; i <= weight; i++) {
        cnt += (sumA[i] * sumB[weight - i]);
    }

    cout << cnt;

    return 0;
}
