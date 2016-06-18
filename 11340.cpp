#include <cstdio>
#include <string>
#include <iostream>
#include <map>
using namespace std;

map<int, int> pay;

int main(){
	int N;
	scanf("%d", &N);
	while(N--){
		pay.clear();
		int K;
		string input;
		scanf("%d\n", &K);
		int i,j,amt; char c;
		
		for(i=0; i<K; i++){
			cin>> c>> amt;
			pay[(int) c] = amt;
			//cout<<"input "<<input<<endl;

		}
		int M;
		scanf("%d\n",&M);
	    //cout<<"M: "<<M<<endl;
		unsigned long long payment =0;
		for(i=0; i<M; i++){
			getline(cin, input);
			//cout<<"input "<<input<<endl;
			for(j=0; j<input.size(); j++){
				if(pay.count((int)input[j]))
					payment += pay[input[j]];
			}
		}

		float pt = payment/100.0;
		printf("%.2lf$\n", payment / 100.0);
	}	
}