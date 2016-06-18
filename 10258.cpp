#include <algorithm>
#include <cstdio>
using namespace std;

const int NC = 100, NP = 10;
char line[1024];

struct player {

	int penalty[NP], solved[NP];

	int n, ps, submissions, tp;
	void clear(int num){
		n = num;
		ps = submissions = tp = 0;
		for(int i = 0; i < NP; i++)	solved[i] = penalty[i] = 0;
	}

	bool operator<(const player p) const{
		return ps > p.ps || (ps == p.ps && tp < p.tp) || (ps==p.ps && tp == p.tp && n < p.n);
	}
} p[100];

int main(){
	int player, problem, time;
	char verdict[16];
	int t;
	gets(line);
	sscanf(line, "%d", &t);
	gets(line);
	while(t--){
		for(int i=0; i < NC; i++)
			p[i].clear(i);

		while(gets(line) && line[0]){
			sscanf(line, "%d %d %d %s",&player, &problem, &time, verdict);
			--player; --problem;

			if(*verdict == 'C' && !p[player].solved[problem]){
				p[player].solved[problem] = 1;
				p[player].ps++;
				p[player].tp += time +p[player].penalty[problem];
			} else if(*verdict == 'I' && !p[player].solved[problem])
				p[player].penalty[problem] += 20;
			++p[player].submissions;
		}

		sort(p, p+NC);
		for(int i =0; i<NC; i++)
			if(p[i].submissions)
				printf("%d %d %d\n", p[i].n + 1, p[i].ps, p[i].tp);
		if(t) printf("\n");
	}
	return 0;
}
/*#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

typedef struct {
	int prob;
	int time_;
	char verdict;
	int penalty=0;
	bool accepted = false;

} submission;

typedef vector<submission> vs;

vector<vs> sb; //scoreboard;
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		sb.assign(101, vs());
		cin.ignore();
		int c, p, t;
		char l;
		char input[50];
		gets(input);

		if(strcmp(input, "") == 0 || feof(stdin)) break;
		sscanf(input, "%d %d %d %c", &c, &p, &t, &l )
		submission u;
		
		if(!sb[c].empty()){
			//team has submitted before
			bool has_submitted = false;
			for(int i =0; i< sb[c].size(); i++){
				if(sb[c][i].prob == c){
					has_submitted = true;
					if()
				}
			}
		}
	}
}*/