#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;



const int MAX = 4000;



long long arr[4][MAX];



int main(void)

{

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    int N;

    cin >> N;



    for (int i = 0; i < N; i++)

        for (int j = 0; j < 4; j++)

            cin >> arr[j][i];



    vector<long long> v;

    //3번째 4번째 배열 합 전처리

    for (int i = 0; i < N; i++)

        for (int j = 0; j < N; j++)

            v.push_back(arr[2][i] + arr[3][j]);



    sort(v.begin(), v.end());

    long long result = 0;

    for (int i = 0; i < N; i++)

        for (int j = 0; j < N; j++)

        {

            long long half = arr[0][i] + arr[1][j];

            //-half에 제일 근접한 인덱스 반환

            long long low = lower_bound(v.begin(), v.end(), -half) - v.begin();

            long long high = upper_bound(v.begin(), v.end(), -half) - v.begin();



            //합이 0이여야지 성립

            if (-half == v[low])

                result += (high - low);

        }

    cout << result << "\n";

    return 0;

}
