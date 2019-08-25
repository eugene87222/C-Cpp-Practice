#include <gtest/gtest.h>
#include <algorithm>
#include <vector>

#include "Binary_Search.h"

namespace
{
class BinarySearchTest : public testing::Test
{
public:
    BinarySearchTest()
    {
        iObj = Binary_Search();
    }
    ~BinarySearchTest() = default;
    void SetUp() override;
    void TearDown() override;

    Binary_Search iObj;
    int iLength;
};

void BinarySearchTest::SetUp()
{
    std::vector<int> vec = {12, 51, 36, 80, 22, 41, 68, 77, 52, 32};
    sort(vec.begin(), vec.end());
    iObj.SetData(vec);
    iLength = vec.size() - 1;
}

void BinarySearchTest::TearDown()
{
    iObj.ResetData();
}

TEST_F(BinarySearchTest, TEST_CASE_1)
{
    int target = 15;
    int pos = iObj.BinarySearch(target, 0, iLength);
    // iObj.PrintVec();
    // std::cout << iLength << std::endl;

    EXPECT_EQ(pos, -1);
}

TEST_F(BinarySearchTest, TEST_CASE_2)
{
    int target = 68;
    int pos = iObj.BinarySearch(target, 0, iLength);
    // iObj.PrintVec();
    // std::cout << iLength << std::endl;

    EXPECT_EQ(pos, 7);
}

TEST_F(BinarySearchTest, TEST_CASE_3)
{
    int target = 51;
    int pos = iObj.BinarySearch(target, 0, iLength);
    // iObj.PrintVec();
    // std::cout << iLength << std::endl;

    EXPECT_EQ(pos, 5);
}
} // namespace

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}