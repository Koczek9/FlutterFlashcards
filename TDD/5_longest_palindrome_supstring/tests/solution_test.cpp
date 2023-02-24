#include <gtest/gtest.h>
#include "../solution.h"

TEST(checkIfPalindromeTest, only_two_letters){
  Solution solution;
  EXPECT_EQ(solution.checkIfPalindrome("aa"), true);
}

TEST(checkIfPalindromeTest, is_palindrome){
  Solution solution;
  EXPECT_EQ(solution.checkIfPalindrome("ooloo"), true);
}

TEST(checkIfPalindromeTest, is_not_palindrome){
  Solution solution;
  EXPECT_EQ(solution.checkIfPalindrome("ooloow"), false);
}

TEST(longestPalindromeTest, only_one_letter){
  Solution solution;
  EXPECT_EQ(solution.longestPalindrome("a"), "a");
}

TEST(longestPalindromeTest, only_two_letters){
  Solution solution;
  EXPECT_EQ(solution.longestPalindrome("aa"), "aa");
}

TEST(longestPalindromeTest, simplest_test){
  Solution solution;
  string result = solution.longestPalindrome("babad");
  EXPECT_TRUE(result == "bab" || result == "aba");
}

TEST(longestPalindromeTest, two_letters){
  Solution solution;
  EXPECT_EQ(solution.longestPalindrome("cbbd"), "bb");
}

TEST(longestPalindromeTest, repeted_characters){
  Solution solution;
  EXPECT_EQ(solution.longestPalindrome("soooses"), "sooos");
}

TEST(longestPalindromeTest, all_different_characters){
  Solution solution;
  string result = solution.longestPalindrome("abc");
  EXPECT_TRUE(result == "a" || result == "b" || result == "c");
}