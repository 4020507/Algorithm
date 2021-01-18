#include <iostream>

using namespace std;
char node[100];
/*
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV140YnqAIECFAYD
*/
void inorder(int curr, int N)
{
    if (N > curr)
    {
        inorder(curr * 2 + 1, N);
        cout << node[curr];
        inorder(curr * 2 + 2, N);
    }
}
int main(void)
{
    int N;

    for (int test_case = 1;test_case <= 10;test_case++)
    {
        cin >> N;
        int curr;
        char c;
        int left;
        int right;
        for (int i = 0;i < N;i++)
        {
            if (i * 2 + 2 < N)
                cin >> curr >> c >> left >> right;
            else if (i * 2 + 1 < N)
                cin >> curr >> c >> left;
            else
                cin >> curr >> c;
            node[i] = c;
        }
        cout << "#" << test_case << " ";
        inorder(0, N);
        cout << endl;

    }
}
