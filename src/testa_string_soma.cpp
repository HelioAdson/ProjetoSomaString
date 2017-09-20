#include <gtest/gtest.h>
#include "string_soma.hpp"

TEST(soma_string, Valido) {
    EXPECT_EQ(3, soma_string("1,2\n"));
}

TEST(soma_string, Invalido) {
  EXPECT_EQ(-1, soma_string("1,2"));
}

TEST(soma_string, ComDelimitador) {
  EXPECT_EQ(3, soma_string("//[%]\n1%2\n"));
}

int main(int argc, char **argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}