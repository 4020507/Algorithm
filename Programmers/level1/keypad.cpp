#include <string>
#include <vector>
#include <math.h>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int L_pos = 10;
    int R_pos = 12;
    
    for(auto i:numbers)
    {
        if(i == 1 || i == 4 || i == 7)
        {
            answer+= "L";
            L_pos = i;
        }
        else if(i == 3 || i == 6 || i == 9)
        {
            answer += "R";
            R_pos = i;
        }
        else
        {
            if(i == 0)
                i = 11;
            int L = abs(L_pos - i);
            int R = abs(R_pos - i);
            L = L/3 + L%3;
            R = R/3 + R%3;
            
            if(L == R)
            {
                if(hand == "left")
                {
                    L_pos = i;
                    answer += "L";
                }
                else
                {
                    R_pos = i;
                    answer += "R";
                }
            }
            else if(L < R)
            {
                L_pos = i;
                answer += "L";
            }
            else
            {
                R_pos = i;
                answer += "R";
            }
            
        }
    }
    return answer;
}
