/*
208. Implement Trie (Prefix Tree)
Medium

3205

50

Add to List

Share
Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.
*/
class Trie {
public:
    /** Initialize your data structure here. */
    
    struct Treenode{
         bool isWord;
         Treenode* next[26];
                Treenode(){
                    isWord=false;
                    for(int i=0;i<26;i++){
                    next[i]=NULL;
                    }
                }    
        
    };  
    Treenode* root;
    Trie() {
        root=new Treenode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Treenode*  temp=root;
        for(auto c:word){
            int idx=c-'a';
            if(temp->next[idx]==NULL)
                temp->next[idx]=new Treenode();
            temp=temp->next[idx];
        }
        temp->isWord=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Treenode*  temp=root;
        for(auto c:word){
            int idx=c-'a';
            if(temp->next[idx]==NULL)
                return false;
            temp=temp->next[idx];
        }   
        return temp->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Treenode*  temp=root;
        for(auto c:prefix){
            int idx=c-'a';
            if(temp->next[idx]==NULL)
                return false;
            temp=temp->next[idx];
        }   
        return true;   
    }
};
