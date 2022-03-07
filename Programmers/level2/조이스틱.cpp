#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string name) {
    int answer = 0;
    int turn = name.length()-1;
    for(int i = 0;i<name.length();i++){
        answer += min(name[i] - 'A','Z'-name[i]+1);
        int check = i+1;
        int l = name.length();

        while(check<l && name[check] == 'A') check++;

        turn = min(turn,i+l - check + min(i,l-check));

    }

    answer = turn + answer;
    return answer;
}
