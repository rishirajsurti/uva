#include <cstdio>
#include <vector>

#include <algorithm>
using namespace std;

float powf(float p, int n){
	float ans=1.0;
	int i;
	for(i=0; i<n; i++){
		ans = ans * p * 1.00000;
	}
	return (n > 0 ? ans : 0.0);
}

int to_binary_int(int n){
	vector<int> a;
	while(n!=0){
		a.push_back( n%2 );
		n = n/2;
	}
	reverse(a.begin(),a.end());
	int b=0;
	for(int i =0; i<a.size(); i++)
		b = b*10 + a[i];
	return b;
}

int main(){
	int n;
	float p, ans;
	while(scanf("%d %f", &n, &p), n){
		int i,j;
		ans = 0.0;
		for(i=0; i<(1<<n); i++){
			//000 001 101... for each permutation
			
			int longest_streak = 0, prev=1, cur_streak=0;
			int wins = 0, loses = 0;
			for(j=0; j<n; j++){ // for each game
				//printf("i = %d j = %d\n", to_binary_int(i), to_binary_int(1<<j));
				if(i & (1<<j)){
					wins++;
					if(prev == 1) cur_streak++;
					else{
						prev = 1; cur_streak++;
					}
					if(cur_streak > longest_streak)
						longest_streak = cur_streak;

				}else{
					loses++;
					prev = 0;
					cur_streak = 0;
				}
			}

			float game_prob, win_prob, los_prob;
			win_prob = powf(p, wins);
			los_prob = powf(1-p, loses);
			if(win_prob == 0)
				game_prob = los_prob;
			else if(los_prob == 0)
				game_prob = win_prob;
			else
				game_prob = win_prob*los_prob*1.00;
			ans += (float)(game_prob * longest_streak * 1.00);
	/*		printf("wins %d loses %d\n", wins, loses);
			printf("%f %d %f\n", game_prob, longest_streak, ans);*/	
		}
		printf("%.6f\n", ans);
	}
}	