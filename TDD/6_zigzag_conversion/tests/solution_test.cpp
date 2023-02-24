#include <gtest/gtest.h>
#include "../solution.h"

TEST(convert_test, tree_rows){
  Solution solution;
  EXPECT_EQ(solution.convert("PAYPALISHIRING", 3), "PAHNAPLSIIGYIR");
}

TEST(convert_test, four_rows){
  Solution solution;
  EXPECT_EQ(solution.convert("PAYPALISHIRING", 4), "PINALSIGYAHRPI");
}

TEST(convert_test, one_character){
  Solution solution;
  EXPECT_EQ(solution.convert("A", 1), "A");
}

TEST(convert_test, four_rows_numbers){
  Solution solution;
  EXPECT_EQ(solution.convert("0123456789", 4), "0615724839");
}