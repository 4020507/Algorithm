#include <string>
#include <vector>
#include <math.h>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int size = progresses.size();
    
    if(size == 0)
        return answer;
    int taken = -1;
    int count = 0;
    
    for(int i = 0;i<size;i++)
    {
        int date = ceil((float)(100 - progresses[i])/(float)speeds[i]);
        if(taken == -1)
        {
            taken = date;
            count++;
        }
        else if(taken >= date)
        {
            count++;
        }
        else
        {
            answer.push_back(count);
            count = 1;
            taken = date;
        }
    }
    answer.push_back(count);
    return answer;
}
