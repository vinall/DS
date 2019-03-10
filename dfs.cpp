#include <iostream>
#include <unordered_map>
#include <list>

struct graph {
    public:
        graph()  { std::cout << "creating graph\n";}
        ~graph() { std::cout << "deleting graph\n";}
        void add_edge(int w,int v) {
            g[w].push_back(v);
        }
        void dfs(int root) {
            std::cout << root << "->\t";
            auto l = g[root];
            std::unordered_map<int,bool> visited;
            visited[2] = true;
            for(const auto &v:l) {
                if(!visited[v])
                    dfsutil(v,visited);
            }
        }
        void dfsutil(int node,std::unordered_map<int,bool> &visited) {
            std::cout << node << "->\t";
            visited[node]= true;
            const auto &l = g[node];
            for(const auto &n : l) {
                if(!visited[n])
                    dfsutil(n,visited);
            }
        }
    private :
        std::unordered_map<int,std::list<int>> g;       
};

int
main() {
    graph mygraph;
    mygraph.add_edge(2,0);
    mygraph.add_edge(0,2);
    mygraph.add_edge(0,1);
    mygraph.add_edge(1,2);
    mygraph.add_edge(2,3);
    mygraph.add_edge(3,3);
    mygraph.dfs(2);
    return 0;
}
