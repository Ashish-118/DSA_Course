class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int ans=0;
        sort(begin(cost),end(cost));

        int n=cost.size();
        int c=1;
        for(int i=n-1; i>=0; i--){
            if(c<=2){
                ans+=cost[i];
            }else{
                c=0;
            }
            c++;
        }

        return ans;
    }
};