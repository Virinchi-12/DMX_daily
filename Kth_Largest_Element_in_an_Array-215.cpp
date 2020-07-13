/*
215. Kth Largest Element in an Array
Medium

3747

253

Add to List

Share
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        //Use a max heap to store the elements, the root will always be maximum element of the rest
        //while you pop, it rebalances in such a way that root is always the maximum
        priority_queue<int> heap(nums.begin(),nums.end());
        
        while(k>1){
            heap.pop();
            k--;
        }
        return heap.top();
    }
};
