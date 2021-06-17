#include <string>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int len = dartResult.length();
    int num = 11;
    int prev = 11;

    for(int i = 0;i<len;i++)
    {
        if(dartResult[i] >= '0' && dartResult[i] <= '9'){
            if(dartResult[i] == '0')
            {
                if(i > 0 && dartResult[i-1] == '1')
                    num = 10;
                else{
                    prev = num;
                    num = 0;
                }
            }
            else{
                prev = num;
                num = dartResult[i] - '0';
            }
        }
        else if(dartResult[i] == 'D'){
            num = num * num;
            answer += num;
        }
        else if(dartResult[i] == 'T'){
            num = num * num * num;
            answer += num;
        }
        else if(dartResult[i] == '*'){
            if(prev != 11){
                answer = answer + prev + num;
                num = num * 2;
            }
            else
            {
                answer = answer + num;
                num = num * 2;
            }
        }
        else if(dartResult[i] == '#'){
            answer = answer + num * (-2);
            num = -num;
        }
        else if(dartResult[i] == 'S'){
            answer += num;
        }
    }
    return answer;
}
