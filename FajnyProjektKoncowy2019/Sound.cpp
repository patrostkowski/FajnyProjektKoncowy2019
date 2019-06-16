#include "Sound.h"



Sound::Sound(std::string theme)
{
		music.openFromFile("song.wav");
		if (!music.openFromFile("song.wav"))
		{
			std::cout << "could not load music!";
		}
		music.setVolume(99);
		music.play();
		music.setLoop(true);
}

Sound::Sound()
{
	sounds[0].openFromFile("chirp.wav");
	if (!music.openFromFile("chirp.wav"))
	{
		std::cout << "could not load chirp!";
	}

	sounds[1].openFromFile("chirp2.wav");
	if (!music.openFromFile("chirp2.wav"))
	{
		std::cout << "could not load chirp2!";
	}

	for (auto i = 0; i < 2; i++)
	{
		sounds[i].setVolume(75);
	}
}

void Sound::playSound(int i)
{
	sounds[i].play();
}

void Sound::muteSound()
{
	music.setVolume(0);
}

void Sound::unmuteSound()
{
	music.setVolume(musicVolume);
}

bool Sound::isMusicMuted()
{
	if(music.getVolume()==0)
		return true;
	else return false;
}
