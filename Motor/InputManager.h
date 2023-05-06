#pragma once
#include <glm/glm.hpp>
#include <unordered_map>

class InputManager
{
private:
	unordered_map<unsigned int,bool> keys;
	glm::vec2 mouseCoords;
public:
};
