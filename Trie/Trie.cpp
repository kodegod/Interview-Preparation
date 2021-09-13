#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long
#define MOD 1000000007
#define N 100005
#define ii pair<int,int>

class Node
{
public:
    char data;
    char isTerminal;
    map<char, Node*> children;

    Node(char ch)
    {
        this->data = ch;
        this->isTerminal = false;
    }
};

class Trie
{
public:
    Node *root;
    Trie()
    {
        this->root = new Node('\0');
    }

    void insert(string str)
    {
        Node *temp = this->root;
        for (int i = 0; i < str.size(); i++)
        {
            char ch = str[i];
            if (temp->children.count(ch))
                temp = temp->children[ch];
            else
            {
                Node *n = new Node(ch);
                temp->children[ch] = n;
                temp = n;
            }
        }
        temp->isTerminal = true;
        return;
    }

    bool search(string str)
    {
        Node *temp = this->root;
        for (int i = 0; i < str.size(); i++)
        {
            char ch = str[i];
            if (temp->children.count(ch))
                temp = temp->children[ch];
            else
                return false;
        }
        return (temp->isTerminal == true);
    }

    void helperDFS(Node *root, string str, string osf)
    {
        if (root == NULL)
            return;

        if (root->isTerminal == true)
            cout << str + osf << endl;

        for (auto ch : root->children)
        {
            helperDFS(ch.second, str, osf + ch.first);
        }
    }

    void printPrefix(string str)
    {
        Node *temp = this->root;
        for (int i = 0; i < str.size(); i++)
        {
            char ch = str[i];
            if (temp->children.count(ch))
                temp = temp->children[ch];
            else
            {
                cout << "Query string not present";
                return;
            }
        }
        helperDFS(temp, str, "");
    }
};

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastio();
    string str;
    int t;
    cin >> t;
    Trie tr;
    while (t--)
    {
        cin >> str;
        tr.insert(str);
    }
    int q;
    cin >> q;
    while (q--)
    {
        cin >> str;
        cout << ((tr.search(str) == true) ? "Yes" : "No") << endl;
    }
    int prefix;
    cin >> prefix;
    while (prefix--)
    {
        cin >> str;
        cout << "prefixes are" << endl;
        tr.printPrefix(str);
    }

    return 0;
}
