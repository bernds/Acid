#pragma once

#include "Maths/Vector3.hpp"

namespace acid
{
	/// <summary>
	/// A interface that defines a particle spawn type.
	/// </summary>
	class ACID_EXPORT ISpawnParticle
	{
	public:
		virtual void Decode(const Node &node) = 0;

		virtual void Encode(Node &node) const = 0;

		/// <summary>
		/// Gets the base spawn position.
		/// </summary>
		/// <returns> The base spawn position. </returns>
		virtual Vector3 GetBaseSpawnPosition() = 0;
	};
}
