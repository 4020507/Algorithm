#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int total = brown + yellow;
    
    int r = total;
    if(yellow == 0)
    {
        answer.push_back(r);
        answer.push_back(1);
        return answer;
    }
    int c = 2;
    while(c<=r)
    {
        while(total%c != 0)
        {
            c++;
        }
        r = total/c;
        if(r * 2 + (c-2)*2 == brown && (c-2)>0)
        {
            answer.push_back(r);
            answer.push_back(c);
            return answer;
        }
        c++;
    }
    return answer;
}
