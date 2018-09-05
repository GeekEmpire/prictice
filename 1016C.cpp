#include<bits/stdc++.h>
#define maxn 1000003

using namespace std;
typedef long long ll;
ll s[maxn],a[2][maxn],p[2][maxn],n,ans,r,d;

int main(){
    cin >> n;
    for (int i=0;i<2;i++) for (int j=0;j<n;j++) scanf("%d",&a[i][j]);
    for (int i=n-1;i>=0;i--) s[i]=s[i+1]+a[0][i]+a[1][i];
    for (int i=n-1;i>=0;i--) p[0][i]=p[0][i+1]+s[i+1]+((n-i)*2-1)*a[1][i];
    for (int i=n-1;i>=0;i--) p[1][i]=p[1][i+1]+s[i+1]+((n-i)*2-1)*a[0][i];
    for (int i=0;i<n;i++){
        ans=max(ans,p[i&1][i]+s[i]*i*2+r);
        r+=d*a[i&1][i]; d++;
        r+=d*a[(i+1)&1][i]; d++;
    }
    cout << ans << endl;
    return 0;
}