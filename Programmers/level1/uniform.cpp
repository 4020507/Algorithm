#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int student[30] = {0,};
    int answer = 0;
    for(auto i:reserve)
        student[i]++;
    for(auto i:lost)
        student[i]--;
    
    for(int i = 1;i<=n;i++)
    {
        if(student[i] == 0 || student[i] == 1)
            answer++;
        else if(student[i] == -1)
        {
            if(i>0 && student[i-1] == 1)
            {
                answer++;
            }
            else if(student[i+1] == 1)
            {
                answer += 2;
                student[i+1]--;
                i++;
            }
        }
    }
    return answer;
}
