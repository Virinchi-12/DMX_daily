class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        
        int n=A.size(),i;
        
        sort(A.begin(),A.end(),[](int &a,int &b){
           
            return abs(a)<abs(b);
        });
        for(i=0;i<n;i++)
        {
            A[i]=A[i]*A[i];
        }
    return A;
    }
};
