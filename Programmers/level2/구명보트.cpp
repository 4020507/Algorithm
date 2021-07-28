#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    int right = people.size()-1;
    int left = 0;
    
    sort(people.begin(),people.end());
    
    while(left<right)
    {
        int sum = people[left] + people[right];
        
        if(sum <= limit)
        {
            answer++;
            left++;
            right--;
        }
        else
        {
            answer++;
            right--;
        }
    }
    
    if(left == right)
        answer++;
    
    return answer;
}
