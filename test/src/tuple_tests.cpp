#include <tuple.h>
#include "gtest/gtest.h"

using namespace std;

class TupleTest : public ::testing::Test {

protected:

  virtual void SetUp() {
  };

  virtual void TearDown() {
  };

  // virtual void verify(int index) {
  //   Fraction       f        = Fraction{numerators.at(index), denominators.at(index)};
  //   DivisionResult expected = DivisionResult{divisions.at(index), remainders.at(index)};
  //   DivisionResult result   = Division(f).divide();
  //   EXPECT_EQ(result.division, expected.division);
  //   EXPECT_EQ(result.remainder, expected.remainder);
  // }
};

TEST_F(TupleTest, tuple_is_point) {
  auto a = Tuple(4.3, -4.2, 3.1, 1.0);
  EXPECT_FLOAT_EQ(a.x(), 4.3);
  EXPECT_FLOAT_EQ(a.y(), -4.2);
  EXPECT_FLOAT_EQ(a.z(), 3.1);
  EXPECT_TRUE(a.IsPoint());
  EXPECT_FALSE(a.IsVector());
}

TEST_F(TupleTest, tuple_is_vector) {
  auto a = Tuple(4.3, -4.2, 3.1, 0.0);
  EXPECT_FLOAT_EQ(a.x(), 4.3);
  EXPECT_FLOAT_EQ(a.y(), -4.2);
  EXPECT_FLOAT_EQ(a.z(), 3.1);
  EXPECT_FALSE(a.IsPoint());
  EXPECT_TRUE(a.IsVector());
}

TEST_F(TupleTest, create_point_and_vector) {
  auto p = Point(4.3, -4.2, 3.1);

  EXPECT_TRUE(p.IsPoint());
  EXPECT_FALSE(p.IsVector());

  auto v = Vector(4.3, -4.2, 3.1);
  EXPECT_FALSE(v.IsPoint());
  EXPECT_TRUE(v.IsVector());
}

TEST_F(TupleTest, add_tuple){
  Tuple a1 = Tuple(3, -2, 5, 1);
  Tuple a2 = Tuple(-2, 3, 1, 0);
  auto r = a1 + a2;
  EXPECT_EQ(r, Tuple(1, 1, 6, 1));
}

TEST_F(TupleTest, subtract_tuple){
  Tuple a1 = Point(3., 2., 1.1);
  Tuple a2 = Vector(5., 6., 7.1);
  auto r = a1 - a2;
  EXPECT_EQ(r, Point(-2., -4., -6.));
}

TEST_F(TupleTest, subtract_vector_from_vector){
  Tuple a1 = Vector(3, 2, 1);
  Tuple a2 = Vector(5, 6, 7);
  auto r = a1 - a2;
  EXPECT_EQ(r, Vector(-2, -4, -6));
}

TEST_F(TupleTest, negate_tuple){
  Tuple a1 = Tuple(1, -2, 3, -4);
  auto r = -a1;
  EXPECT_EQ(r, Tuple(-1, 2, -3, 4));
}

TEST_F(TupleTest, scalar_multple){
  auto a1 = Tuple(1., -2., 3., -4.);
  auto r =  a1 * 3.5;
  EXPECT_EQ(r, Tuple(3.5, -7., 10.5, -14.));
}

TEST_F(TupleTest, scalar_multple_fraction){
  auto a1 = Tuple(1., -2., 3., -4.);
  auto r =  a1 * 0.5;
  EXPECT_EQ(r, Tuple(0.5, -1., 1.5, -2.));
}

TEST_F(TupleTest, scalar_division){
  auto a1 = Tuple(1., -2., 3., -4.);
  auto r = a1 / 2.;
  EXPECT_EQ(r, Tuple(0.5, -1., 1.5, -2.));
}

TEST_F(TupleTest, magnitude){
  EXPECT_EQ(1., (Vector(1., 0., 0.)).magnitude());
  EXPECT_EQ(1., (Vector(0., 1., 0.)).magnitude());
  EXPECT_EQ(1., (Vector(0., 0., 1.)).magnitude());
  EXPECT_EQ(sqrt(14), (Vector(1., 2., 3.)).magnitude());
  EXPECT_EQ(sqrt(14), (Vector(-1., -2., -3.)).magnitude());
}