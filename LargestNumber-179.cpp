class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        int n=nums.size(),i;
             
        sort(nums.begin(),nums.end(),[](int &a, int &b){
            string s1=to_string(a),s2=to_string(b);
            int q=s1.size(),w=s2.size();
         
            if(s1+s2>s2+s1)
                return true;
            else return false;
               
        });
        
        string s;
        for(i=0;i<n;i++)
        {
            s=s+to_string(nums[i]);
        }
      
        if(s[0]=='0')
            return("0");
        return s;
    }
};
