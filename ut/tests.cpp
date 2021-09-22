#include <vector>

#include <complex/complex.hpp>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <polynomial/polynomial.hpp>

using namespace setm;

// Type alias.
using CP = Polynomial<Complex>;

TEST(PolyComplexTests, Equality) {
    const CP a{ Complex(3) };
    const CP b = a;

    EXPECT_EQ(a, b);
    EXPECT_EQ(b, Complex(3));
    EXPECT_EQ(b, 3.0);
    EXPECT_EQ(a + 1.0, 1.0 + b);
    EXPECT_EQ(CP(Complex(1.0)) + 0.9, CP(Complex(1.9)));
    EXPECT_NE(CP(Complex(1.0, 2.0)), CP(Complex(1.0, 2.0001)));

    const std::vector<Complex> complexVector{ Complex(1, 1), Complex(2, 2), Complex(3, 3) };
    const CP c{ complexVector.cbegin(), complexVector.cend() };
    EXPECT_THAT(complexVector, ::testing::ElementsAreArray(c.cbegin(), c.cend()));
}

TEST(PolyComplexTests, Addition) {
    const CP a{ Complex(-1.01, 15.8) };
    const CP b{ Complex(1.01, -15.8) };

    EXPECT_EQ(a + b, CP());
    EXPECT_EQ(1.01 + a, CP(Complex(0.0, 15.8)));
    EXPECT_EQ(b + Complex(1.99, 5.8), CP(Complex(3, -10)));
}

TEST(PolyComplexTests, Substraction) {
    const CP a{ Complex(2.0, 5.0) };
    const CP b{ Complex(1.0, -2.0) };

    EXPECT_EQ(a - b, CP(Complex(1.0, 7.0)));
    EXPECT_EQ(a - Complex(3, 2), CP(Complex(-1, 3)));
    EXPECT_EQ(CP(Complex(1, 1) - Complex(1, 1)), Complex());
}

TEST(PolyComplexTests, Multiplication) {
    const CP a{ Complex(5.5, 10.2), Complex(1.0, 2.0) };
    const CP b{ Complex(2.0), Complex(2.0, 1.0) };
    const CP abMultiplication{ Complex(11.0, 20.4), Complex(2.8, 29.9), Complex(0, 5) };

    EXPECT_EQ(a * b, abMultiplication);
    EXPECT_EQ(3.0 * b, CP(Complex(6.0), Complex(6.0, 3.0)));
    EXPECT_EQ(b * Complex(1.0, 1.0), CP(Complex(2.0, 2.0), Complex(1.0, 3.0)));
}

TEST(PolyComplexTests, Division) {
    const CP a{ Complex(1.0), Complex(5.0) };
    const CP b{ Complex(2.0), Complex(10.0) };
    EXPECT_EQ(a / b, 0.5);
    EXPECT_EQ(b / a, Complex(2.0));
    EXPECT_EQ(2.0 / a, -0.2);
    EXPECT_EQ(CP(Complex(1.0, 2.0)) / CP(Complex(1.0, 2.0)), 1.0);
}

TEST(PolyComplexTests, Subscription) {
}

TEST(PolyComplexTests, Unary) {
}
