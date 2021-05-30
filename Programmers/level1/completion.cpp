#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(),participant.end());
    sort(completion.begin(),completion.end());
    
    int count = 0;
    
    for(auto i:completion)
    {
        if(i != participant[count])
            return participant[count];
        count++;
    }
    return participant[participant.size()-1];
}
