#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "User.h"

using namespace std;
using ::testing::_;

TEST(User, is_repeated){
    bool bl = AddUser("salam");
    EXPECT_EQ(bl, 1);
    bl = AddUser("salam");
    EXPECT_EQ(bl, 0);
}
TEST(User, parser_works){
    auto ret = parser("salam,aleik");
    EXPECT_EQ(ret.first ,"salam");
    EXPECT_EQ(ret.second , "aleik");
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
