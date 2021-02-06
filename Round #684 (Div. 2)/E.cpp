
#include<iostream>
#include<cstdio>
#include<string>
#include<ctime>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<stack>
#include<climits>
#include<queue>
#include<map>
#include<set>
#include<sstream>
#include<cassert>
#include<bitset>
using namespace std;
 
typedef long long LL;
 
typedef unsigned long long ull;
 
const int inf=0x3f3f3f3f;
 
const int N=2e5+100;
 
struct Node
{
	int l,r;
	int mmin,mmax,lazy;
	LL sum,len;
}tree[N<<2];
 
void update(int k,int val)
{
	tree[k].mmax=tree[k].mmin=tree[k].lazy=val;
	tree[k].sum=tree[k].len*val;
}
 
void pushup(int k)
{
	tree[k].mmax=max(tree[k<<1].mmax,tree[k<<1|1].mmax);
	tree[k].mmin=min(tree[k<<1].mmin,tree[k<<1|1].mmin);
	tree[k].sum=tree[k<<1].sum+tree[k<<1|1].sum;
}
 
void pushdown(int k)
{
	if(tree[k].l==tree[k].r)
		return;
	if(tree[k].lazy)
	{
		int lz=tree[k].lazy;
		tree[k].lazy=0;
		update(k<<1,lz);
		update(k<<1|1,lz);
	}
}
 
void build(int k,int l,int r)
{
	tree[k].l=l;
	tree[k].r=r;
	tree[k].lazy=0;
	tree[k].len=r-l+1;
	if(l==r)
	{
		int num;
		scanf("%d",&num);
		tree[k].mmin=tree[k].mmax=tree[k].sum=num;
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	pushup(k);
}
 
void update(int k,int l,int r,int val)
{
	if(tree[k].mmin>=val)
		return;
	if(tree[k].l>r||tree[k].r<l)
		return;
	if(tree[k].l>=l&&tree[k].r<=r&&tree[k].mmax<val)
	{
		update(k,val);
		return;
	}
	pushdown(k);
	update(k<<1,l,r,val);
	update(k<<1|1,l,r,val);
	pushup(k);
}
 
int query(int k,int l,int r,int& val)
{
	if(tree[k].mmin>val)
		return 0;
	if(tree[k].l>r||tree[k].r<l)
		return 0;
	if(tree[k].l>=l&&tree[k].r<=r&&tree[k].sum<=val)
	{
		val-=tree[k].sum;
		return tree[k].len;
	}
	pushdown(k);
	int ans1=query(k<<1,l,r,val);
	int ans2=query(k<<1|1,l,r,val);
	return ans1+ans2;
}
 
int main()
{
#ifndef ONLINE_JUDGE
//  freopen("data.in.txt","r",stdin);
//  freopen("data.out.txt","w",stdout);
#endif
//  ios::sync_with_stdio(false);
	int n,m;
	scanf("%d%d",&n,&m);
	build(1,1,n);
	while(m--)
	{
		int op,x,y;
		scanf("%d%d%d",&op,&x,&y);
		if(op==1)
			update(1,1,x,y);
		else
			printf("%d\n",query(1,x,n,y));
	}
}