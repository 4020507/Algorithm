#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    sort(rocks.begin(),rocks.end());
    int left = 0;
    int right = distance;
    int size = rocks.size();
    while(left <= right)
    {
        int mid = (left + right)/2;
        int prev = 0;
        int count = 0;
        for(int i = 0;i<size;i++)
        {
            if(rocks[i] - prev < mid)
            {
                count++;
            }
            else
                prev = rocks[i];
        }
        if(distance - prev < mid)
            count++;

        if(count <= n)
        {
            answer = max(mid,answer);
            left = mid + 1;
        }
        else
            right = mid - 1;
    }

    return answer;
}
