//LOLOLOL THIS PROBLEM!!

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

typedef vector<int> vi;

int main(){
	int b,s, j = 1;
	while(scanf("%d %d", &b, &s), (s||b)){
		
		vi ab(b,0);
		vi as(s,0);
		for(int i = 0; i < b; i++)
			scanf("%d", &ab[i]);
		for(int i = 0; i < s; i++)
			scanf("%d", &as[i]);

		sort(ab.begin(), ab.end()); //can use rbegin(), rend()
		sort(as.begin(), as.end());

		if(as.size() == ab.size())
			printf("Case %d: 0\n",j++ );
		else if(as.size() > ab.size()){
			printf("Case %d: 0\n",j++ );
		}
		else
			printf("Case %d: %lu %d\n",j++, ab.size()-as.size(), ab[0] );
	}
	return 0;
}

/*#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

typedef vector<int> vi;

int main(){
	int b,s, j = 1;
	while(scanf("%d %d", &b, &s), (s||b)){
		
		vi ab(b,0);
		vi as(s,0);
		for(int i = 0; i < b; i++)
			scanf("%d", &ab[i]);
		for(int i = 0; i < s; i++)
			scanf("%d", &as[i]);

		sort(ab.begin(), ab.end()); //can use rbegin(), rend()
		sort(as.begin(), as.end());

		reverse(ab.begin(), ab.end());
		reverse(as.begin(), as.end());

		int mb[b], ms[s]; //married to ?

		int min_diff=1000000, diff;
		int b_id = 0;
		while(!as.empty() || !ab.empty()){
			int curr_age = ab[0], matched_id; //take first boy
			for(int i = 0; i < s; i++){ 	//search all of spinsters
				diff = abs(curr_age-as[i]);
				if(diff < min_diff){
					min_diff = diff;
					matched_id = i;
				}}
			mb[b_id] = matched_id;
			ms[matched_id] = b_id; 
			b_id++;
			ab.erase(ab.begin());
			as.erase(lower_bound(as.begin(), as.end(),as[matched_id]));
		}

		if(as.empty() && ab.empty())
			printf("Case %d: 0\n",j++ );
		else if(as.empty())
			printf("Case %d: %u %d\n",j++, ab.size(), ab[ab.size()-1] );
		else printf("Case %d: %u %d\n",j++, as.size(), as[as.size()-1] );

	}
	return 0;
}*/