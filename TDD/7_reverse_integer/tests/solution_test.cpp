#include <gtest/gtest.h>
#include "../solution.h"

TEST(reverse_test, one_digit){
  Solution solution;
  EXPECT_EQ(solution.reverse(2), 2);
}

TEST(reverse_test, number){
  Solution solution;
  EXPECT_EQ(solution.reverse(123), 321);
}

TEST(reverse_test, negative_number){
  Solution solution;
  EXPECT_EQ(solution.reverse(-123), -321);
}

TEST(reverse_test, with_zero){
  Solution solution;
  EXPECT_EQ(solution.reverse(120), 21);
}

TEST(reverse_test, out_of_range_signed){
  Solution solution;
  EXPECT_EQ(solution.reverse(2147483643), 0);
}

TEST(reverse_test, out_of_range_signed_2){
  Solution solution;
  EXPECT_EQ(solution.reverse(1534236469), 0);
}