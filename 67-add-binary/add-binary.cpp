class Solution {
public:
    string addBinary(string a, string b) {
        int count = 0;
        int carry = 0;
        std::string res = "";

        while(count < a.size() || count < b.size()){
            int aNum = !(a.size() <= count || a[a.size() - (count + 1)] == '0');
            int bNum = !(b.size() <= count || b[b.size() - (count + 1)] == '0');

            int total = aNum + bNum + carry;

            if(total == 3){
                carry = 1;
                res = "1" + res;
            }
            else if(total == 2){
                carry = 1;
                res = "0" + res;
            }
            else if(total == 1){
                carry = 0;
                res = "1" + res;               
            }
            else{
                carry = 0;
                res = "0" + res;
            }
            count++;
        }

        if(carry == 1) res = "1" + res;

        return res;

    }
};