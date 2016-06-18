#include <bits/stdc++.h>
using namespace std;

static const int V = 100;

struct Elevator{
	int id;
	int from;
	int to;
	int cost;
	bool operator > (const Elevator &e) const{
		return this->cost > e.cost;
	}
};

int main(){
	int n,k;
	while(cin>>n>>k){
		vector< vector<Elevator> > elevators(V);
		vector<int> time(n+1);

		
		for(int id = 1; id <= n; id++)
			cin>>time[id];

		cin.ignore();
		for(int id = 1; id <= n; id++0){
			// for each elevator
			string s;
			vector<int> floors;
			int floor;
			getline(cin, s);
			stringstream ss(s);
			// on what all floors does it stop;
			while(ss >> floor)
				floors.push_back(floor);

			for(size_t j = 0; j < floors.size(); j++){
				for(size_t k = j+1; k < floors.size(); k++){
			// for that particular elevator
			// calculate min time to travel between two floors		
					Elevator e;
					e.id = id;
					e.cost = 0;

					e.from = floors[j];
					e.to = floors[k];
					elevators[floors[j]].push_back(e);

					e.from = floors[k];
					e.to = floors[j];
					elevators[floors[k]].push_back(e);
			//for that floor store that this elevator can go to next floor
			//hence when we are at jth floor we have choice to make from 'elevators'

				}
			}
		}	
		priority_queue<Elevator, vector<Elevator>, greater<Elevator> > pq;
		vector<int> shortest(V, -1);
		vector<int> id(V, -1);
		
		Elevator e;
		e.from = 0;
		e.to = 0;
		e.cost = 0;
		shortest[0] = 0;
		pq.push(e);
		while(!pq.empty()){
			Elevator u = pq.top(); pq.pop();
			// lazy deletion

			if(shortest[u.to] != u.cost)
				continue;
			//expand the floor

			for(size_t i = 0; i < elevators[u.to].size(); i++){

				Elevator v = elevators[u.to][i];
				int alt = shortest[v.from] + abs(v.to - v.from)*time[v.id];
				
			}
		}
	}

}