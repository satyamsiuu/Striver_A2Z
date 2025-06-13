#include<bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int> &nums, int k)
{
    long long sum = 0;
        int n = nums.size();
        int c = 0;
        map<long long,int> premap{{0,1}};
        for(int i =0;i<n;i++)
        {  
            sum+= nums[i];
            if(premap.find(sum-k)!=premap.end())
                c+=premap[sum-k];

            premap[sum]++;
        }
        return c;
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