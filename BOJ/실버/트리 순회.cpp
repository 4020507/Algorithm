#include <iostream>
#include <string>
using namespace std;


class tree {
    tree* left;
    tree* right;
    char val;

public:
    void setData(char val)
    {
        this->val = val;
    }

    void setLeft(tree* left)
    {
        this->left = left;
    }

    void setRight(tree* right)
    {
        this->right = right;
    }

    void static preOrder(tree* tree)
    {
        if (tree != NULL)
        {
            cout << tree->val;
            preOrder(tree->left);
            preOrder(tree->right);
        }
    }

    void static inOrder(tree* tree)
    {
        if (tree != NULL)
        {
            inOrder(tree->left);
            cout << tree->val;
            inOrder(tree->right);
        }
    }

    void static postOrder(tree* tree)
    {
        if (tree != NULL)
        {
            postOrder(tree->left);
            postOrder(tree->right);
            cout << tree->val;
        }
    }
};
int main(void)
{
    int N;
    cin >> N;

    tree* root = new tree[27];
    char a, b, c;
    for (int i = 0;i < N;i++)
    {
        cin >> a >> b >> c;

        root[a - 'A'].setData(a);

        if (b != '.')
            root[a - 'A'].setLeft(&root[b - 'A']);
        else
            root[a - 'A'].setLeft(NULL);
        if (c != '.')
            root[a - 'A'].setRight(&root[c - 'A']);
        else
            root[a - 'A'].setRight(NULL);
    }

    tree* t = &root[0];
    tree::preOrder(t); cout << '\n';
    tree::inOrder(t); cout << '\n';
    tree::postOrder(t); cout << '\n';

    return 0;

}
