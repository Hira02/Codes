#include <bits/stdc++.h>
using namespace std;
class trie
{
    public:
    bool isWord;
    trie *children[26];
    trie()
    {
        // trie *root;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        // root->isWord = true;
    }
};
void insert(string word, trie *root)
{
    trie *crawl = root;
    for (int i = 0; i < word.length(); i++)
    {
        int val = word[i] - 'a';
        if (!crawl->children[val] )
        {
            crawl->children[val] = new trie();
        }
        crawl = crawl->children[val];
    }
    crawl->isWord = true;
}
int searchWord(string word, trie *root)
{
    trie *curr = root;
    for (int i = 0; i < word.length(); i++)
    {
        int val = word[i] - 'a';
        if (!curr->children[val])
            return 0;
        curr = curr->children[val];
    }
    if (!curr && curr->isWord == true)
        return 1;
    return 0;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string str;
        cin >> str;
        cout<<str;
        trie *root = new trie();
        string temp = "";
        // int size = sizeof(str)/sizeof(str[0]);
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == ' ')
            {
                insert(temp, root);
                temp.clear();
            }
            else
            {
                temp += str[i];
            }
        }
        string word;
        cin >> word;
        cout << searchWord(word, root) << "\n";
    }
}