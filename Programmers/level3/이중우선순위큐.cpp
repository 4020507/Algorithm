3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int> big;
    priority_queue<int> small;

    int count = 0;
    for(auto o:operations)
    {
        if(count == 0)
        {
            while(!big.empty())
                big.pop();
            while(!small.empty())
                small.pop();
        }
        if(o[0] == 'I')
        {
            big.push(-stoi(o.substr(2)));
            small.push(stoi(o.substr(2)));
            count++;
        }
        else if(o[0] == 'D')
        {
            if(count == 0)
                continue;
            if(o[2] == '1')
            {
                small.pop();
            }
            else
            {
                big.pop();
            }
            count--;
        }
    }

    if(count == 0)
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        answer.push_back(small.top());
        answer.push_back(-big.top());
    }
    return answer;
}
