#include <cstdio>
#include <map>
using namespace std;

map< int, int > m;
int fw[100][100][3];
int deg[100], n[100];
bool v[100];

int make_call(int time, int target){

	int ret = n[target];
	for(int i=0; i < deg[target]; i++){
		if(time >= fw[target][i][0] && time <=fw[target][i][1]){
			if(m.find(fw[target][i][2]) == m.end())	return fw[target][i][2];
			else{
				if(v[fw[target][i][2]])	return 9999;
				ret = make_call(time, m[fw[target][i][2]]);
			}
		}
	}
	return ret;
}
int main(){
	int a , dur, i, nums, src, t, tgt, time;
	printf("CALL FORWARDING OUTPUT\n");
	scanf("%d",&t);

	for(int s = 1; s <= t; s++){

		for( i = 0; i < 100; i++)	deg[i] = 0;
		nums=0;
		m.clear();
		printf("SYSTEM %d\n", s);

		while(scanf("%4d",&src) && src){
			scanf("%d %d %d", &time, &dur, &tgt);

			if(m.find(src) == m.end())
				m[src] = nums, n[nums++] = src;
			
			a = m[src];
			fw[a][deg[a]][0] = time;
			fw[a][deg[a]][1] = time+dur;
			fw[a][deg[a]][2] = tgt;
			deg[a]++;

		}

		//0 [1111- 0- source - dur - tgt] [ 1111 - 1 - s - d - tgt] [..] 
		//1	[2222...]
		//map[2222] = 1; map[1111] = 0;
		//deg[0] = 2;
		//deg[1] = 1; //how many occurences; 

		while(scanf("%d", &time) && time != 9000){
			scanf("%d", &tgt);

			if(m.find(tgt) == m.end()){ //tgt is not on leave
				printf("AT %04d CALL TO %04d RINGS TO %04d\n", time, tgt, tgt );
				continue;
			}

			for(i=0; i<nums; i++)	v[i]= 0;
			int dest = make_call(time, m[tgt]);
			printf("AT %04d CALL TO %04d RINGS TO %04d\n", time, tgt, dest );
		}
	}
	printf("END OF OUTPUT\n");
	return 0;

}

/*
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
int N,k,t,ext, forwarded_to;
vector<vi> db;
vector<bool> checked;

bool call_forward(int extn, int ct){ //extension, call time


	//if extension available at that time, no need of forward
	int i,j;
	for(i =0; i<db.size(); i++){
		if(db[i][0] == extn && (ct >= db[i][1] && ct <= (db[i][1]+db[i][2]))){
			
			if(!checked[i]){
				checked[i]= true;
				call_forward(db[i][3], ct);	
			}
			else
				return false;
		}
	
	}
	forwarded_to = extn;
	return true;
}

int main(){
	int temp;
	scanf("%d", &N);
	printf("CALL FORWARDING OUTPUT\n");
	for(temp = 1; temp<=N; temp++){
		printf("SYSTEM %d\n", temp);		
		
		db.clear();
		checked.clear();

		while(scanf("%d",&k),k){
			vi record(4,0);
			record[0] = k;
			scanf("%d %d %d", &record[1], &record[2], &record[3]);			
			db.push_back(record);			
			checked.push_back(false);
		}

		scanf("%d", &t);
		while(t != 9000){
			scanf("%d",&ext);
			if(call_forward(ext, t))
				printf("AT %4d CALL TO %4d RINGS %4d\n",t, ext, forwarded_to );
			else
				printf("AT %4d CALL TO %4d RINGS 9999\n",t, ext);

			scanf("%d",&t);
		}
		printf("END OF OUTPUT\n");
	}
	return 0;
}*/