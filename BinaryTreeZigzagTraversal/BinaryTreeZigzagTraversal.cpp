// BinaryTreeZigzagTraversal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <stack>
#include <vector>

class Node
{
public:
    Node* left;
    Node* right;
    int data;

    Node(int d)
        : data(d)
        , left(nullptr)
        , right(nullptr)
    {}
};

Node* ArrayToTree(const std::vector<int>& v)
{
    if (v.size() == 0)
        return nullptr;
    Node* root = new Node(v[0]);
    std::queue<Node*> q;
    q.push(root);
    bool l = true;
    for (size_t i = 1; i < v.size(); ++i, l = !l)
    {
        Node* pNode = q.front();
        if (!l)
            q.pop();
        if (v[i] != -1)
        {
            if (l)
            {
                pNode->left = new Node(v[i]);
                q.push(pNode->left);
            }
            else
            {
                pNode->right = new Node(v[i]);
                q.push(pNode->right);
            }
        }
    }

    return root;
}

void FreeTree(Node* pNode)
{
    if (pNode == nullptr)
        return;

    FreeTree(pNode->left);
    FreeTree(pNode->right);

    delete pNode;
}

void Traverse(std::stack<Node*>&& s, bool isLToR, std::vector<int>& result)
{
    std::stack<Node*> ss;
    while (!s.empty())
    {
        Node* pNode = s.top();
        s.pop();

        result.push_back(pNode->data);
        if (isLToR)
        {
            if (pNode->left != nullptr)
                ss.push(pNode->left);
            if (pNode->right != nullptr)
                ss.push(pNode->right);
        }
        else
        {
            if (pNode->right != nullptr)
                ss.push(pNode->right);
            if (pNode->left != nullptr)
                ss.push(pNode->left);
        }
    }

    if (!ss.empty())
        Traverse(std::move(ss), !isLToR, result);
}

std::vector<int> ZigzagLevelOrderTraversal(Node* root)
{
    bool lToR = true;
    std::stack<Node*> s;
    s.push(root);
    std::vector<int> result;

    Traverse(std::move(s), lToR, result);
    return result;
}

int main()
{
    while (true)
    {
        std::cout << "Number of nodes in the tree: ";
        int count = 0;
        std::cin >> count;
        if (count == 0)
            break;

        std::cout << "Values of the tree nodes: ";
        std::vector<int> v(count, 0);
        for (int i = 0; i < count; ++i)
            std::cin >> v[i];

        Node* root = ArrayToTree(v);

        std::vector<int> result = ZigzagLevelOrderTraversal(root);
        if (!result.empty())
            std::cout << result[0];
        for (size_t i = 1; i < result.size(); ++i)
            std::cout << ", " << result[i];
        std::cout << std::endl;
        FreeTree(root);
    }
}
