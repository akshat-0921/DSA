class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int hash_code[3]={0};
        int count_sub=0;
        int l=0,r=0;
        while(r<n){
            hash_code[s[r]-'a']++;
            while(hash_code[0]>=1 && hash_code[1]>=1 && hash_code[2]>=1){
                count_sub+=(n-r);
                hash_code[s[l]-'a']--;
                l++;

            }
            r++;
        }
    return count_sub;   
    }
};