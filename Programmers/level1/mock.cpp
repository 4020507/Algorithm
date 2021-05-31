#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int score[3] = {0,};
    int one[5] = {1,2,3,4,5};
    int two[8] = {2,1,2,3,2,4,2,5};
    int three[10] = {3,3,1,1,2,2,4,4,5,5};
    int count = 0;
    int temp = 0;
    for(auto i:answers)
    {
        if(one[count%5] == i)
            score[0]++;
        if(two[count%8] == i)
            score[1]++;
        if(three[(count++)%10] == i)
            score[2]++;
    }
    temp = max(score[0],max(score[1],score[2]));
    
    for(int i = 0;i<3;i++)
    {
        if(temp == score[i])
            answer.push_back(i+1);
    }
    return answer;
}
