#include<bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int> &nums, int k)
{
    int n = nums.size();
    int i = 0,j=0;
    int sum = 0;
    int maxlen = 0;
    while(j<n && i<n)
    {
        if(j==n-1 && sum<k)
            break;

        if(sum<k)
        {
            sum+=nums[j];
            j++;
        }
        else if(sum>k)
        {
            sum-=nums[i];
            i++;
        }
        else
        {
            maxlen = max(maxlen,j-i+1);
            j++;
            sum+=nums[j];
        }
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