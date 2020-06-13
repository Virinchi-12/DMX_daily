/*84. Largest Rectangle in Histogram

Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

 


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

 


The largest rectangle is shown in the shaded area, which has area = 10 unit.

 

Example:

Input: [2,1,5,6,2,3]
Output: 10
*/

class Solution {
public:

      vector<int> nextSmallestElementRight(vector<int>& nums) {
        
         int n=nums.size(),j;
        stack<int> s;
        vector<int> res(n,n);
        
        for(int i=0;i<n;i++){
            while(!s.empty() && nums[s.top()]>nums[i]){
                res[s.top()]=i;
                s.pop();
            }

            s.push(i);
        }

        return res;
      }
    
    vector<int> nextSmallestElementLeft(vector<int>& nums) {
        
        int n=nums.size();
        stack<int> s2;
        vector<int> left(n, -1);
       
        for(int i=n-1; i>=0; i--){
            while(!s2.empty() && nums[s2.top()]>nums[i]){
                left[s2.top()]=i;
                s2.pop();
            }
            s2.push(i);
        }
        return left;
      }
    
    int largestRectangleArea(vector<int>& heights) {
        
        vector<int> nsr=nextSmallestElementRight(heights);
        vector<int> nsl=nextSmallestElementLeft(heights);
        int i,n=heights.size();
        
        for(i=0;i<n;i++){
            cout<<nsr[i]<<" ";
        }
        cout<<endl;
        for(i=0;i<n;i++){
            cout<<nsl[i]<<" ";
        }
        int area=0;
    for(i=0;i<n;i++){
        area=max(area,heights[i]*(nsr[i]-nsl[i]-1));
    }
        return area;
    }
    
};
