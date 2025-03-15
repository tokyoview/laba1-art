#pragma once
#include <iostream>
#include "TSound.h"

class TMusic : public TSound
{
protected:
  int voices;
  std::string instruments;
  long long int listeners;
public:
  TMusic(std::string name = "Unknown",
    std::string author = "No Author",
    int year = 0,
    int mood = 0,
    std::string genre = "No Genre",
    bool isdigital = true,
    double duration = 0.0,
    int channels = 2,
    bool isvoice = true,
    int voices = 4,
    std::string instruments = "No Instruments",
    long long int listeners = 1);
  TMusic(const TMusic& p);
  ~TMusic();

  int GetVoices();
  std::string GetInstruments();
  long long int GetListeners();

  void SetVoices(int voices_);
  void SetInstruments(std::string instruments_);
  void SetListeners(long long int listeners_);

  friend std::ostream& operator <<(std::ostream& o, TMusic& b);
  friend std::istream& operator >>(std::istream& i, TMusic& b);
};
std::ostream& operator <<(std::ostream& o, TMusic& b);
std::istream& operator >>(std::istream& i, TMusic& b);