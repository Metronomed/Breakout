#ifndef INPUT_MANAGER_H_
#define INPUT_MANAGER_H_

#include <SDL.h>

class InputManager {
public:
	void startUp();
	void shutDown();

	void updateStates();

	bool wasKeyPressed(SDL_Scancode key) const;
	bool wasKeyReleased(SDL_Scancode key) const;
	bool isKeyHeld(SDL_Scancode key) const;

	bool wasMBClicked(int MB) const;
	bool wasMBReleased(int MB) const;
	bool isMBHeld(int MB) const;
	void getMouseLocation(int* x, int* y);

private:
	static bool isInstantiated;
	static const int numScancodes = 282;

	void updateKeyStates();
	void updateMouseState();

	bool m_pressedKeys[numScancodes];
	bool m_releasedKeys[numScancodes];
	bool m_heldKeys[numScancodes];

	struct MouseState
	{
		int x;
		int y;
		
		bool clickedMouseButtons[3];
		bool releasedMouseButtons[3];
		bool heldMouseButtons[3];
	};

	MouseState m_Mouse;
};

#endif