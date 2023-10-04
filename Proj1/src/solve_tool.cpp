#include "solve_tool.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <climits>
#include <utility>

//#define PIV pair< int, vector<int> >

using namespace std;

// Constructor
SolveTool::SolveTool(vector< vector<int> > G, int len) {
    size = len;
    graph.resize(len + 1, vector<int>(len + 1, INT_MAX));
    for(int i = 1; i <= len; i++) {
        for(int j = 1; j <= len; j++) {
            graph[i][j] = G[i][j];
        }
        graph[i][i] = 0;
    }
}

// Dynamic Programming method
int SolveTool::DynamicProgramming() {
    vector< vector<PIV> > cache(size + 1, vector<PIV>(1 << (size + 1)));

    int res = INT_MAX;
	int min_idx = -1;
    for(int i = 2; i <= size; i++) {
        if(graph[i][1] == INT_MAX) continue;
        int tmp = DPSolver(i, (1 << (size + 1)) - 1, cache) + graph[i][1];
		if(tmp < res) {
			res = tmp;
			min_idx = i;
		}
    }
	if(min_idx != -1) path = cache[min_idx][(1 << (size + 1)) - 1].second;
    return res;
}

int SolveTool::DPSolver(int last, int mask, vector< vector<PIV> >& cache) {
    if(mask == ((1 << last) | 3) && graph[1][last] != INT_MAX) {
		if(cache[last][mask].second.empty()) {
			cache[last][mask].first = graph[1][last];
			cache[last][mask].second.push_back(1);
			cache[last][mask].second.push_back(last);
		}
		return graph[1][last];
	}

    if(cache[last][mask].first > 0) return cache[last][mask].first;

    int curr = INT_MAX;
	int min_idx = 0;
    for(int i = 2; i <= size; i++) {
        if(graph[i][last] != INT_MAX && last != i && mask & (1 << i)) {
        	int tmp = DPSolver(i, mask ^ (1 << last), cache) + graph[i][last];
			if(tmp < curr) {
				curr = tmp;
				min_idx = i;
			}
        }
    }
	if(min_idx != -1) {
		cache[last][mask].second = cache[min_idx][mask ^ (1 << last)].second;
		cache[last][mask].second.push_back(last);
    	cache[last][mask].first = curr;
	}

    return cache[last][mask].first;
}

void SolveTool::printPath(ofstream& out) {
	out << "Path = ";
	for(int i = 0; i < path.size(); i++) {
		out <<  path[i] << " ";
	}
	out << 1 << endl;
}
