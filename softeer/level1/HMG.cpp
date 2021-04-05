#include<iostream>


using namespace std;

int main(int argc, char** argv)
{
        string name;
        cin>> name;

        string abbreviation = "";
        for(int i = 0;i<name.length();i++)
                if(name[i] >= 65 && name[i]<=90)
                        abbreviation += name[i];
        
        cout<<abbreviation<<endl;

 return 0;
}
