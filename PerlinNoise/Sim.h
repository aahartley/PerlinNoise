#pragma once
#include <SFML/Graphics.hpp>
class Sim {
public:
	Sim();
	void run();
private:
	sf::RenderWindow* window;
};