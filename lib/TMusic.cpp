#include <iostream>
#include "TMusic.h"

TMusic::TMusic(std::string name_, std::string author_, int year_, int mood_, std::string genre_,
  bool isdigital_, double duration_, int channels_, bool isvoice_, int voices_,
  std::string instruments_, long long int listeners_) : TSound::TSound()
{
  if ((voices_ < 1) || (listeners_ < 1))
    throw "Unable to create a TMusic: bad voices or listeners value!";
  else
  {
    this->voices = voices_;
    this->listeners = listeners_;
  }
  this->instruments = instruments_;
}

TMusic::TMusic(const TMusic& p) : TMusic::TMusic()
{
  this->voices = p.voices;
  this->instruments = p.instruments;
  this->listeners = p.listeners;
}

TMusic::~TMusic()
{}

int TMusic::GetVoices()
{
  return voices;
}
std::string TMusic::GetInstruments()
{
  return instruments;
}
long long int TMusic::GetListeners()
{
  return listeners;
}

void TMusic::SetVoices(int voices_)
{
  if (voices_ > 1)
    this->voices = voices_;
  else
    throw "Unable to set voices!";
}

void TMusic::SetInstruments(std::string instruments_)
{
  if (instruments_ != "")
  {
    this->instruments = instruments_;
  }
  else
    throw "Unable to set new value: Wrong instruments!";
}

void TMusic::SetListeners(long long int listeners_)
{
  if (listeners_ > 1)
    this->listeners = listeners_;
  else
    throw "Unable to set listeners!";
}

std::ostream& operator<<(std::ostream& o, TMusic& b)
{
  o << "Voices:\t" << b.voices << "\nInstruments:\t" << b.instruments;
  o << "\nListeners:\t" << b.listeners << std::endl;
  return o;
}
std::istream& operator>>(std::istream& i, TMusic& b)
{
  std::cout << "Enter Voices of TMusic:";
  i >> b.voices;
  std::cout << "Enter Instruments of TMusic:";
  i >> b.instruments;
  std::cout << "Enter Listeners of TMusic:";
  i >> b.listeners;
  return i;
}