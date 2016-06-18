#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <numeric>
#include <string>
using namespace std;


int tape_length, n_tracks;
string line;

vector<int> a;

int main(){

	while(getline(cin, line)){
		std::istringstream is(line);
		a.assign(istream_iterator<int>(is), istream_iterator<int>());
		
		tape_length = a[0];
		a.erase(a.begin());
		n_tracks = a[0];	a.erase(a.begin());
		
		int c,k, max_n = 0, max_sum=0;
		
		for(c = 0; c < (1<<n_tracks); c++){
			int sum=0;
			for(k=0; k < n_tracks; k++){
				if(c & (1<<k))
					sum += a[k];
			}
			if( sum <= tape_length && sum>max_sum){
				max_sum = sum;
				max_n = c;
			}
		}

		for(k=0; k<n_tracks; k++){
			if(max_n & (1<<k))
				printf("%d ",a[k] );
		}
		printf("sum:%d\n",max_sum );
		
	}
	return 0;
}