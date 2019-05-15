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