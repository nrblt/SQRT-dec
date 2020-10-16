#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <ctime>
#include <cmath>

using namespace std;

#define re return 0;
#define ll long long
#define str string
#define INF (int)(1e9+7)
#define pb push_back
//#define mp make_pair
#define F first
#define S second
#define fr(ii, ee) for (int ii = 0; ii < ee; ii++)
#define maxn (ll)(1e5+7)

ll n,m,k,res,t;

void solve(int oo){

    scanf("%d", &n);
    scanf("%d", &k);

    vector<int> a;
    for(int i=1;i<=n;++i){
        int pp;
        scanf("%d", &pp);
        a.pb(pp);
    }
    int len = (int) sqrt (n + .0) + 1;//sqrt of n
    vector<int> b (len);//our blocks 
    for(int i=0;i<n;++i){
        b[i / len] =INF;//if we are finding the minimums in l r,we write INF ,if maximum write -INF,if numbers of something write 0
    }
    for (int i=0; i<n; ++i) {
        b[i / len] = min(b[i / len], a[i]);//building our blocks
    }

    for (int j=1;j<=k;++j) {
        int l, r;
        scanf("%d", &l);
        scanf("%d", &r);
        if(j==1){
            printf("Case %d",oo);
            printf(":\n");
        }
        int sum = INF;
        for (int i=l-1; i<r; ) {
            if (i % len == 0 && i + len - 1 <= r) {//if they have fully blocks between l and r we are taking whole blocks value
                sum = min(b[i / len], sum);
                i += len;//then iterating blocks length
 
            } else {
                sum = min(sum, a[i]);//if they are not in fully blocks we must just take comparing with arrays element
                ++i;//then just i++ only
            }
        }
        printf("%d",sum);//answer is sum
        printf("\n");
    }

}
int main(){
    scanf("%d", &t);
    int kk=t;
    while(t--) {
        solve(kk-t);
    }
}
