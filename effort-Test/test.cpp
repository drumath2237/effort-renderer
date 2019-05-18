#include "pch.h"
#include "gtest/gtest.h"

#include "../efffort-renderer/Vector3.h"


TEST(VectorTest, Constructor1) {
	auto v = Vector3();
	EXPECT_EQ(v.x, 0);
	EXPECT_EQ(v.y, 0);
	EXPECT_EQ(v.z, 0);
}

TEST(VectorTest, Constructor2) {
	auto v = Vector3(5.);
	EXPECT_EQ(v.x, 5.);
	EXPECT_EQ(v.y, 5.);
	EXPECT_EQ(v.z, 5.);
}

TEST(VectorTest, Constructor3) {
	auto v = Vector3(5., 4.);
	EXPECT_EQ(v.x, 5.);
	EXPECT_EQ(v.y, 4.);
	EXPECT_EQ(v.z, 0);
}

TEST(VectorTest, Constructor4) {
	auto v = Vector3(5., 4., 3.);
	EXPECT_EQ(v.x, 5.);
	EXPECT_EQ(v.y, 4.);
	EXPECT_EQ(v.z, 3.);
}

TEST(VectorTest, operation) {
	auto v1 = Vector3();
	auto v2 = Vector3(1., 2.);

	EXPECT_EQ(v1 + v2, Vector3(1., 2., 0));
	EXPECT_EQ(v1 - v2, Vector3(-1., -2., 0));

	v1 = Vector3(1.);

	EXPECT_EQ(v1 * v2, Vector3(1., 2., 0));
}

TEST(VectorTest, dot_and_cross) {
	auto v1 = Vector3(1.);
	auto v2 = Vector3(1., 2.);

	EXPECT_EQ(dot(v1, v2), 3.);
	EXPECT_EQ(cross(v1, v2), Vector3(-2, 1, 1));
}

TEST(VectorTest, length_and_normalize) {
	auto v = Vector3(1.);
	EXPECT_EQ(v.length(), sqrt(3));
	EXPECT_EQ(normalize(v).length(), 1.);
}