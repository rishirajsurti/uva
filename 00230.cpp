#include <bits/stdc++.h>
using namespace std;

struct book{
	string title, author;

	bool operator<(const book &other) const{
		if(author != other.author)
			return author < other.author;
		return title < other.title;
	}
};

int main(){
	string input;
	char t[85], a[85];
	vector<book> books;
	vector<book> returned;
	map<string, int> position;
	map<int, bool> taken;
	string title;

	while(getline(cin, input)){
		if(input == "END") break;

		sscanf(input.c_str(), "\"%[^\"]\" by %[^\n\r]", t, a);
		book tmp;
		tmp.author = string(a);
		tmp.title = string(t);
		books.push_back(tmp);
	}

	sort(books.begin(), books.end());
	for(int i = 0; i < books.size(); i++){
		position[books[i].title] = i;
		taken[i] = false;
	}

	while(getline(cin, input)){
		if(input == "END") break;

		if(input[0] == 'S'){
			sort(returned.begin(), returned.end());
			
			for(int i = 0; i < returned.size(); i++){
				int pos = position[returned[i].title];
				bool found = false;
				int after = pos-1;
				while(after >= 0){
					if(taken[after] == false){
						found = true;
						break;
					}
					after--;
				}
				if(found){
					cout<<"Put \"" <<books[pos].title << "\" after \""<<books[after].title<<"\""<<endl;		
				} else{
					cout<<"Put \"" <<books[pos].title<< "\" first"<<endl;
				}
				taken[pos] = false;	
			}
			cout<<"END" <<endl;
			returned.clear();

		} else if(input[0] == 'B'){
			sscanf(input.c_str(), "BORROW \"%[^\"]\"", t);
			title = string(t);
			int pos = position[title];
			taken[pos] = true;
		} else if(input[0] == 'R'){
			sscanf(input.c_str(), "RETURN \"%[^\"]\"", t);
			title = string(t);
			int pos = position[title];
			returned.push_back(books[pos]);
		}
	}
}
/*#include <bits/stdc++.h>
using namespace std;

int main(){
	string line;
	vector<string> lib;
	getline(cin, line);

	while(line != "END"){
		lib.push_back(line);
		getline(cin, line);
	}
	sort(lib.begin(), lib.end());
	vector<int> status(lib.size(), 1); //all books available;

	string what, book;
	cin>>what;
	while(what!="SHELVE"){
		cin>>book;
		int p = *lower_bound(lib.begin(), lib.end(), book);
		if(what == "BORROW")
			status[p] = 0;
		else if(what == "RETURN"){
			for(int i = p; i>=0; i--){
				if(status[i]==1) break;
			}
		} 
	}
}*/