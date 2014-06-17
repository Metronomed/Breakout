#include "InputManager.h"
#include <stdio.h>

bool InputManager::isInstantiated = false;

void InputManager::startUp() {
	if (isInstantiated == true) {
		printf("InputManager already instantiated, should not happen again.");
	}
	else {
		isInstantiated = true;
		for (int key = 0; key < InputManager::numScancodes; ++key) {
			m_pressedKeys[key] = false;
			m_releasedKeys[key] = false;
			m_heldKeys[key] = false;
		}

		m_Mouse.x = 0;
		m_Mouse.y = 0;
		for (int MB = 0; MB < 1; ++MB) {
			m_Mouse.clickedMouseButtons[MB] = false;
			m_Mouse.releasedMouseButtons[MB] = false;
			m_Mouse.heldMouseButtons[MB] = false;
		}
	}
}

void InputManager::shutDown() {
	isInstantiated = false;
}

void InputManager::updateStates() {
	updateKeyStates();
	updateMouseState();
}

void InputManager::updateKeyStates() {
	const Uint8* keyStates = SDL_GetKeyboardState(NULL);
	for (int key = 0; key < InputManager::numScancodes; ++key) {
		const bool prevHeld = m_heldKeys[key];
		const bool currKeyState = keyStates[key];

		m_pressedKeys[key] = (prevHeld == false && currKeyState == true);
		m_releasedKeys[key] = (prevHeld == true && currKeyState == false);
		m_heldKeys[key] = currKeyState;
	}
}

void InputManager::updateMouseState() {
	const Uint32 mouseButtonState = SDL_GetMouseState(&m_Mouse.x, &m_Mouse.y);
	
	for (int MB = 0; MB < 3; ++MB) {
		const bool currMBState = mouseButtonState&SDL_BUTTON(MB+1);
		const bool prevHeld = m_Mouse.heldMouseButtons[MB];

		m_Mouse.clickedMouseButtons[MB] = (prevHeld == false && currMBState == true);
		m_Mouse.releasedMouseButtons[MB] = (prevHeld == true && currMBState == false);
		m_Mouse.heldMouseButtons[MB] = currMBState;
	}

}

bool InputManager::wasKeyPressed(SDL_Scancode key) const {
	return m_pressedKeys[key];
}

bool InputManager::wasKeyReleased(SDL_Scancode key) const {
	return m_releasedKeys[key];
}

bool InputManager::isKeyHeld(SDL_Scancode key) const {
	return m_heldKeys[key];
}

//use 0 = LB, 1 = MB, 2 = RB
bool InputManager::wasMBClicked(int MB) const {
	return m_Mouse.clickedMouseButtons[MB];
}

bool InputManager::wasMBReleased(int MB) const {
	return m_Mouse.releasedMouseButtons[MB];
}

bool InputManager::isMBHeld(int MB) const {
	return m_Mouse.heldMouseButtons[MB];
}

void InputManager::getMouseLocation(int* x, int* y) {
	(*x) = m_Mouse.x;
	(*y) = m_Mouse.y;
}