class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;

        string goalTwo = goal + goal;

        if(goalTwo.find(s) != std::string::npos){
            return true;
        }

        return false;
    }
};