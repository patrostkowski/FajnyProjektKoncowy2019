#pragma once
#include "SFML/Audio.hpp"
#include <iostream>
class Sound
{
	sf::Music music;
	sf::Music sounds[2];
public:
	Sound(std::string theme);
	Sound();
	void playSound(int i);
};

