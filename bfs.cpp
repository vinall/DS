#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>


struct graph {
	public:
		void add_node(int root,int connected) {
			auto &l = graph[root];
			l.push_back(connected);
		}

		void bfs() {
			std::unordered_map<int,bool> visited;
			visited[2] = true;
			std::queue<int> q;
			q.push(2);
			while(q.empty() == false) {
				auto node = q.front();
				std::cout << node << "->\t";
				q.pop();
				std::list<int> l = graph[node];
				for(const auto &n :  l) {
					if(visited.find(n) == visited.end())
					{
						visited[n] = true;
						q.push(n);
					}
				}
			}
			std::cout << std::endl;
		}

	private:
		std::unordered_map<int,std::list<int>> graph;
};


int
main() {
	graph g;
	g.add_node(2,0);
	g.add_node(2,3);
	g.add_node(0,2);
	g.add_node(0,1);
	g.add_node(1,2);
	g.add_node(3,3);
	g.bfs();
	return 0;
}
