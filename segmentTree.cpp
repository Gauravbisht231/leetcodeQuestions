#include<bits/stdc++.h>
using namespace std;

class SegmentTree
{
public:
    vector<int> segTree;
    int n;

    SegmentTree(int n) {
        segTree.resize(2 * n);
    }

    int buildSegTree(int node, int l, int r, vector<int> &arr) {
        if (l == r) {
            segTree[node] = arr[r]; // or arr[r]
            return segTree[node];
        }
        int mid = (l + r) / 2;
        buildSegTree(2 * node + 1, l, mid, arr); // for sum from l to mid
         buildSegTree(2 * node + 2, mid+1, r, arr); // for sum from l to r    
        // based on the problem, you can change the operation
        return segTree[node] =  segTree[(node*2)+1] + segTree[(node*2)+2];
    }
};
int main(){
    
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    SegmentTree *tree = new SegmentTree(arr.size());
    tree->buildSegTree(0, 0, arr.size() - 1, arr);
    cout << "Segment Tree: ";
    for (int i = 0; i < tree->segTree.size(); i++) {
        cout << tree->segTree[i] << " ";
    
}
}
