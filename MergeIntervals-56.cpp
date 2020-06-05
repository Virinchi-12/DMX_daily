class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        int n=intervals.size(),i;
        vector<pair<int,int>> res;
        
        for(i=0;i<n;i++)
        {
            res.push_back(make_pair(intervals[i][0],0));
            res.push_back(make_pair(intervals[i][1],1));
        }
        
                sort(res.begin(),res.end());

        
        vector<vector<int>> finale;int count=0;
        for(i=0;i<2*n;i++)
        {
            if(res[i].second==0){
                count++;
            if(count==1) finale.push_back({res[i].first});
            }
            if(res[i].second==1){ count--;
            
            if(count==0) finale[finale.size()-1].push_back(res[i].first);
                                }
        }
        
       return finale; 
    }
};
