#pragma warning(disable:4996)
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class score
{
public:
    string name;
    int korean;
    int english;
    int math;

    score(string name, int korean, int english, int math)
    {
        this->name = name;
        this->korean = korean;
        this->english = english;
        this->math = math;
    }

    bool operator < (score& other)
    {
        if (this->korean == other.korean && this->english == other.english && this->math == other.math) {
            return this->name < other.name;
        }
        if (this->korean == other.korean && this->english == other.english) {
            return this->math > other.math;
        }
        if (this->korean == other.korean) {
            return this->english < other.english;
        }
        return this->korean > other.korean;
    }
};

int main(void) {

    int N;
    cin >> N;

    vector<score> lists;
    for (int i = 0;i < N;i++)
    {
        string name;
        int korean;
        int english;
        int math;

        cin >> name >> korean >> english >> math;
        lists.push_back(score(name, korean, english, math));
    }

    sort(lists.begin(), lists.end());

    for (auto s : lists)
    {
        cout << s.name <<'\n';
    }
    return 0;
    
}
