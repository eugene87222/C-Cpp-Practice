/**
 * @ Author: Your name
 * @ Create Time: 2019-08-25 05:46:27
 * @ Modified by: Your name
 * @ Modified time: 2019-08-25 06:56:31
 * @ Description:
 */

#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <vector>

using namespace std;

class Binary_Search
{
public:
    Binary_Search() = default;
    ~Binary_Search() = default;
    int BinarySearch(int target, int aLeft, int aRight) const;
    void SetData(const vector<int> &aVec);
    void ResetData();
    void PrintVec();

private:
    vector<int> iVec;
};

#endif