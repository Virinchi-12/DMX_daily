/*435. Non-overlapping Intervals
Medium

943

33

Add to List

Share
Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

 

Example 1:

Input: [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.*/


class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        vector<pair<int,int>> v;
        int n=intervals.size(),i;
    
        sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b){
            return a[1]<b[1];
            
        });
        
        i=0;int count=0;
        while(i<n)
        {
            int cur_ind=i;
           int  j=cur_ind+1;
            while(j<n){
            if(intervals[j][0]<intervals[cur_ind][1])
            {
                count++;
            }
            else
            {
                break;
            }
         j++;
                
            }
            i=j;
        }
            
        return count;
    }
};
