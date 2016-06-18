#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

typedef vector<int> vi;

//convert every character to an equivalent index;
// A=65, 'a' = 97;

int to_idx(char c){
	if(c > 'a')
		return (c+26-'a');

	return (c-'A');
}

struct compare{
	inline bool operator()(const int left, const int right) const{
		return (left <= right);
	};
};


/*
INPUT: a a b b c
pos: 
	...
	26: 0 1
	27: 2 3
	28: 4

QUERY: a b c

*/
int main(){
	
	vi pos[52];

	string input;
	cin>>input;
	
	int i;
	for(i = 0; i < input.size(); i++){
		pos[to_idx(input[i])].push_back(i);
	}

	int Q;
	scanf("%d", &Q);
	
	compare c;
	
	while(Q--){
	string SS; cin>>SS;
	bool matches = true;
	int first = 0, last = -1;
	int cur_pos = 0;

	for(i = 0; i < SS.size(); i++){
		int idx = to_idx(SS[i]);
		vi::iterator it = lower_bound(pos[idx].begin(),
									  pos[idx].end(),
									  last,  c);
		//last = -1
		// pos[idx] elements greater that 0
		//returns first position
		if(it == pos[idx].end()){
			matches = false;
			break;
		}else{
			last = *it;
			if( i == 0)
				first = last;
			}
		}
	if(matches)
		printf("Matched %d %d\n", first, last);
	else
		printf("Not matched\n");
	}
	return 0;
}

/*#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <string>
using namespace std;

int arr[1000005];
int qrr[105];

int main(){
	int n,i;
	
	string input;
	cin>>input;
	
	for(i=0; i<input.size(); i++)
		arr[i] = (int)input[i];
	
	scanf("%d", &n);
	while(n--){
		string q;
		cin>>q;

		for(i=0; i<q.size(); i++)
			qrr[i] = (int)q[i];

		int start=-1,end=-1;
		bool matched = true;
		int prev=0;

		for(i = 0; i < q.size(); i++){
			int pos = lower_bound(arr, arr+input.size(), &qrr[i]);
			if(pos - arr == input.size()){
				// not found
				matched = false;
				break;
			}
			else{
				*pos = -1;
				if(start == -1)
					start = pos-arr;

				end = pos-arr;
			}
		}
		if(matched)
			printf("Matched %d %d\n", start, end);
		else
			printf("Not matched\n");

	}
	return 0;
}
*/