#include <gtest/gtest.h>
#include "../solution.h"

TEST(SolutionTests, simplest_test) {
  Solution solution;
  EXPECT_EQ(solution.lengthOfLongestSubstring("abcde"), 5);
}

TEST(SolutionTests, standard_test) {
  Solution solution;
  EXPECT_EQ(solution.lengthOfLongestSubstring("abcabcbb"), 3);
}

TEST(SolutionTests, all_the_same) {
  Solution solution;
  EXPECT_EQ(solution.lengthOfLongestSubstring("bbbbb"), 1);
}

TEST(SolutionTests, with_some_same) {
  Solution solution;
  EXPECT_EQ(solution.lengthOfLongestSubstring("pwwkew"), 3);
}

TEST(SolutionTests, going_back) {
  Solution solution;
  EXPECT_EQ(solution.lengthOfLongestSubstring("abdcdefg"), 5);
}

TEST(SolutionTests, first_is_last) {
  Solution solution;
  EXPECT_EQ(solution.lengthOfLongestSubstring("aabaab!bb"), 3);
}
