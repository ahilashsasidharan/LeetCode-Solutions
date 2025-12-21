class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int size = isConnected.size();
        vector<bool> visited(size, false);
        int count = 0;

        for(auto i{0uz}; i < visited.size(); i++){
            if(visited[i]){
                continue;
            }
            stack<int>  toVisit;
            toVisit.push(i);
            count++;

            while(!toVisit.empty()){
                int c = toVisit.top();
                toVisit.pop();
                if(visited[c]) continue;
                visited[c] = true; 
                for(auto j{0uz}; j < isConnected[c].size(); j++){
                    if(visited[j]) continue;
                    
                    if(isConnected[c][j] == 1) toVisit.push(j);
                }
            }
        }

        return count;
    }
};