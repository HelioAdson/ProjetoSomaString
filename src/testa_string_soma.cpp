#include <gtest/gtest.h>
#include "string_soma.hpp"

TEST(soma_string, Valido) {
    EXPECT_EQ(3, soma_string("1,2\n"));
    EXPECT_EQ(6, soma_string("3,2,1\n"));
    EXPECT_EQ(3, soma_string("1,\n2\n"));
    EXPECT_EQ(5, soma_string("1\n\n\n,4\n"));
    EXPECT_EQ(4, soma_string("1\n\n\n,\n\n\n3\n"));
    EXPECT_EQ(10, soma_string("1,2,3\n,4\n"));  
}

TEST(soma_string, Invalido) {
  EXPECT_EQ(-1, soma_string("1,2"));
  EXPECT_EQ(-1, soma_string(",2\n"));
  EXPECT_EQ(-1, soma_string("1,,2\n"));
  EXPECT_EQ(-1, soma_string(",\n"));
  EXPECT_EQ(-1, soma_string("1;2\n"));
  EXPECT_EQ(-1, soma_string("1,2"));
  EXPECT_EQ(-1, soma_string("1,2 \n"));
  EXPECT_EQ(-1, soma_string("1,2,3,4\n"));
}

TEST(soma_string, ComDelimitadorValido) {
  EXPECT_EQ(5, soma_string("//[;]\n2;3\n"));
  EXPECT_EQ(9, soma_string("//[***]\n2***3***4\n"));
}

TEST(soma_string, ComDelimitadorInvalido) {
  EXPECT_EQ(-1, soma_string("//[***]2***3***4\n"));
}

int main(int argc, char **argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}