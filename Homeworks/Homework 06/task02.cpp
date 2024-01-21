#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node* left;
    Node* right;
};

Node nodes[10000000];
long long childrenAmount[10000000] = { 0 };

int calculateChildrenAmount(Node* root, const size_t& index)
{
    if (!root->left && !root->right) return 0;

    if (root->left)
    {
        childrenAmount[index]++;
        childrenAmount[index] += calculateChildrenAmount(root->left, root->left->value);
    }
    if (root->right)
    {
        childrenAmount[index]++;
        childrenAmount[index] += calculateChildrenAmount(root->right, root->right->value);
    }

    return childrenAmount[index];
}

void generateTree(size_t nodesAmount)
{
    int leftChildIndex, rightChildIndex;

    nodes[nodesAmount].value = nodesAmount;
    nodes[nodesAmount + 1].value = nodesAmount + 1;

    for (size_t i = 0; i < nodesAmount; i++)
    {
        cin >> leftChildIndex >> rightChildIndex;

        nodes[i].value = i;
        if (leftChildIndex == -1) nodes[i].left = nullptr;
        else
        {
            nodes[i].left = &nodes[leftChildIndex];
        }

        if (rightChildIndex == -1) nodes[i].right = nullptr;
        else
        {
            nodes[i].right = &nodes[rightChildIndex];
        }
    }
}

long long findMaxProduct(size_t nodesAmount)
{
    calculateChildrenAmount(&nodes[0], 0);
    long long currentProduct = 1, maxProduct = 1;

    maxProduct = (nodes[0].left ? childrenAmount[nodes[0].left->value] + 1 : 1) *
        (nodes[0].right ? childrenAmount[nodes[0].right->value] + 1 : 1);

    for (size_t i = 1; i <= nodesAmount; i++)
    {
        currentProduct = (childrenAmount[0] - childrenAmount[i]) *
            (nodes[i].left ? childrenAmount[nodes[i].left->value] + 1 : 1) *
            (nodes[i].right ? childrenAmount[nodes[i].right->value] + 1 : 1);
        maxProduct = max(maxProduct, currentProduct);
    }

    return maxProduct;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    size_t nodesAmount;
    cin >> nodesAmount;

    generateTree(nodesAmount);
    cout << findMaxProduct(nodesAmount);

    return 0;
}
