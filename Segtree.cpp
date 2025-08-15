#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
public:
    vector<int> segTree;
    vector<int> lazy;
    int n;

    void printTree()
    {
        for (int i = 0; i < segTree.size(); i++)
        {
            cout << segTree[i] << " ";
        }
        cout << endl;
    }
    SegmentTree(int n)
    {
        segTree.resize(4 * n);
        lazy.resize(4 * n, 0);
    }

    void buildSegTree(int node, int l, int r, vector<int> &arr)
    {
        if (l == r)
        {
            segTree[node] = arr[l]; // or arr[r]
            return;
        }
        int mid = (l + r) / 2;
        buildSegTree(2 * node + 1, l, mid, arr);     // for sum from l to mid
        buildSegTree(2 * node + 2, mid + 1, r, arr); // for sum from l to r
        // based on the problem, you can change the operation
        segTree[node] = segTree[(node * 2) + 1] + segTree[(node * 2) + 2];
    }

    int getRangeSum(int i, int l, int r, int start, int end)
    {
        if (end < l or start > r)
        {
            return 0;
        }
        if (start <= l and end >= r)
            return segTree[i];
        return getRangeSum(2 * i + 1, l, (l + r) / 2, start, end) + getRangeSum(2 * i + 2, ((l + r) / 2) + 1, r, start, end);
    }

    void update(int i, int l, int r, int changeInd, int value)
    {
        if (l == r)
        {
            segTree[i] += value;
            return;
        }
        int mid = (l + r) / 2;
        if (changeInd <= mid)
        {
            update(2 * i + 1, l, mid, changeInd, value);
        }
        else
        {
            update(2 * i + 2, mid + 1, r, changeInd, value);
        }
        segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
        return;
    }

    void lazyUpdate(int i, int l, int r, int start, int end, int val){
        // update segTree from lazy first
            if(lazy[i]!=0){
                segTree[i] += (r-l+1)*lazy[i];
                if(l!=r){
                    lazy[2*i+1] += lazy[i];
                    lazy[2*i+2] += lazy[i];
                }
                lazy[i]=0;

            }
            // out of range case
            if(start>r or end<l) return;
            //fully in range case
            if(start<=l and end>=r){
                if(lazy[i] == 0){
                    segTree[i] += (r-l+1)*val;
                    if(l!=r){
                        lazy[2*i+1] += val;
                        lazy[2*i+2] += val;
                    }
                }
                return;
            }
            // overlapping case: propagate in both subtrees 
            int mid  = l +(r-l)/2;
            lazyUpdate(2*i+1, l , mid, start, end, val);
            lazyUpdate(2*i+2, mid+1, r, start, end, val);

            segTree[i]= segTree[2*i+1] + segTree[2*i+2];
            return;

    }
};