class Solution {
public:
    int compress(vector<char>& chars) {
        int sp = 0;
        int fp = 0;
        char currChar = chars[0];
        int count = 0;

        while(sp < chars.size() and fp < chars.size()){
            if(currChar == chars[fp] and fp != chars.size() - 1){
                count++;
            }
            else{
                if(fp == chars.size() - 1 and chars[fp] == currChar) count++; 
                std::cout << currChar << endl;

                chars[sp] = currChar;
                sp++;

                if(count == 1){
                    if(fp == (chars.size() - 1) and chars[fp] != currChar){
                        chars[sp] = chars[fp];
                        sp++;
                    } 
                    currChar = chars[fp];
                    fp++;
                
                    continue;
                }

                string fc = to_string(count);

                for(auto i {0uz}; i < fc.size(); i++){
                    chars[sp] = fc[i];
                    if(sp + 1 < chars.size()) sp++;
                }
                
                if(fp == (chars.size() - 1) and chars[fp] != currChar){
                    chars[sp] = chars[fp];
                    sp++;
                } 

                count = 1;
                currChar = chars[fp];
            }
            fp++;
        }

        return sp;
    }
};