//check graphs that exist hamilton path?
//using dynamic programming and bitmasking

#include<bits/stdc++.h>

using namespace std;

/*
2
5 5
1 2
1 3
2 4
2 5
3 5
7 13
1 3
1 5
1 7
2 4
2 5
2 6
3 4
3 5 
3 7
4 6
4 7
5 7
6 7

0
1
*/

/*
matrix n * 2^n
dp[j][i] = có đường từ i đến j

*/

int nbGraph;
int nbVertices,nbEdges;
const int MAX = 20;
vector<int> adj[MAX]; //adjacent

int path[MAX];
int pos;
bool mark[MAX]; //= true if vertix is inserted into current hamcycle

bool isSafe(int node, int pos){
    //cout << "check for node = " <<node << " " <<pos<<": "<<endl;
    for (int v : adj[path[pos-1]])
    {
        if (v == node){
            for (int i = 1; i < pos; i++)
                if (path[i] == node){
                    return false;
                }
            //cout << true <<endl;
            return true;
        }
    }
    return false;
}
void solution();

bool hamiltonianCycle(int pos){

    //if all vertices are included in Hamilton Cycle
    if (pos == nbVertices+1) {
        for (int v : adj[path[pos-1]])
            if (v == 1) {
                //solution();
                return true;
            }
        return false;
    }

    for (int n = 1; n <= nbVertices; n++){
        if (isSafe(n, pos)) //check if this vertex can be added to Hamilton cycle
        {
            path[pos] = n;
            //backtracking
//            if (pos == nbVertices) {
//            	solution();
//			}
            if (hamiltonianCycle(pos+1) == true)
                return true;
            path[pos] = -1;
        }
    }
    return false;
}

void solution(){
    cout << "Solution: ";
    for(int i = 1; i <= nbVertices; i++){
        cout << path[i] << " ";
    }
    cout << path[1] <<endl;
}

bool hamCycle() {
    memset(path, -1, nbVertices+1);

    path[1] = 1;

    if (hamiltonianCycle(2) == false) {
        return false;
    }
    return true;
}

void input(){
    freopen("data.txt", "r", stdin);
    cin >> nbGraph;
    for (int i = 0; i < nbGraph; i++){
        cin >> nbVertices >> nbEdges;

        for (int j = 0; j < nbEdges; j++){
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // for (int j = 1; j <= nbVertices; j++){
        //     for (int k = 0; k < adj[j].size(); k++){
        //         cout << adj[j][k] << " ";
        //     }
        //     cout <<endl;
        // }
        cout << hamCycle() <<endl;

        //end
        for (int j = 1; j <= nbVertices; j++){
            adj[j].clear();
        }
    }
}

int main(int argc, char const *argv[])
{
    input();
    return 0;
}
