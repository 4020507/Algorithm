#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;

    long long start = 0;
    long long end = (long long) times[times.size()-1] * n;
    
    while(start <= end)
    {
        long long mid = (start + end)/2;

        long long t = 0;
        
        for(auto time:times)
            t += mid/time;
        
        if(t >= n)
        {
            answer = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    return answer;
}
