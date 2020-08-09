/*
127. Word Ladder
Medium

3313

1190

Add to List

Share
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> s(wordList.begin(),wordList.end());
        
        //make a queue
        queue<pair<string,int>> q;
        unordered_set<string> visited;
        
        pair<string,int> curElement;
        string currword;
        int currdist;
        
        //initialisation
        //push into the queue and mark as visited
        q.push({beginWord,1});
        visited.insert(beginWord);
        while(!q.empty()){
            
            curElement=q.front();
            q.pop();
            
            currword=curElement.first;
            currdist=curElement.second;
            
            if(currword==endWord)
                return currdist;
            
            //process it's neighbours
            //For every index of a word, consider all possibilites
            string tempword=currword;
            for(int i=0;i<currword.size();i++){
                for(int j=0;j<26;j++){
                    tempword[i]=(char)(j+'a');
                    
                    //If in dictionary but unvisited
                    if(s.find(tempword)!=s.end() && visited.find(tempword)==visited.end()){
                        q.push({tempword,currdist+1});
                        visited.insert(tempword);
                    }
                }
                tempword[i]=currword[i];
            }
            
        }
        return 0;
    }
};
