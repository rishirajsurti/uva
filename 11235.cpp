#include <bits/stdc++.h>
using namespace std;

const int N = 200048;
int begin[N], end[N], v[N];

inline int min(int a, int b){ return a < b ? a : b; }
inline int max(int a, int b){ return a > b ? a : b; }

struct node{
	int b, e, m, v; // begin, end, middle , value;
	node *left, *right;
} nodes[N << 2];

void init(node *n, int idx, int b, int e){
	n->b = b;
	n->e = e;
	n->m = ((n->b) + (n->e)) / 2;
	int z = v[n->m];

	if(b!=e){
		n->left = nodes + (idx << 1) + 1; // +1 because 0 indexed
		n->right = nodes + (idx << 1) + 1 + 1;
		init(n->left, n->left - nodes, n->b, n->m);
		init(n->right, n->right-nodes, n->m + 1, n->e);

		n->v = max(n->left->v, n->right->v);
		n->v = max(n->v, min(end[z], n->e) - max(begin[z], n->b) + 1); 

	} else{
		n->left = n->right = NULL;
		n->v = 1;
	}
}

int query(node *n, int i, int j){
	if(i > n->e || j < n->b) return 0;
	if(i <= n->b && j >= n->e) return n->v;

	int z = max(query(n->left, i, j), query(n->right, i, j));
	return max(z, min(end[v[n->m]], j) - max(begin[v[n->m]],i) + 1);
}

int main(){
	for(int n,q; scanf("%d %d", &n, &q) == 2; ){
		for(int i = 0, p = 200001; i < n; i++){
			scanf("%d", &v[i]);
			v[i] += 100000;
			//remember values are in non decreasing order

			//if the sequence breaks;
			//consider 1 1 1 1 1 2 2 2 3 3 3

			if(v[i] != p){ // if current is not equal to previous value
				begin[v[i]] = i; // store index of the "value";
				end[p] = i-1; // the previous value;
			}
			p = v[i]; // update p to last value;
		}

		end[v[n-1]] = n-1;
		init(nodes, 0, 0, n-1);
		for(int a, b, i = 0; i<q; i++){
			scanf("%d %d", &a, &b);
			printf("%d\n", query(nodes, --a, --b));
		}
	}
	return 0;
}
/*#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;


class SegmentTree{	//segment tree is stored like a heap array

private:
	vi st, A;
	int n;
	int left(int p) {return p << 1; }
	int right(int p) { return (p << 1) + 1; }

	//p is the index of the node of tree as in the array
	void build( int p, int L, int R){
		if ( L == R )
			st[p] = A[L];		//store  the index
		else{				//recursively compute the values
			build(left(p) , L , (L+R) / 2);
			build(right(p), (L+R)/2 + 1, R);
			//int p1 = st[left(p)], p2 = st[right(p)];
			//st[p] = (A[p1] <= A[p2]) ? p1 : p2;
			map<int, int> m;
			int i, maxv = -1;
			for(i=L; i<=R; i++){
				++m[A[i]];
				if(m[A[i]] > maxv) st[p] = A[i];		
			}
		} } 

	int rmq(int p, int L, int R, int i, int j){

		if( i > R || j < L)	return -1; //current segment outside query range
		if( L >= i && R <= j) return st[p]; // completely inside query range

		int p1 = rmq(left(p), L, (L+R)/2, i , j);
		int p2 = rmq(right(p), (L+R)/2 + 1, R, i, j);

		if(p1 == -1)	return p2;
		if(p2 == -1)	return p1;
		return (A[p1] <= A[p2]) ? p1 : p2;
	}	

	int update_point(int p, int L, int R, int idx, int new_value){
		int i = idx, j = idx;

		// if the current interval does not intersect
		// the update interval, return this st node value!

		if( i > R || j < L)
			return st[p];

		// if the current interval is included in the update range,
		//update that st[node]
		if (L == i && R == j){
			A[i] = new_value;	//update underlying array
			return st[p] = L; // this index
		}

		//compute the minimum position in the 
		//left and right part of the interval
		int p1, p2;
		p1 = update_point(left(p), L, (L+R)/2, idx, new_value);
		p2 = update_point(right(p), (L+R)/2 + 1, R, idx, new_value);

		return st[p] = (A[p1] <= A[p2]) ? p1 : p2 ;
	}

public:
	SegmentTree(const vi &_A){
		A = _A;	n = (int)A.size(); //copy content for local usage
		st.assign(4 * n, 0);	//create large enough vector of zeroes
		build(1, 0, n - 1);
	}

	int rmq(int i, int j){	
		return rmq(1, 0, n-1, i, j); //overloading
		}

	int update_point(int idx, int new_value){
		return update_point(1, 0, n - 1, idx, new_value);
	}
};
int main(){
	int n,q;
	while(scanf("%d", &n), n){
		scanf("%d", &q);
		vi a(n);
		int i,j, x,y;
		for(i=0; i<n; scanf("%d", &a[i++]));
		SegmentTree st(a);
		for(i=0; i<q; i++){
			scanf("%d %d", &x, &y);

		}
	}
}
*/

/*#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
	
typedef vector<int> vi;
 
int arr[100005];

class SegmentTree{

private:
	vi st, A;
	int n, max;

	int left(int p){ return (p << 1); }
	int right(int p){ return ((p << 1) + 1); }

	void build(int p, int L, int R){
		if( L == R ){
			st[p] = L;
		}
		else{

			build(left(p), L, (L+R)/2);
			build(right(p), 1+(L+R)/2, R);
			int p1 = st[left(p)], p2 = st[right(p)];
			st[p] = (A[p1] >= A[p2]) ? p1 : p2;
		}}

	int rmq(int p, int L, int R, int i, int j){

		if( i > R || j < L ) return -1;

		if( L >= i && R <= j) return st[p];

		int p1 = rmq(left(p), L, (L+R)/2, i, j);
		int p2 = rmq(right(p), 1+(L+R)/2, R, i, j);

		if(p1 == -1)	return p2;
		if(p2 == -1)	return p1;

		return (A[p1] >= A[p2]) ? p1 : p2;
	}

public:
	SegmentTree(const vi &_A){
		A = _A;
		n = (int)A.size();
		st.assign(4*n, 0);
		build( 1, 0, n - 1);
	}

	int rmq(int i, int j){
		return rmq( 1, 0, n-1, i , j);
	}
};

int main(){
	int n, q, i, j, a, b,prev, cur,count;

	while(scanf("%d",&n),n){
		scanf("%d", &q);

		scanf("%d", &cur);
		count=1;
		arr[0] = count++;
		for(i=1; i<n; i++){
			prev = cur;
			scanf("%d",&cur);
			if(cur != prev)
				count = 1;
			
			arr[i] = count++;
		}
		for(i=0; i<n; i++)
			printf("%d ", arr[i] );
		printf("\n");
		vi A(arr, arr+n);
		SegmentTree st(A);

		for(i=0; i<q; i++){
			scanf("%d %d", &a, &b);
			printf("%d\n", st.rmq(a-1,b-1) );
		}

	}
}*/