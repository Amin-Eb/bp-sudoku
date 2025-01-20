#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "Core.h"

using namespace std;
using ::testing::_;

TEST(Core_things, is_validation_works){
	Mat tmp;
	for(int i = 0; i < 9; i ++) tmp.table[0][i] = 0;
	bool check = valid(tmp);
	EXPECT_EQ(check, 0);
	int a[9][9] = {
	 {6, 3, 9, 5, 7, 4, 1, 8, 2}
	,{5, 4, 1, 8, 2, 9, 3, 7, 6}
	,{7, 8, 2, 6, 1, 3, 9, 5, 4}
	,{1, 9, 8, 4, 6, 7, 5, 2, 3}
	,{3, 6, 5, 9, 8, 2, 4, 1, 7}
	,{4, 2, 7, 1, 3, 5, 8, 6, 9}
	,{9, 5, 6, 7, 4, 8, 2, 3, 1}
	,{8, 1, 3, 2, 9, 6,	7, 4, 5}
	,{2, 7, 4, 3, 5, 1, 6, 9, 8}};
	for(int i = 0; i < 9; i ++)
		for(int j = 0; j < 9; j ++)
			tmp.table[i][j] = a[i][j];
	check = valid(tmp);
	EXPECT_EQ(check, 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
