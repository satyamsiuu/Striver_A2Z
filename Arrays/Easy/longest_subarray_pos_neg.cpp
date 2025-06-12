#include<bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int> &nums, int k)
{
    int n = nums.size();
    int maxlen = 0;
    long long sum = 0;
    map<long long,int> presum;
    for(int i=0;i<n;i++)
    {
        sum+=nums[i];
        if(sum==k)
            maxlen = max(maxlen,i+1);
            
        long long rem = sum-k;

        if(presum.find(rem)!=presum.end())
        {
            int len = i-presum[rem];
            maxlen = max(maxlen,len);
        }
        if(presum.find(sum)==presum.end())
            presum[sum] = i;
    }
    return maxlen;
}

int main()
{
    int n,k;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>k;
    cout<<longestSubarray(a,k)<<endl;
}