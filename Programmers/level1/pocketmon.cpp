#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 1;
    sort(nums.begin(),nums.end());
    int N = nums.size()/2;
    
    int prev = nums[0];
    for(int i = 1;i<nums.size();i++)
    {
        if(answer == N)
            break;
        if(prev == nums[i])
            continue;
        answer++;
        prev = nums[i];
    }
    return answer;
}
