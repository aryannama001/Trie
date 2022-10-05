#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[26];
    bool isEnd;
};

Node *construct()
{
    Node *newNode = new Node;

    newNode->isEnd = false;

    for (int i = 0; i < 26; i++)
        newNode->links[i] = NULL;

    return newNode;
}

void insert(Node *root, string s)
{
    Node *temp = root;

    for (int i = 0; i < s.size(); i++)
    {
        int index = s[i] - 'a';
        if (!temp->links[index])
        {
            temp->links[index] = construct();
        }
        temp = temp->links[index];
    }
    temp->isEnd = true;
}

bool search(Node *root, string s)
{
    Node *temp = root;

    for (int i = 0; i < s.size(); i++)
    {
        int index = s[i] - 'a';
        if (!temp->links[index])
            return false;

        temp = temp->links[index];
    }

    return (temp->isEnd);
}

int main()
{
    string keywords[] = {
        "auto", "break", "case", "char", "continue", "do", "default", "const", "double", "else", "enum", "extern", "for", "if", "goto", "float", "int", "long", "register", "return", "signed", "static", "sizeof", "short", "struct", "switch", "typedef", "union", "void", "while", "volatile", "unsigned"};

    int n = sizeof(keywords) / sizeof(keywords[0]);

    Node *root = construct();

    for (int i = 0; i < n; i++)
        insert(root, keywords[i]);

    string key;
    cout << "enter the string: ";
    cin >> key;

    if (search(root, key))
    {
        cout << key << " is a keyword" << endl;
    }
    else
        cout << key << " is not a keyword" << endl;

    return 0;
}