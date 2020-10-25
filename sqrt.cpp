#include <bits/stdc++.h>
using namespace std;

//https://vjudge.net/contest/398640#problem/D


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

ll n,m,k,res,t,q,len;
char s[maxn];

void solve(int oo) {
      scanf("%s%d",s,&q);
      n=strlen(s);
      len=300;
      int b[n];
      int ok[n];
      for(int i=0;i<n;++i){
            b[i]=0;
            ok[i]=i%len==0;
      }
      int kk=0;
      if(kk==0){
            printf("Case %d:\n",oo);
            kk++;
      }
      for(int j=1;j<=q;++j){
            char c[2];
            scanf("%s",c);
            if(c[0]=='I'){
                  int l,r;
                  scanf("%d%d",&l,&r);
                  for(int i=l-1;i<r;) {
                        if (ok[i] && i + len - 1 < r) {
                              b[i/len]++;
                              i+=len;
                        }
                        else{
                              if(s[i]=='0'){
                                    s[i]='1';
                                    i++;
                              }
                              else{
                                    s[i]='0';
                                    i++;
                              }
                        }
                  }
            }
            else{
                  int po;
                  scanf("%d",&po);
                  //cout<<b[po/len];
                  if(b[(po-1)/len]%2==0){
                        printf("%d\n",s[po-1]-48);
                  }
                  else{
                        if(s[po-1]=='0'){
                              printf("%d",1);
                              printf("\n");
                        }
                        else{
                              printf("%d",0);
                              printf("\n");
                        }
                  }
            }
      }
}

int main(){
      scanf("%d", &t);
      int kk=t;
      while(t--) {
            solve(kk-t);
      }
}
