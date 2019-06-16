#pragma once
#include "SFML/Audio.hpp"
#include <iostream>
class Sound
{
	sf::Music music;
	sf::Music sounds[2];
	float musicVolume = 75.f;
public:
	Sound(std::string theme);
	Sound();
	void playSound(int i);
	void muteSound();
	void unmuteSound();
	bool isMusicMuted();
};

