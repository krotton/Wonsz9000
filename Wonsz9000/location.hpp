// 3D location related routines and classes.

#pragma once

#include "essentials.hpp"


namespace wonsz9000
{
	// Represents a vector in 3D euclidean space.
	struct Vec3D
	{
		double x, y, z;

		Vec3D(double const x = 0.0, double const y = 0.0, double const z = 0.0):
			x(x), y(y), z(z)
		{}

		Vec3D operator+(Vec3D const& other) const
		{
			Vec3D new_vec = *this;
			return new_vec += other;
		}

		Vec3D& operator+=(Vec3D const& other)
		{
			x += other.x;
			y += other.y;
			z += other.z;

			return *this;
		}

		Vec3D operator-() const
		{
			return {-x, -y, -z};
		}

		Vec3D operator-(Vec3D const& other) const
		{
			return other + (-*this);
		}
	};

	// Represents a location in 3D.
	using Location = Vec3D;

	// Represents a distance in 3D.
	using Distance = Vec3D;

	// Represents a rotation in 3D.
	using Rotation = Vec3D;
}
