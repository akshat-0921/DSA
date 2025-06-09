class Solution {
public:
    int countPrimes(int n) {
        vector<int> a(n,1);
        int c=0;
        if(n==0 || n==1)return 0;
        for(int i=2;i*i<n;i++){
            if(a[i]==1){
                for(int j=i*i;j<n;j+=i){
                  a[j]=0;
                }
            }
        }
        
        for(int i=2;i<n;i++){
            if(a[i]==1){
                c++;
            }
        }

      return c;

        
    }
};