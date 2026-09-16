class Solution {
public:
    int numberOfSets(int n,int k){
        const long long M=1e9+7;
        vector<long long>d(2*k+1); d[0]=1;
        for(int i=1;i<=n+k-1;i++)
            for(int j=min(i,2*k);j;j--) d[j]=(d[j]+d[j-1])%M;
        return d[2*k];
    }
};