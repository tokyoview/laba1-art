#pragma once
#include <iostream>
#include "TArt.h"

class TSound : public TArt
{
protected:
  double duration; // in minutes
  int channels; // number of channels
  bool isvoice; // is there human voice
public:
  TSound(std::string name = "Unknown",
    std::string author = "No Author",
    int year = 0,
    int mood = 0,
    std::string genre = "No Genre",
    bool isdigital = true,
    double duration = 0.0,
    int channels = 2,
    bool isvoice = true);
  TSound(const TSound& p);
  ~TSound();

  double GetDuration();
  int GetChannels();
  bool GetIsVoice();

  void SetDuration(double duration_);
  void SetChannels(int channels_);
  void SetIsVoice(bool isvoice_);

  friend std::ostream& operator <<(std::ostream& o, TSound& b);
  friend std::istream& operator >>(std::istream& i, TSound& b);

  void WhoAmI() override
  {
    std::cout << "I am TSound!" << std::endl;
  }
};
std::ostream& operator <<(std::ostream& o, TSound& b);
std::istream& operator >>(std::istream& i, TSound& b);