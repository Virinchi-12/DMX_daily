/*

743. Network Delay Time
Medium

1769

229

Add to List

Share
There are N network nodes, labelled 1 to N.

Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node, and w is the time it takes for a signal to travel from source to target.

Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal? If it is impossible, return -1.

 

Example 1:



Input: times = [[2,1,1],[2,3,1],[3,4,1]], N = 4, K = 2
Output: 2
 

Note:

N will be in the range [1, 100].
K will be in the range [1, N].
The length of times will be in the range [1, 6000].
All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 0 <= w <= 100.

*/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        // Construct the graph
        vector<vector<pair<int, int>>> graph(N+1);
        int i, currNode, currWeight, res = -1, countNodes = 0;
        pair<int, int> currElt;
        
        for(i = 0; i < times.size(); i++)
            graph[times[i][0]].push_back({times[i][2], times[i][1]});
        
        // Priority queue
        // Min pq
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        vector<bool> visited(N+1, false);
        
        // Initialize
        pq.push({0, K});
        
        while(!pq.empty()){
            
            currElt = pq.top();
            pq.pop();
            
            currNode = currElt.second;
            currWeight = currElt.first;
            
            // Handle more than 1 instance of the same node in the PQ
            if(visited[currNode]) continue;
            
            // Unique instance
            visited[currNode] = true;
            
            res = max(res, currWeight);
            
            countNodes++;
            
            // Push its neighbours
            for(i = 0; i < graph[currNode].size(); i++){
                if(!visited[graph[currNode][i].second])
                    pq.push({currWeight+graph[currNode][i].first, graph[currNode][i].second});
            }
        }
        
        return (countNodes == N)? res: -1;
    }
};
