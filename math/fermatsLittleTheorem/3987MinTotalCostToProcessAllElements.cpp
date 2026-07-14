#define mod 1000000007
class Solution {
public:

    int binaryPow(long long a,int b){
        long long ans=1;

        while(b!=0){
            if(b&1){
                ans=(ans*a)%mod;
            }

            a=(a*a)%mod;
            b>>=1;
        }

         
        return ans;
    }
    int minimumCost(vector<int>& nums, int k) {
        long long count=0;

        long long token=k;

        for(int i=0; i<nums.size(); i++){
            if(token>=nums[i]){
                token-=nums[i];
            }else{
                int n=nums[i]-token;
                int x=n/k+(n%k==0?0:1);

                token=(1LL*k*x)-n;
                count=(count+x)%mod;
            }
        }

        return (((count*(count+1)%mod))*(binaryPow(2,mod-2)%mod))%mod;
    }
};