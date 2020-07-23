// Author: Half-Blood_Prince

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, oo = 1e9;

int arr[N],n, q, t, a, b;
int seg[4*N];

void Build(int ind, int l, int r)
{
	if(l==r)
	{
		seg[ind] = arr[l];
		return;
	}
	int mid = l + (r-l)/2;
	int lf = ind*2+1;
	int rt = ind*2+2;
	Build(lf, l, mid);
	Build(rt, mid+1, r);
	seg[ind] = min(seg[lf], seg[rt]);
}

int getAns(int x, int y, int ind, int l, int r)
{
	if(r<x || l>y)	return oo;
	if(l>=x && r<=y)	return seg[ind];
	int mid = l + (r-l)/2;
	int lf = ind*2+1;
	int rt = ind*2+2;

	int r1 = getAns(x, y, lf, l, mid);
	int r2 = getAns(x, y, rt, mid+1, r);
	return min(r1,r2);
}

void Update(int x, int v, int ind, int l, int r)
{
	if(x<l || x>r)	return;
	if(l==r)
	{
		seg[ind] = v;
		return;
	}
	int mid = l + (r-l)/2;
	int lf = ind*2+1;
	int rt = ind*2+2;
	Update(x, v, lf, l, mid);
	Update(x, v, rt, mid+1, r);
	seg[ind] = min(seg[lf], seg[rt]);
}

int main()
{
	cin >> n;
	for(int i=1 ; i<=n ; ++i)
	{
		cin >> arr[i];
	}

	Build(0, 1, n);

	int q;
	cin >> q;
	while(q--)
	{

		cin >> t >> a >> b;

		if(t==1)	cout << getAns(a, b, 0, 1, n) << endl;
		else Update(a, b, 0, 1, n);
	}
}
