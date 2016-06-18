#include <iostream>
using namespace std;

void rotate(char** sq, int b){

	char **tmp;

	tmp = new char*[b];
	for(int i =0; i < b; i++)
		tmp[i] = new char[b];

	for(int i =0; i < b; i++)
		for(int j = 0; j < b; j++)
			tmp[i][j] = sq[i][j];

	/*
	00 01 02     20 10 00
	10 11 12	 21 11 01
	20 21 22     22 12 02
	i =1 j =2
	b = 3
	sq[1][3-1-2] = sq[1][0] = tmp[2][1]
		sq[0][0]		tmp[2][0]
		sq[0][1]		tmp[1][0]
		sq[0][2]		tmp[0][0]
	*/

	for(int i = 0; i < b; i++)
		for(int j = b-1; j >= 0; j--)
			sq[i][b-1-j] = tmp[j][i];

	for(int i = 0; i < b; i++)
		delete[] tmp[i];
	delete[] tmp;

}

int count(char **big, int a, char** small, int b){
	int result = 0;

	for(int i = 0; i < a-b+1; i++){
		for(int j =0; j < a-b+1; j++){
			bool ok = true;
			for(int k =0; k < b; k++){
				for(int l = 0; l < b; l++){
					if(big[i+k][j+l] != small[k][l]){
						ok = false;
						k = b;
						break;
					}
				}
			}
			if(ok)
				result++;
		}
	}
	
	return result;
}

int main(){
	int a, b;
	char **big, **small;
	int result[4];

	while(cin>> a >> b){
		if(!a && !b)
			break;

		for(int i = 0; i < 4; i++)
			result[i] = 0;

		big = new char*[a];
		for(int i = 0; i < a; i++)
			big[i] = new char[a];

		small = new char*[b];
		for(int i =0; i < b; i++)
			small[i] = new char[b];

		for(int i =0; i < a; i++)
			for(int j = 0; j < a; j++)
				cin >> big[i][j];

		for(int i =0; i < b; i++)
			for(int j = 0; j < b; j++)
				cin >> small[i][j];	

		for(int i =0; i<4; i++){
			result[i] = count(big, a, small, b);
			rotate(small, b);
		}

		for(int i = 0; i < 4; i++){
			if(i > 0)
				cout<<" ";
			cout<<result[i];
		}
		cout<<endl;

		for(int i = 0; i < a; i++)
			delete[] big[i];
		delete[] big;

		for(int i =0; i < b; i++)
			delete[] small[i];
		delete[] small;

	}
	return 0;
}