/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

/*
#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};
*/

typedef pair<UndirectedGraphNode *, UndirectedGraphNode *> PNN;

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (node == NULL)
            return NULL;

        map<int, PNN> lookup;
        queue<UndirectedGraphNode *> active;

        active.push(node);
        lookup[node->label] = make_pair(node,
                                        new UndirectedGraphNode(node->label));
        while (!active.empty()) {
            UndirectedGraphNode *current = active.front();
            active.pop();
            UndirectedGraphNode *clone = lookup[current->label].second;

            for (int i = 0; i < current->neighbors.size(); ++i) {
                if (lookup.find(current->neighbors[i]->label) == lookup.end()) {
                    active.push(current->neighbors[i]);
                    lookup[current->neighbors[i]->label] = make_pair(
                        current->neighbors[i],
                        new UndirectedGraphNode(current->neighbors[i]->label));
                }
                clone->neighbors.push_back(
                    lookup[current->neighbors[i]->label].second);
            }
        }

        return lookup[node->label].second;
    }
};
