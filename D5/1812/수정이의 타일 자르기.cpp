#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,M;
vector<pair<bool,pair<int,int>>> tile;
vector<int> square;
int ans;
bool cmp(int a, int b)
{
    return a>b;
}

void sol()
{
    ans = 1;
    int size = square.size();
    for(int i = 0;i<size;i++)
    {
        bool check = false;

        for(int j = 0;j<tile.size();j++)
        {
            if(tile[j].first)
                continue;
            int length = tile[j].second.first;
            int width = tile[j].second.second;
            
            if(length >= square[i] && width >= square[i])
            {
                check = true;
                tile[j].first = true;

                if(length>square[i])
                    tile.push_back(make_pair(false,make_pair(length - square[i],width)));
                if(width>square[i])
                    tile.push_back(make_pair(false,make_pair(square[i],width - square[i])));
                break;
            }
        }
        if(!check)
            {
                ans++;
                if(M>square[i])
                    tile.push_back(make_pair(false,make_pair(M,M-square[i])));
                if(M>square[i])
                	tile.push_back(make_pair(false,make_pair(M-square[i],square[i])));
            }
    }
}
int main(void)
{
    int T;
    cin>>T;
    int a;
    int len;
    for(int test_case = 1;test_case<=T;test_case++)
    {
        cin>>N>>M;
        
        tile.clear();
        square.clear();
        for(int i = 0;i<N;i++){
            cin>>a;
            len = 1;
            for(int j = 0;j<a;j++) len<<=1;
            square.push_back(len);
        }
        sort(square.begin(),square.end(),cmp);
        tile.push_back(make_pair(false,make_pair(M,M)));
        
        sol();
        cout<<"#"<<test_case<<" "<<ans<<endl;
    }
}
