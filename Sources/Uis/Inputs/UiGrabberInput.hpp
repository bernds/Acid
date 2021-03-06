#pragma once

#include "Devices/Joysticks.hpp"
#include "Devices/Keyboard.hpp"
#include "Devices/Mouse.hpp"
#include "Fonts/Text.hpp"
#include "Guis/Gui.hpp"
#include "Uis/UiObject.hpp"
#include "UiButtonInput.hpp"

namespace acid {
class ACID_EXPORT UiGrabberInput : public UiObject {
public:
	UiGrabberInput();

	void UpdateObject() override;

	const std::string &GetTitle() const { return textTitle.GetString(); }
	void SetTitle(const std::string &string) { textTitle.SetString(string); }

protected:
	virtual std::string GetTextString() const = 0;

	void SetUpdating(bool updating);
	void UpdateValue();

	Gui background;
	Text textTitle;
	Text textValue;

	int32_t lastKey = 0;

	bool updating = false;
	bool mouseOver = false;
};

class ACID_EXPORT UiGrabberJoystick : public UiGrabberInput {
public:
	UiGrabberJoystick();

	uint32_t GetPort() const { return port; }
	void SetPort(uint32_t port) { this->port = port; }

	uint32_t GetValue() const { return value; }
	void SetValue(uint32_t value);

	/**
	 * Called when this value of the input changes.
	 * @return The delegate.
	 */
	Delegate<void(uint32_t, uint32_t)> &OnValue() { return onValue; }

protected:
	std::string GetTextString() const override {
		return String::To(value);
	}

private:
	uint32_t port = 0; // -1
	uint32_t value = 0;
	Delegate<void(uint32_t, uint32_t)> onValue;
};

class ACID_EXPORT UiGrabberKeyboard : public UiGrabberInput {
public:
	UiGrabberKeyboard();

	Key GetValue() const { return value; }
	void SetValue(Key value);

	/**
	 * Called when this value of the input changes.
	 * @return The delegate.
	 */
	Delegate<void(Key)> &OnValue() { return onValue; }

protected:
	std::string GetTextString() const override {
		return Keyboard::ToString(value);
	}

private:
	Key value = Key::Unknown;
	Delegate<void(Key)> onValue;
};

class ACID_EXPORT UiGrabberMouse : public UiGrabberInput {
public:
	UiGrabberMouse();

	MouseButton GetValue() const { return value; }
	void SetValue(MouseButton value);

	/**
	 * Called when this value of the input changes.
	 * @return The delegate.
	 */
	Delegate<void(MouseButton)> &OnValue() { return onValue; }

protected:
	std::string GetTextString() const override {
		return String::To(static_cast<int32_t>(value));
	}

private:
	MouseButton value = MouseButton::Last;
	Delegate<void(MouseButton)> onValue;
};
}
