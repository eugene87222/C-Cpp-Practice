#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

#include "Binary_Search.h"

using namespace std;

int Binary_Search::BinarySearch(int target, int aLeft, int aRight) const
{
    if (aLeft <= aRight)
    {
        int mid = (aLeft + aRight) / 2;
        if (target < iVec[mid])
            return BinarySearch(target, aLeft, mid - 1);
        if (target > iVec[mid])
            return BinarySearch(target, mid + 1, aRight);
        if (target == iVec[mid])
            return mid;
    }
    return -1;
}

void Binary_Search::SetData(const vector<int> &aVec)
{
    iVec = aVec;
}

void Binary_Search::ResetData()
{
    iVec.clear();
}

void Binary_Search::PrintVec()
{
    for (vector<int>::iterator it = iVec.begin(); it != iVec.end(); it++)
    {
        printf("%d ", *it);
    }
    printf("\n");
}