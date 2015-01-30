// GL utility routines and helpers.

#pragma once

#include "essentials.hpp"

#include "location.hpp"


namespace wonsz9000
{
	// Fancier, RAII-enabled matrix transform support with chaining.
	template <int MatrixMode = GL_MODELVIEW>
	class Transform
	{
	public:
		Transform()
		{
			// Save current matrix mode - it will be restored upon destruction.
			glGetIntegerv(GL_MATRIX_MODE, &prev_mode_);

			glMatrixMode(MatrixMode);
			glPushMatrix();
		}

		~Transform()
		{
			glPopMatrix();
			glMatrixMode(prev_mode_);
		}

		// Translate by a vector.
		Transform const& translate(Distance const by) const
		{
			glTranslated(by.x, by.y, by.z);

			return *this;
		}

		// Rotate by a vector of angles.
		Transform const& rotate(Rotation const by) const
		{
			glRotated(by.x, 1.0, 0.0, 0.0);
			glRotated(by.y, 0.0, 1.0, 0.0);
			glRotated(by.z, 0.0, 0.0, 1.0);

			return *this;
		}

		// Scale by a vector of coefficients.
		Transform const& scale(Vec3D const by) const
		{
			glScaled(by.x, by.y, by.z);

			return *this;
		}

	private:
		int prev_mode_;
	};
}
