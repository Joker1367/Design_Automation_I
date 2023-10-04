#include <iostream>
#include <fstream>
#include <string>
#include <climits>
#include "solve_tool.h"

using namespace std;

int main(int argc, char* argv[]) {

    int size = 0;
    vector< vector<int> > graph(21, vector<int>(21, 100000));

    char buffer[200];
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);

    string edge_id;
    int weight, v1, v2;
    char c;
    while(fin >> edge_id) {
        fin >> weight;
        fin >> c >> v1;
        fin >> c >> v2;
        graph[v1][v2] = graph[v2][v1] = weight;
        size = max(size, max(v1, v2));
    }

    SolveTool TSPSolver(graph, size);
    fout << "******* DynamicProgramming Method *******" << endl;
    fout << "Minimum distance = " << TSPSolver.DynamicProgramming() << endl;
	TSPSolver.printPath(fout);

    fin.close();
    fout.close();
    return 0;
}
