#pragma once

#include "Devices/Joysticks.hpp"
#include "Inputs/InputAxis.hpp"

namespace acid {
/**
 * @brief InputAxis input from a joystick input device.
 */
class ACID_EXPORT JoystickInputAxis : public InputAxis::Registrar<JoystickInputAxis> {
	inline static const bool Registered = Register("joystick");
public:
	/**
	 * Creates a new axis joystick.
	 * @param port The joystick port.
	 * @param axis The axis on the joystick being checked.
	 */
	explicit JoystickInputAxis(JoystickPort port = 0, JoystickAxis axis = 0);

	float GetAmount() const override;

	ArgumentDescription GetArgumentDescription() const override;

	bool IsConnected() const;

	JoystickPort GetPort() const { return port; }
	void SetPort(JoystickPort port) { this->port = port; }

	JoystickAxis GetAxis() const { return axis; }
	void SetAxis(JoystickAxis axis) { this->axis = axis; }

	friend const Node &operator>>(const Node &node, JoystickInputAxis &joystick);
	friend Node &operator<<(Node &node, const JoystickInputAxis &joystick);

private:
	JoystickPort port;
	JoystickAxis axis;
};
}
