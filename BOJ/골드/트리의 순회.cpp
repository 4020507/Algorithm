#pragma warning(disable:4996)
#include <iostream>

using namespace std;

int inOrder[100001];
int postOrder[100001];
int inOrderIndex[100001];

void makePreOrder(int postOrderStart, int postOrderEnd, int inOrderStart, int inOrderEnd) {
    
    if (postOrderStart > postOrderEnd || inOrderStart > inOrderEnd)
        return;
    int root = postOrder[postOrderEnd];
    cout << root << ' ';

    makePreOrder(postOrderStart, postOrderStart + inOrderIndex[root] - inOrderStart - 1, inOrderStart, inOrderIndex[root] - 1);

    makePreOrder(postOrderStart + inOrderIndex[root] - inOrderStart, postOrderEnd - 1, inOrderIndex[root] + 1, inOrderEnd);
}
int main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    for (int i = 0;i < N;i++)
        cin >> inOrder[i];
    for (int i = 0;i < N;i++)
        cin >> postOrder[i];
    for (int i = 0;i < N;i++)
        inOrderIndex[inOrder[i]] = i;

    makePreOrder(0, N - 1, 0, N - 1);

    return 0;

}
