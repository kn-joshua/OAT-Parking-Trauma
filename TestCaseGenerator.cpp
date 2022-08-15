#include <bits/stdc++.h>
using namespace std;
int lookup[101][101]; //as N and H are bounded by 100
void preprocess(vector <int> arr, int n)
{
    for (int i = 0; i < n; i++)
    lookup[i][0] = i;
    for (int j = 1; (1 << j) <= n; j++)
    {
        for (int i = 0; (i + (1 << j) - 1) < n; i++)
        {
            if (arr[lookup[i][j - 1]] < arr[lookup[i + (1 << (j - 1))][j - 1]])
            lookup[i][j] = lookup[i][j - 1];
            else
            lookup[i][j] = lookup[i + (1 << (j - 1))][j - 1];
        }
    }
}
int query(vector <int> arr, int L, int R)
{
    int j = (int)log2(R - L + 1);
    if (arr[lookup[L][j]] <= arr[lookup[R - (1 << j) + 1][j]])
    return arr[lookup[L][j]];
    else
    return arr[lookup[R - (1 << j) + 1][j]];
}
int solve(int n,int h, int k, vector <int> a)
{
    preprocess(a,n); //generating the RMQ data structure
    vector <int> s(n);
    s[0]=a[0];
    for(int i=1;i<n;++i)
    s[i]=s[i-1]+a[i]; //generating sum prefix array
    int ans=INT_MAX;
    for(int i=0;i<=n-k;++i)
    {
        int x=query(a,i,i+k-1);
        if(i==0)
        ans=min(ans,s[i+k-1]-k*x);
        else
        ans=min(ans,s[i+k-1]-s[i-1]-k*x);
    }
    return ans;
}
int main()
{
    freopen ("TestCases.in", "w", stdout);
    int maxN=100;
    srand(time(NULL));
    int t=1+rand()%100;
    cout<<t<<endl;
    vector <int> ans(t);
    for(int i=0;i<t;++i)
    {
        int n= 1 + rand()%(maxN);
        int h= 1 + rand()%(maxN); 
        int k= 1 + rand()%(n); // as k<=n always
        cout<<n<<" "<<h<<" "<<k<<endl;
        vector <int> a(n);
        for(int j=0;j<n;++j)
        {
            a[j]=1+rand()%h;
            cout<<a[j]<<" ";
        }
        ans[i]=solve(n,h,k,a);
        cout<<endl;
    }
    fclose(stdout);
    freopen("Answers.in","w",stdout);
    for(int i=0;i<t;++i)
    cout<<ans[i]<<endl;
    fclose(stdout);
}