#include <iostream>
#include "TSound.h"

TSound::TSound(std::string name_, std::string author_, int year_, int mood_, std::string genre_,
  bool isdigital_, double duration_, int channels_, bool isvoice_) : TArt::TArt()
{
  if (!isdigital_ && (channels_ != 1))
    this->channels = 1;
  else
    this->channels - channels_;
  if ((duration_ < 0) || (channels_ < 1))
    throw "Unable to create a TSound: bad duration or channels!!";
  this->duration = duration_;
  this->isvoice = isvoice_;
}

TSound::TSound(const TSound& p) : TSound::TSound()
{
  this->duration = p.duration;
  this->channels = p.channels;
  this->isvoice = p.isvoice;
}

TSound::~TSound()
{}

double TSound::GetDuration()
{
  return duration;
}
int TSound::GetChannels()
{
  if (!isdigital)
    return 1;
  return channels;
}
bool TSound::GetIsVoice()
{
  return isvoice;
}

void TSound::SetDuration(double duration_)
{
  if (duration_ > 0)
    this->duration = duration_;
  else
    throw "Unable to set duration!";
}

void TSound::SetChannels(int channels_)
{
  if (channels_ > 1)
    if (isdigital)
      this->channels = channels_;
    else
      this->channels = 1;
  else
    throw "Unable to set channels!";
}

void TSound::SetIsVoice(bool isvoice_)
{
  this->isvoice = isvoice_;
}


std::ostream& operator<<(std::ostream& o, TSound& b)
{
  o << "Duration:\t" << b.duration << "\nChannels:\t" << b.channels;
  o << "\nIsVoice:\t" << b.isvoice << std::endl;
  return o;
}
std::istream& operator>>(std::istream& i, TSound& b)
{
  std::cout << "Enter Duration of TSound:";
  i >> b.duration;
  std::cout << "Enter Channels of TSound:";
  i >> b.channels;
  std::cout << "Enter IsVoice of TSound (1 or 0):";
  i >> b.isvoice;
  return i;
}