#include <iostream>
#include "Music.h"

Music::Music(char* name, char* author, int year, int mood, char* genre,
  bool isdigital, double duration, char channels, bool isvoice, int voices,
  char* instuments, long long int listeners) : Sound::Sound()
{
  if ((voices < 1) || (listeners < 1))
    throw "Unable to create a Music: bad voices or listeners value!";
}

Music::Music(const Music& p) : Music::Music()
{
  this->voices = p.voices;
  this->instruments = p.instruments;
  //delete[] p.instruments;
  this->listeners = p.listeners;
}

Music::~Music()
{}

int Music::GetVoices()
{
  return voices;
}
char* Music::GetInstruments()
{
  return instruments;
}
long long int Music::GetListeners()
{
  return listeners;
}

void Music::SetVoices(int voices_)
{
  if (voices_ > 1)
    this->voices = voices_;
  else
    throw "Unable to set voices!";
}

void Music::SetInstruments(char* instruments_)
{
  if (instruments_ != nullptr)
  {
    //delete[] this->instruments;
    this->instruments = instruments_;
  }
  else
    throw "Unable to set new value: Wrong instruments!";
}

void Music::SetListeners(long long int listeners_)
{
  if (listeners_ > 1)
    this->listeners = listeners_;
  else
    throw "Unable to set listeners!";
}
