#include<bits/stdc++.h>
using namespace std;
void nextPermutation(vector<int>& nums) 
{
    auto start = nums.begin();
    int n = nums.size();
    int i;
    for(i = n-2;i>=0;i--)
    {
        if(nums[i]<nums[i+1])
            break;
    }
    if(i>=0)
    {
        int k = i;
        for(i = n-1;i>k;i--)
        {
            if(nums[k]<nums[i])
            {
                swap(nums[i],nums[k]);
                break;
            }
        } 
        start+=k+1;
    }
    reverse(start,nums.end());
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];

    nextPermutation(a);

    for(int i: a)
        cout<<i<<" ";
    cout<<"\n";
    return 0;
}