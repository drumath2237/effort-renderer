#include "pch.h"
#include "gtest/gtest.h"

#include "../efffort-renderer/Vector3.h"
#include "../efffort-renderer/Ray.h"
#include "../efffort-renderer/Image.h"
#include "../efffort-renderer/util.h"

TEST(util, clamp_test) {
	EXPECT_EQ(clamp(1, 2, 3), 2);
	EXPECT_EQ(clamp(1, 3, 2), 2);
	EXPECT_EQ(clamp(2, 1, 3), 2);
}

TEST(RayTest, Constructor) {
	Ray r = Ray();
	EXPECT_EQ(r.direction.x, 1);
	EXPECT_EQ(r.direction.y, 0);

	EXPECT_EQ(r.origin, Vector3());
}

TEST(RayTest, Constructor2) {
	Ray r = Ray(Vector3(1, 2, 3), Vector3(4, 5, 6));
	EXPECT_EQ(r.direction, Vector3(4, 5, 6));
	EXPECT_EQ(r.origin, Vector3(1, 2, 3));
}

TEST(RayTest, t_) {
	Ray r = Ray();
	EXPECT_EQ(r(3.), Vector3(3., 0, 0));
}



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