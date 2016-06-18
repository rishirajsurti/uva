#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
int main(){
	int c;
	scanf("%d", &c);
	while(c--){
		int n, t, m;
		scanf("%d %d %d", &n, &t, &m);
		int i,j;
		priority_queue<ii, vector<ii>, greater<ii> > left, right, ans;
		char pos[100];
		int arr_time;
		for(i=0; i<m; i++){
			scanf("%d %s", &arr_time, pos);
			if(strcmp(pos, "left")==0)
				left.push(ii(i,arr_time));
			else if(strcmp(pos,"right")==0)
				right.push(ii(i,arr_time));
		}
		int cur_time = 0;
		int cur_pos = 0; //left;

		while(!left.empty() && !right.empty()){
		//	printf("pos %d time %d\n",pos, cur_time );
			if(cur_pos == 0){
				//ferry on the left
				ii left_car = left.top();
				ii right_car = right.top();

				if(left_car.second <= right_car.second){
				//if left car arrived before right car
				//add waiting time
				if(left_car.second > cur_time)
					cur_time += ( left_car.second - cur_time);
				//load the ferry with n cars
				//ans_time = arr_time + t;
				for(i=0; i<n && !left.empty(); i++){
					ii take_car = left.top();
					if(take_car.second <= cur_time){
						ans.push(ii(take_car.first, cur_time+t));
						left.pop();
					}
				}
					// reached other side
					cur_time += t; 
					cur_pos = 1 - cur_pos; 
				}
				else{
					//if right car arrived before left car
					//ferry will go to the right first
					cur_time += (right_car.second + t);
					cur_pos = 1 - cur_pos;			
				}
			}
			else if(cur_pos == 1){
				//ferry on the right
				ii left_car = left.top();
				ii right_car = right.top();

				if(right_car.second <= left_car.second){
					//if right car arrived before left car
					//add waiting time
					if(right_car.second > cur_time)
						cur_time += (right_car.second - cur_time);

					for(i=0; i<n && !right.empty(); i++){
						ii take_car = right.top();
						if(take_car.second <= cur_time){
							ans.push(ii(take_car.first, cur_time+t));
							right.pop();
						}
					}

					// reached other side
					cur_time += t; 
					cur_pos = 1 - cur_pos; 
				}
				else{
					//if left car arrived before right car
					cur_time += (left_car.second + t);
					cur_pos = 1 - cur_pos;
				}
			}
		}

		// remaining cars
		while(!left.empty()){
			ii rem = left.top();
			int at = rem.second;
			
			if(cur_pos == 1){
				cur_time += t;
				cur_pos = 1 - cur_pos;
			}

			if(at > cur_time){
				cur_time += (cur_time - at);
			}

			for(i=0; i<n && !left.empty(); i++){
				rem = left.top();
				if(rem.second <= cur_time){
					ans.push(ii(rem.first, cur_time+t));
					left.pop();
				}
			}
			//loaded, make the round 
			cur_time += t;
			cur_pos = 1-cur_pos; 
		}

		while(!right.empty()){
			ii rem = right.top();
			int at = rem.second;
			if(cur_pos == 0){
				cur_pos += t;
				cur_pos = 1 - cur_pos;
			}
			
			if(at > cur_time){
				cur_time += (cur_time - at);
			}

			for(i=0; i<n && !right.empty(); i++){
				rem = right.top();
				if(rem.second <= cur_time){
					ans.push(ii(rem.first, cur_time+t));
					right.pop();
				}
			}
			cur_time+=t;
			cur_pos = 1 - cur_pos;
		}

		while(!ans.empty()){
			ii rem = ans.top();
			printf("%d\n", rem.second);
			ans.pop();
		}
		if(c)
			printf("\n");
	}
	return 0;
}

/*#include <cstdio>

const int NN = 10048;
char where[16];
int at[NN], cross[NN];
bool side[NN];

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a < b ? b : a; };

int main{
	int t; scanf("%d", &t);

	for(int m, n, z; t-- && scanf("%d %d %d", &n, &z, &m) == 3;){
		int left, right, time = 0;

		for(int i = 0; i < m; i++){
			scanf("%d %s", at[i], where);
			side[i] = (where[0] == 'l');
		}

		//count how many cars want to go to left, right
		for(left = 0; left < m && !side[left]; left++);
		for(right = 0; right < m && side[right]; right++);

		at[m] = 1<<30;

		while(left < m || right < m){
			time = max(time, min(at[left], at[right]));

			
		}

	}
}
/*#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct {
	int arr_time;
	string shore;

} c[10005];

int main(){
	int TC;
	scanf("%d", &TC);
	while(TC--){
		int n_cars,t_travel,m;
		scanf("%d %d %d", &n_cars, &t_travel, &m);
		int i;
		for(i=0; i<m; i++){
			cin>>c[i].arr_time >> shore;
		}
		int cur_time = 0;
		int cur_shore = 0;
		for(i=0; i<m; i++){


		}
	}
}*/