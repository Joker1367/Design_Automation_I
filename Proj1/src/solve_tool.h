#ifndef _SOLVE_TOOL_H
#define _SOLVE_TOOL_H

#include <vector>
#include <fstream>
#include <climits>
#include <utility>

#define PIV pair<int, vector<int> >

using namespace std;

class SolveTool {
    public:
                            	SolveTool(vector< vector<int> >, int);
        int                 	DynamicProgramming();
		void					printPath(ofstream&);
    private:
        int                 	DPSolver(int, int, vector< vector<PIV> >&);
        int                 	size;
		vector<int>      		path;
        vector< vector<int> > 	graph;
};

#endif
