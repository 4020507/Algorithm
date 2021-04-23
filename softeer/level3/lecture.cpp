#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b)
{
        return a.second<b.second;
}
int main(int argc, char** argv)
{
        int N, S, F;
        cin>>N;

        int count = 1;
        vector<pair<int,int>> v;
        for(int i = 0;i<N;i++)
        {
                cin>>S>>F;
                v.push_back(make_pair(S,F));
        }
        
        sort(v.begin(),v.end(),cmp);

        count = 1;
        int second = v[0].second;

        int size = v.size();
        for(int i = 1;i<size;i++)
        {
                if(second <= v[i].first)
                {
                        count++;
                        second = v[i].second;
                }
        }
        cout<<count;
        retur
