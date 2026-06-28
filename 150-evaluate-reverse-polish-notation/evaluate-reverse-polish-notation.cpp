class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> processTokens;
        
        for(std::string c : tokens){
            int res, one, two;

            if(c == "+" || c == "-" || c == "*" || c == "/"){
                one = processTokens.top();
                processTokens.pop();
                two = processTokens.top();
                processTokens.pop();
            }

            if(c == "+"){
                res = one + two;
            }
            else if(c == "-"){
                res = two - one;
            }
            else if(c == "/"){
                res = two / one;
            }
            else if(c == "*"){
                res = two * one;
            }
            else{
                res = std::stoi(c);
            }
            processTokens.push(res);
        }

        return processTokens.top();
    }
};