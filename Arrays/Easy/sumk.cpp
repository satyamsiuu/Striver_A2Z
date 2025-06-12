#include<bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int> &nums, int k)
{
    long long sum = 0;
        int n = nums.size();
        int c = 0;
        int t = 0;
        map<long long,int> premap;
        for(int i =0;i<n;i++)
        {  
            sum+= nums[i];
            if(sum==k)
            {
                t++;
                c++;
            }
            else
            {   
                long long res = sum - k;
                if(premap.find(res)!=premap.end())
                    c++;
            }
            if(premap.find(sum)==premap.end())
                premap[sum] = i;
            else
                c+=t-1;
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