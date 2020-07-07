/*
957. Prison Cells After N Days
Medium

665

940

Add to List

Share
There are 8 prison cells in a row, and each cell is either occupied or vacant.

Each day, whether the cell is occupied or vacant changes according to the following rules:

If a cell has two adjacent neighbors that are both occupied or both vacant, then the cell becomes occupied.
Otherwise, it becomes vacant.
(Note that because the prison is a row, the first and the last cells in the row can't have two adjacent neighbors.)

We describe the current state of the prison in the following way: cells[i] == 1 if the i-th cell is occupied, else cells[i] == 0.

Given the initial state of the prison, return the state of the prison after N days (and N such changes described above.)

 

Example 1:

Input: cells = [0,1,0,1,1,0,0,1], N = 7
Output: [0,0,1,1,0,0,0,0]
Explanation: 
The following table summarizes the state of the prison on each day:
Day 0: [0, 1, 0, 1, 1, 0, 0, 1]
Day 1: [0, 1, 1, 0, 0, 0, 0, 0]
Day 2: [0, 0, 0, 0, 1, 1, 1, 0]
Day 3: [0, 1, 1, 0, 0, 1, 0, 0]
Day 4: [0, 0, 0, 0, 0, 1, 0, 0]
Day 5: [0, 1, 1, 1, 0, 1, 0, 0]
Day 6: [0, 0, 1, 0, 1, 1, 0, 0]
Day 7: [0, 0, 1, 1, 0, 0, 0, 0]

Example 2:

Input: cells = [1,0,0,1,0,0,1,0], N = 1000000000
Output: [0,0,1,1,1,1,1,0]
 

Note:

cells.length == 8
cells[i] is in {0, 1}
1 <= N <= 10^9
*/

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        // Step: 1
        // Finding out k & l
        // Keep simulating till we find a repetition
        string currState = "", nextState;
        int i, count = 1, k, l, offset;
        // An unordered map to track repetition
        // Key is the state and the value is the state number
        unordered_map<string, int> m;
        // A vector to track the actual states
        vector<string> states;
        
        // Result vector
        vector<int> res;
        
        for(i = 0; i < 8; i++)
            currState += to_string(cells[i]);
        
        states.push_back(currState);
        m[currState] = 0;
        // Simulate till we get a repetition
      
        while(count<=N){
            nextState="0";
            
            for(i=1;i<7;i++){
                if(currState[i-1]==currState[i+1])
                    nextState+="1";
                else
                    nextState+="0";
            }
            nextState+="0";
            
            //Check for repetition
            
            //if there is no repetition
            if(m.find(nextState)==m.end()){
                m[nextState]=states.size();
                states.push_back(nextState);
                currState=nextState;
                count++;
                continue;
            }
            //if there is repetition
            break;
                
        }
        
        // All linear
            if(count>N){
                for(i=0;i<8;i++)
                res.push_back(currState[i]-'0');
                
                return res;
            }
        
        // Cycle
        k=m[nextState]; 
        l=count-k;
        
        offset=(N-k)%l;
        
        // State to be returned is states[k+offset]
        
        for(i=0;i<8;i++)
            res.push_back(states[k+offset][i]-'0');
        
        return res;
        
        
        
    }
};
