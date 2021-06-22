#include <string>
#include <vector>

using namespace std;

void dfs(vector<int>&numbers,int target,int count,int& answer,int sum){
    if(numbers.size() == count)
    {
        if(target == sum)
        {
            answer++;
        }
        return;
    }
    
    dfs(numbers,target,count+1,answer,sum+numbers[count]);
    dfs(numbers,target,count+1,answer,sum-numbers[count]);
}
int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(numbers,target,0,answer,0);
    return answer;
}
