#include <bits/stdc++.h>
#include "Segtree.cpp"
using namespace std;



int main()
{

    cout << "staring main" << endl;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    SegmentTree *tree = new SegmentTree(arr.size());
    tree->buildSegTree(0, 0, arr.size() - 1, arr);
    cout << "Segment Tree: ";
    tree->printTree();
    // queries on ranges
    vector<pair<int, int>> queries;
    queries.push_back({0, 10});
    queries.push_back({1, 5});
    queries.push_back({5, 8});
    queries.push_back({3, 9});

    for (auto it : queries)
    {
        auto startInd = it.first;
        auto endInd = it.second;
        cout << endl;
        cout << "start: " << startInd << "end: " << endInd << endl;
        cout << "range sum is : " << tree->getRangeSum(0, 0, arr.size() - 1, startInd, endInd) << endl;
    }
    // point update an index in the nums array
    cout << "changing index of 0, with value 2 " << endl;
    tree->update(0, 0, arr.size() - 1, 0, 2);
    tree->printTree();

    /*update range in the nums arrray: for this appraoch (without lazy propagation) the TC: O(q*m*logn)
 where q is the number of queries , m is the number of elements per query, and n is the total number of elements in the nums array */
    
//  vector<vector<int>> updateRanges = {
//         {0, 9, 1}, 
//         {1, 3, 4}, 
//         {2, 5, 6}  
//     };

//     for (auto it : updateRanges)
//     {
//         auto fromInd = it[0];
//         auto toInd = it[1];
//         auto val = it[2];
//         for (int i = fromInd; i <= toInd; i++)
//         {
//             tree->update(0, 0, arr.size() - 1, i, val);
//         }
//         cout << "After updating index from " << fromInd << " to " << toInd << " with value " << val << endl;
//         tree->printTree();
//     }

        tree->lazyUpdate(0, 0, arr.size() - 1, 0, 9, 1);
        tree->printTree();
    return 0;

}
