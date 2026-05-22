#include <gtest/gtest.h>
#include "calculator.h"

TEST(CalculatorTest, BasicOperations) {
    Calculator calc;
    EXPECT_DOUBLE_EQ(calc.calculate("2 + 3"), 5);
    EXPECT_DOUBLE_EQ(calc.calculate("10 - 4"), 6);
    EXPECT_DOUBLE_EQ(calc.calculate("3 * 7"), 21);
    EXPECT_DOUBLE_EQ(calc.calculate("15 / 3"), 5);
}

TEST(CalculatorTest, ComplexExpressions) {
    Calculator calc;
    EXPECT_DOUBLE_EQ(calc.calculate("2 + 3 * 4"), 14);
    EXPECT_DOUBLE_EQ(calc.calculate("(2 + 3) * 4"), 20);
    EXPECT_DOUBLE_EQ(calc.calculate("2 * 3 + 4 * 5"), 26);
}

TEST(CalculatorTest, Parentheses) {
    Calculator calc;
    EXPECT_DOUBLE_EQ(calc.calculate("((2 + 3) * 4)"), 20);
    EXPECT_DOUBLE_EQ(calc.calculate("2 * (3 + 4)"), 14);
}

TEST(CalculatorTest, NegativeNumbers) {
    Calculator calc;
    EXPECT_DOUBLE_EQ(calc.calculate("-5 + 3"), -2);
    EXPECT_DOUBLE_EQ(calc.calculate("2 * -3"), -6);
    EXPECT_DOUBLE_EQ(calc.calculate("-(-5)"), 5);
}

TEST(CalculatorTest, Exponentiation) {
    Calculator calc;
    EXPECT_DOUBLE_EQ(calc.calculate("2 ^ 3"), 8);
    EXPECT_DOUBLE_EQ(calc.calculate("4 ^ 0.5"), 2);
    EXPECT_DOUBLE_EQ(calc.calculate("2 ^ (1 + 2)"), 8);
}

TEST(CalculatorTest, DivisionByZero) {
    Calculator calc;
    ASSERT_THROW(calc.calculate("5 / 0"), std::runtime_error);
}

TEST(CalculatorTest, InvalidInput) {
    Calculator calc;
    ASSERT_THROW(calc.calculate("2 ++ 3"), std::runtime_error);
    ASSERT_THROW(calc.calculate("2 + "), std::runtime_error);
    ASSERT_THROW(calc.calculate("(2 + 3"), std::runtime_error);
    ASSERT_THROW(calc.calculate("abc"), std::runtime_error);
}

TEST(CalculatorTest, DecimalNumbers) {
    Calculator calc;
    EXPECT_DOUBLE_EQ(calc.calculate("3.14 + 0.86"), 4.0);
    EXPECT_DOUBLE_EQ(calc.calculate("10 / 2.5"), 4.0);
    EXPECT_DOUBLE_EQ(calc.calculate("0.5 * 0.4"), 0.2);
}

TEST(CalculatorTest, MixedOperations) {
    Calculator calc;
    EXPECT_DOUBLE_EQ(calc.calculate("2 + 3 * (4 - 1) ^ 2"), 29);
    EXPECT_DOUBLE_EQ(calc.calculate("-2 * (3 + 1) / 2"), -4);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
