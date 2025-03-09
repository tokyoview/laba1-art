#include <iostream>
#include "Sound.h"

Sound::Sound(char* name, char* author, int year, int mood, char* genre,
  bool isdigital, double duration, char channels, bool isvoice) : Art::Art()
{
  if (!isdigital)
    channels = 1;
  if ((duration < 0) || (channels < 1))
    throw "Unable to create a Sound: bad duration or channels!!";
}

Sound::Sound(const Sound& p) : Sound::Sound()
{
  this->duration = p.duration;
  this->channels = p.channels;
  this->isvoice = p.isvoice;
}

Sound::~Sound()
{}

double Sound::GetDuration()
{
  return duration;
}
char Sound::GetChannels()
{
  return channels;
}
bool Sound::GetIsVoice()
{
  return isvoice;
}

void Sound::SetDuration(double duration_)
{
  if (duration_ > 0)
    this->duration = duration_;
  else
    throw "Unable to set duration!";
}

void Sound::SetChannels(char channels_)
{
  if (channels_ > 1)
    if (isdigital)
      this->channels = channels_;
    else
      this->channels = 1;
  else
    throw "Unable to set channels!";
}

void Sound::SetIsVoice(bool isvoice_)
{
  this->isvoice = isvoice_;
}
