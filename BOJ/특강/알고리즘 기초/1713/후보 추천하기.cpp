#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

bool cmp(pair<int, pair<int, int>> & a, pair<int, pair<int, int>>& b)
{
    if (a.first != b.first)
        return a.first > b.first;
    else
        return a.second.first > b.second.first;
}

bool cmp2(pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b)
{
    return a.second.second < b.second.second;
}
int main() {

    cin >> N;
    int M;
    cin >> M;

    int num;
    vector<pair<int, pair<int,int>>> candidates;
    bool exist;
    for (int i = 0;i < M;i++)
    {
        cin >> num;
        exist = false;
        
        for (int i = 0;i < candidates.size();i++)
        {
            if (candidates[i].second.second == num)
            {
                candidates[i].first++;
                exist = true;
                break;
            }
        }

        if (candidates.size() == N && !exist)
        {
            sort(candidates.begin(), candidates.end(),cmp);
            candidates.pop_back();
        }

        if (!exist)
        {
            candidates.push_back({ 1,{i, num} });
        }
    }

    sort(candidates.begin(), candidates.end(),cmp2);
    for (auto c : candidates)
    {
        cout << c.second.second << ' ';
    }

    


    return 0;
}
