#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

map<string, int> nameToNum;
map<int, string> numToName;
int indegree[1000];
int N, M;
vector<int> ancestor[1000];
vector<int> children[1000];
vector<string> root;

void topology(int n) {
    queue<int> q;
    q.push(n);
    int a,i,num;
    while (!q.empty()) {
        a = q.front();
        q.pop();

        for (i = 0;i < ancestor[a].size();i++) {
            num = ancestor[a][i];

            indegree[num]--;

            if (indegree[num] == 0) {
                q.push(num);
                children[a].push_back(num);
            }
        }
    }
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> N;

    int i;
    string s1, s2;
    for (i = 0;i < N;i++) {
        cin >> s1;
        nameToNum[s1] = i;
        numToName[i] = s1;
    }

    cin >> M;

    for (i = 0;i < M;i++) {
        cin >> s1 >> s2;
        indegree[nameToNum[s1]]++;
        ancestor[nameToNum[s2]].push_back(nameToNum[s1]);
    }

    for (i = 0;i < N;i++) {
        if (indegree[i] == 0)
            root.push_back(numToName[i]);
    }
    sort(root.begin(), root.end());

    cout << root.size() << '\n';

    for (i = 0;i < root.size();i++)
        cout << root[i] << ' ';

    for (i = 0;i < root.size();i++)
        topology(nameToNum[root[i]]);

    cout << '\n';
    vector<string> sortedName;
    for (auto m : nameToNum) {
        cout << m.first << ' ' << children[m.second].size()<<' ';
        for (i = 0;i < children[m.second].size();i++)
            sortedName.push_back(numToName[children[m.second][i]]);
        sort(sortedName.begin(), sortedName.end());

        for (i = 0;i < sortedName.size();i++)
            cout << sortedName[i] << ' ';

        cout << '\n';
        sortedName.clear();
    }
    return 0;

}
