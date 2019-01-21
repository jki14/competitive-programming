//10184789    NKHelloWorld    4047    Accepted    5980K    329MS    G++    2373B    2012-05-11 20:59:20
 #include <cstdio>
 #include <iostream>
 using namespace std;
 #define MAXN 210000
 
 int a[MAXN],sum[MAXN];
 int n,m,k;
 
 struct SEGTREE
 {
     int l,r,maxval,det;
 }tree[MAXN*4];
 
 void buildsegtree(int root,int l,int r)
 {
     tree[root].l = l;    tree[root].r = r;
     tree[root].det = 0;
     if(l == r)
     {
         tree[root].maxval = sum[l];
         return ;
     }
     int mid = (l+r)>>1;
     buildsegtree(root<<1,l,mid);
     buildsegtree(root<<1|1,mid+1,r);
     tree[root].maxval = max(tree[root<<1].maxval,tree[root<<1|1].maxval);
 }
 
 void pushdown(int root)
 {
     if(tree[root].det == 0)    return ;
     tree[root].maxval += tree[root].det;
     if(tree[root].l != tree[root].r)
     {
         tree[root<<1].det += tree[root].det;
         tree[root<<1|1].det += tree[root].det;
     }
     tree[root].det = 0;
 }
 
 void update(int root,int l,int r,int det)
 {
     if(tree[root].l == l && tree[root].r == r)
     {
         tree[root].det += det;
         return ;
     }
pushdown(root);
     int mid = (tree[root].l + tree[root].r)>>1;
     if(r <= mid)
         update(root<<1,l,r,det);
     else if(l >mid)
         update(root<<1|1,l,r,det);
     else
     {
         update(root<<1,l,mid,det);
         update(root<<1|1,mid+1,r,det);
     }
     pushdown(root<<1);
     pushdown(root<<1|1);
     tree[root].maxval = max(tree[root<<1].maxval,tree[root<<1|1].maxval);
 }
 
 int query(int root,int l,int r)
 {
     pushdown(root);
     if(tree[root].l == l && tree[root].r == r)
     {
         return tree[root].maxval;
     }
     int mid = (tree[root].l + tree[root].r)>>1;
     if(r <= mid)
         return query(root<<1,l,r);
     else if(l >mid)
         return query(root<<1|1,l,r);
     else
         return max(query(root<<1,l,mid),query(root<<1|1,mid+1,r));
 }
 
 void edit(int x,int y)
 {
     int det = y - a[x];
     a[x] = y;
     int ll = x-k+1;
     if(ll <1)    ll = 1;
     int rr = x;
     if(x > n - k +1)    rr = n-k+1;
     update(1,ll,rr,det);
 }
 
 int main()
 {
     int totcase,i,j;
     scanf("%d",&totcase);
     while(totcase--)
     {
         scanf("%d%d%d",&n,&m,&k);
         for(i=1;i<=n;i++)
         {
             scanf("%d",&a[i]);
         }
         sum[1] = 0;
         for(i=1;i<=k;i++)    sum[1] += a[i];
         for(i=2;i<=n-k+1;i++)    sum[i] = sum[i-1] - a[i-1] + a[i+k-1];
         buildsegtree(1,1,n-k+1);
         int p,x,y;
         while(m--)
         {
             scanf("%d%d%d",&p,&x,&y);
             if(p==0)
             {
                 edit(x,y);
             }
             else if(p ==1 )
             {
                 int xx = a[x],yy = a[y];
                 edit(y,xx);
                 edit(x,yy);
             }
             else
             {
                 printf("%d\n",query(1,x,y-k+1));
             }
         }
     }
     return 0;
 }
