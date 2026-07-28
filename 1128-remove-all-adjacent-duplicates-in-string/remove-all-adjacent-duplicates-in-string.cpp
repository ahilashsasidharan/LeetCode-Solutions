class Solution {
public:
    string removeDuplicates(string s) {
        std::stack<char> chars;

        for(char c : s){
            if(!chars.empty() && chars.top() == c){
                chars.pop();
            }
            else{
                chars.push(c);
            }
        }

        std::string res = "";

        while(!chars.empty()){
            res += chars.top();
            chars.pop();
        }

        std::reverse(res.begin(), res.end());

        return res;
    }
};