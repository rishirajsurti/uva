#include <bits/stdc++.h>
using namespace std;

int N, T = 0;
char inp[1500];
stack<char> empty;
vector<stack<char> > containers;

int add_to_stack(int i){
	for(int j = 0; j < containers.size(); j++){
		if(inp[i]<=containers[j].top()){
			containers[j].push(inp[i]);
			return 0;
		}
	}
	containers.push_back(empty);
	containers[containers.size()-1].push(inp[i]);
	return 1;
}

int main(){
	while(gets(inp), strcmp(inp,"end") != 0){
		T++;
		N = strlen(inp);
		containers.clear();
		int ans = 0;
		for(int i = 0; i < N; i++){
			ans += add_to_stack(i);
		}
		printf("Case %d: %d\n",T, ans );
	}
	return 0;
}

/*#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	int tc=1;
	while(getline(cin, s)){
		if(s=="end")
			break;
		int count[26]={0};
		int i;
		for(i=0; i<s.size(); i++)
			count[s[i]-'A']++;
		stack<int> st[26];
		int filled[26]={0};
		int curr_stack=0;
		for(i=0; i<s.size(); i++){
			if(!st[curr_stack].empty()){
				char lc = st[curr_stack].top(); //last char
				if(lc==s[i])
					st[curr_stack].push(s[i]);
				//if lower character and is filled
				else if(lc > s[i] && filled[lc]==count[lc]) 
					st[curr_stack].push(s[i]);
				//no need for new stack
				//else check if other stacks have space
				else{
					int j;
					for(j=curr_stack-1; j>=0; j--){
						char lc = st[j].top();
						if(lc==s[j])
							st[j].push(s[i]);
						//if lower character and is filled
						else if(lc > s[i] && filled[lc]==count[lc]) 
							st[curr_stack].push(s[i]);
					}
				}
			} else{

			}
		}
		printf("Case %d: %d\n", tc++, curr_stack+1);
	}	
}

/*#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	int caseNo=1;
	while(getline(cin, s)){
		if(s == "end") break;
		int a[26];
		int i;
		int count[26]={0};
		for(i=0 ;i<s.size(); i++) ++count[s[i]-'A'];
		vector<int> filled;
		int ans = 0;
		
		for(i=0; i<s.size(); i++){
			if(filled.empty()){
				
			}
		}

		map<char, int> m;
		int i;
		for(i=0 ;i<s.size(); i++) ++m[s[i]];
		map<char, int> count;
		int filled=1, ans =1;
		char prev=s[0];
		for(i=1; i<s.size(); i++){
			if(filled > 0){
				if(s[i]!=prev){
					filled--; 
					prev = s[i];
				}
			} else{
				if(prev != s[i]) ans++;
				++count[s[i]]; 
				if(count[s[i]] == m[s[i]]) filled++;
				
			}
		}
		printf("Case %d: %d\n",caseNo++, ans );
	}
	return 0;
}
*/