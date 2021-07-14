#include <string>
#include <vector>

using namespace std;

int balanced(string s)
{
    int count = 0;
    
    for(int i = 0;s.length();i++)
    {
        if(s[i] == '(')
        {
            count++;
        }
        else
            count--;
        if(count == 0)
            return i;
    }
    
    return -1;
}

bool right(string s)
{
    int count = 0;
    
    for(int i = 0;i<s.length();i++)
    {
        if(s[i] == '(')
            count++;
        else
        {
            if(count == 0)
                return false;
            count--;
        }
    }
    
    return true;
}
string solution(string p) {
    string answer = "";
    
    if(p == "")
        return answer;
    
    int index = balanced(p) + 1;
    string u = p.substr(0,index);
    string v = p.substr(index);
    
    if(right(u))
    {
        answer = u + solution(v);
    }
    else
    {
        answer += "(";
        answer += solution(v);
        answer += ")";
        u = u.substr(1,u.size()-2);
        for(int i = 0;i<u.size();i++)
        {
            if(u[i] == '(')
                u[i] = ')';
            else
                u[i] = '(';
        }
        
        answer += u;
    }
    return answer;
}
