#include <sstream>
#include <string>
#include <cstdio>
#include <iostream>
#include <map>
#include <cstring>
using namespace std;

int main(){
	map< long long, int> R;
	int i,j;
	int t, n, A[105];
	string s;
	long long f1 = 1, f2 = 2, f3;

	R[f1] = 0, R[f2] = 1;
	for(i=2; i <= 50; i++){
		f3 = f1+ f2;
		f1 = f2; f2 = f3;
		R[f3] = i;
	}

	cin>>t;
	while(t--){
		cin>>n;
		for(i=0; i<n; i++)
			cin>>A[i];
		cin.ignore(100, '\n');
		getline(cin, s);
		char buf[105];
		memset(buf, ' ', sizeof(buf));
		int len = s.length();
		for(i=0, j = 0; i < n; i++){
			while(j < len && (s[j] < 'A' || s[j] > 'Z')) j++;
			buf[R[A[i]]] = s[j];
			j++;
		}

		for(i=100; buf[i] == ' '; i--);
		buf[i+1] = '\0';
		for(i=0; buf[i]; i++)
			printf("%c", buf[i]);
		printf("\n");
	}
}

/*#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[10000];
map<int, int> R;
void getfibo(){
	R[1] = 1;
	R[2] = 2;

	int i;
//	a[0] = 1; a[1] = 2;
	for(i=3; i < 10000; i++){
		R[R[i-1]+R[i-2]] = i;
	}

}

int main(){
	int t; scanf("%d", &t);
	getfibo();
	while(t--){
		string line;
		int i,j,n; scanf("%d", &n);
		vector<int> pos;
		for(i=0; i<n; i++){
			scanf("%d", &j);
			pos.push_back(j);
			//pos.push_back(find(a, a+10000, j) - a);
		}

		getline(cin, line);
		string ans(2*l, 42), l; // 42 := *
		ans = line;
		for(i=0; i<line.size(); i++){
			if(line[i] - 'A' < 0 || line[i] - 'Z' > 0) continue;
			l+=line[i];
		}
		cout<<l<<endl;
		
		for(i=0; i<pos.size(); i++){
			//R[pos[i]] is the position of 			
			ans[R[pos[i]]] = l[i];
		}
		cout<<ans<<endl;
/*		for(i=0; i<line.size(); i++){
			if(line[i] - 'A' < 0 || line[i] - 'Z' > 0) continue;
			ans[pos[i]] = line[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}*/