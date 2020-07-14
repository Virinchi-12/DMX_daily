/*
347. Top K Frequent Elements
Medium

3095

215

Add to List

Share
Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
You can return the answer in any order.
*/

class Solution {
public:
    typedef pair<int,int> p;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //Build the max heap based on the frequency i.e pair of frequency and nums[i]
        priority_queue<p> pq;
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        
        for(auto it:m){
            pq.push({it.second,it.first});
        }
        
        vector<int> res;
        while(res.size()<k){
            pair<int,int> pres=pq.top();
            res.push_back(pres.second);
            pq.pop();
        }
        return res;
    }
};
