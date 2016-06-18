#include <iostream>
#include <cstdio>
using namespace std;

enum direction{
	TOP,
	BOTTOM,
	LEFT,
	RIGHT
};

pair<int, int> compute_position(int s, int p){
	int x,y;
	direction dir;
	x = y = s / 2 + 1;
	dir = TOP;

	if(p == 1)
		return make_pair(x,y);

	long long current = 1;
	int increment = 1;
	int count = 2;

	while(true){

		if(current + increment >= p)
			increment = p - current;

		count--;
		current += increment;
		switch(dir){
			case TOP:
				x += increment;
				dir = LEFT;
				break;
			case BOTTOM:
				x -= increment;
				dir = RIGHT;
				break;
			case LEFT:
				y -= increment;
				dir = BOTTOM;
				break;
			case RIGHT:
				y += increment;
				dir = TOP;
				break;
		}
		if(count==0){
			increment++;
			count = 2;
		}
		if(current == p)
			break;	
	}
	return make_pair(x,y);
}

int main(){
	int size, p;
	while(scanf("%d %d", &size, &p), (size || p)){

		pair<int, int> result = compute_position(size, p);

		cout<<"Line = "<<result.first<<", column = "<<result.second<<"."<<endl;
	}
	return 0;
}

/*#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int a[100005][100005];

int main(){
	int mid, count, i,j;
	int SZ,p;

	while(scanf("%d %d",&SZ, &p), (SZ||p)){
	mid = SZ/2 + 1;
	count=1;
	i = mid;	j=mid;
	a[mid][mid] = count;
	count++;
	while(count != p){
		i--;
		a[i][j] = count++;
		
		while((j!=i) && (count!=p))
			a[i][--j] = count++;

		while((i+j != SZ+1) && (count!=p)){
			a[++i][j] = count++;
		}

		while((j!=i) && (count!=p))
			a[i][++j] = count++;
		
		while((i+j != SZ+1) && (count!=p)){
			a[--i][j] = count++;
		}

	}

	printf("Line = %d, column = %d\n",SZ+1-i, SZ+1-j );	
	}
	return 0;
}*/