class Solution {
public:
    void carry(string & str, const string &max){
        for(int i =0; i < max.length(); i++){
            if(str[i] <= max[i]) return;
            str[i] = '0';
            if(i+1 < max.length()) str[i+1]++;
        }
    }

    vector<string> letterCombinations(string digits) {

        if(digits == "") return {};
        
        unordered_map<char, string> numToLet{};
        numToLet['2'] = "abc"; numToLet['3'] = "def"; numToLet['4'] = "ghi";
        numToLet['5'] = "jkl"; numToLet['6'] = "mno"; numToLet['7'] = "pqrs";
        numToLet['8'] = "tuv"; numToLet['9'] = "wxyz";

        int resultLen = 1;  
        for(const char c: digits) resultLen *= numToLet[c].length();

        string maxCombo = ""; 
        for(const char c: digits) maxCombo += to_string(numToLet[c].length()-1);
        vector<string> result(resultLen, string(digits.length(),'0'));
        string comboIdxs = string(digits.length(),'0');

        for(int i = 1; comboIdxs != maxCombo; ++i){
            comboIdxs[0]++;
            carry(comboIdxs, maxCombo);
            result[i] = comboIdxs;
        }
        for(int i = 0; i < result.size(); ++i) 
            for(int j = 0; j < digits.length(); ++j)
                result[i][j] = numToLet[digits[j]][result[i][j]-'0'];

        return result;

    }
};