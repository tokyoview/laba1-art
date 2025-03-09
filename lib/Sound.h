#pragma once
#include <iostream>
#include "Art.h"

class Sound : public Art
{
protected:
  double duration; // in minutes
  char channels; // number of channels
  bool isvoice; // is there human voice
public:
  Sound(char* name = "Unknown",
    char* author = "No Author",
    int year = 0,
    int mood = 0,
    char* genre = "No Genre",
    bool isdigital = true,
    double duration = 0.0,
    char channels = 2,
    bool isvoice = true);
  Sound(const Sound& p);
  ~Sound();

  double GetDuration();
  char GetChannels();
  bool GetIsVoice();

  void SetDuration(double duration_);
  void SetChannels(char channels_);
  void SetIsVoice(bool isvoice_);

  friend std::ostream& operator <<(std::ostream& o, Sound& b);
  friend std::istream& operator >>(std::istream& i, Sound& b);
};
std::ostream& operator <<(std::ostream& o, Sound& b);
std::istream& operator >>(std::istream& i, Sound& b);