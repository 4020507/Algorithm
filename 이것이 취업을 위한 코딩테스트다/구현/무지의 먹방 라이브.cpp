
2
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
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int solution(vector<int> food_times, long long k) {

    long long total = 0;
    for (int i = 0; i < food_times.size(); i++) {
        total += food_times[i];
    }

    if (total <= k) 
        return -1;

    priority_queue<pair<int, int> > pq;
    for (int i = 0; i < food_times.size(); i++) {

        pq.push(make_pair(-food_times[i], i + 1));
    }

    total = 0;
    long long previous = 0;
    long long size = food_times.size(); 

    while (total + ((-pq.top().first - previous) * size) <= k) {
        int curr = -pq.top().first;
        pq.pop();
        total += (curr - previous) * size;
        size--;
        previous = curr; 
    }

    vector<pair<int, int> > ans;
    while (!pq.empty()) 
    {
        ans.push_back(make_pair(-pq.top().first,pq.top().second));
        pq.pop();
    }
    sort(ans.begin(), ans.end(), cmp);
    return ans[(k - total) % size].second;
}
