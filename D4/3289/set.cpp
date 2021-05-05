#include<iostream>

using namespace std;

int parent[1000001];

int findParent(int a)
{
    if(parent[a] == a)
        return a;
    else
        return parent[a] = findParent(parent[a]);
}

bool sameParent(int a,int b)
{
    a = findParent(a);
    b = findParent(b);
    if(a == b)
        return true;
    else
        return false;
}

void Union(int a,int b)
{
    a = findParent(a);
    b = findParent(b);
    
    parent[a] = min(a,b);
    parent[b] = parent[a];
}
int main(void)
{
    int T;
    cin>>T;
    int m,n,a,b;
    int size;
    int order;
    string s;
    bool check;
	int out;
    for(int test_case = 1;test_case<=T;test_case++)
    {
        cin>>n>>m;
        
        for(int i = 1;i<=1000001;i++)
            parent[i] = i;
        s = "";
        
        for(int i = 0;i<m;i++)
        {
            cin>>order>>a>>b;
            
            if(order == 0)
            {
                Union(a,b);
            }
            else
            {
                if(sameParent(a,b))
                    s += "1";
                else
                    s += "0";
            }
        }  
        cout<<"#"<<test_case<<" "<<s<<endl;
    }
}
