/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

#include<bits/stdc++.h>
class TrieNode {
public:
    unordered_map<int,TrieNode *> child;
    bool isEnd;
    TrieNode()
    {
        isEnd=false;
    }
    
};

class Trie {
public:
    /** Initialize your data structure here. */
    TrieNode *root;   
    Trie() {
        root= new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *tem=root;
        for(auto x:word)
        {
            if(!tem->child.count(x-'a'))
                tem->child[x-'a']= new TrieNode();
            tem=tem->child[x-'a'];
        }
        tem->isEnd=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *tem=root;
        for(auto x:word)
        {
            if(!tem->child.count(x-'a'))
                return false;
            tem=tem->child[x-'a'];
        }
        return  tem->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *tem=root;
        for(auto x:prefix)
        {
            if(!tem->child.count(x-'a'))
                return false;
            tem=tem->child[x-'a'];
        }
        return  true;
    }
};
