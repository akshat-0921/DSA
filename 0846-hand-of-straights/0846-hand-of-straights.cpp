class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        priority_queue<int,vector<int>,greater<>>q;
        int n = hand.size();
        if(n%groupSize) return false;

        for(auto it:hand) q.push(it);
        int p = n/groupSize;
        for(int i=0;i<p;i++){
            vector<int>rem;
            int num = q.top();q.pop();
            int k = groupSize-1;
            while(!q.empty()&&k>0){
                int t = q.top();q.pop();
                if(num+1==t){
                    k--;
                    num = t;
                }
                else if(num==t){
                    rem.push_back(t);
                }
                else return false;
            }
            for(auto it:rem) q.push(it);
            
        }
        return q.empty() ? true : false;
    }
};