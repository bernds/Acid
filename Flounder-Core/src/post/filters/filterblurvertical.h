#pragma once

#include "../../devices/display.h"
#include "../ipostfilter.h"

namespace flounder
{
	class filterblurvertical :
		public ipostfilter
	{
	private:
		int m_heightValue;
		float m_scaleValue;
		bool m_fitToDisplay;
		float m_sizeScalar;
	public:
		filterblurvertical(const float &sizeScalar);

		filterblurvertical(const int &width, const int &height);

		~filterblurvertical();

		void storeValues() override;

		inline void setScaleValue(const float &scaleValue) { m_scaleValue = scaleValue; }
	};
}
