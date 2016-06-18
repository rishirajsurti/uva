#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

typedef struct{
	string maker;
	int l,h;
} record;

typedef vector<record> vr;

int main(){
	
	int t,db,q,p;
	
	scanf("%d",&t);
	
	while(t--){
		vr cars;

		scanf("%d",&db);
		
		while(db--){
			record r;
			cin>>r.maker>>r.l>>r.h;
			//cin.ignore();
			cars.push_back(r);
			}

		scanf("%d",&q);
		while(q--){
			scanf("%d",&p);
			int found = -1;
			for(int i = 0; i < cars.size(); i++){
				if(p >= cars[i].l && p <= cars[i].h){
					if(found>-1){
						found = -1;
						break;
					}
					else
						found = i;
				}
				}
			if(found > -1)
				cout<<cars[found].maker<<endl;
			else
				printf("UNDETERMINED\n");
			}
		if(t)
			printf("\n");
	}
}
