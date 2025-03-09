#pragma once
#include <iostream>
#include "Sound.h"

class Music : public Sound
{
protected:
  int voices;
  char* instruments;
  long long int listeners;
public:
  Music(char* name = "Unknown",
    char* author = "No Author",
    int year = 0,
    int mood = 0,
    char* genre = "No Genre",
    bool isdigital = true,
    double duration = 0.0,
    char channels = 2,
    bool isvoice = true,
    int voices = 4,
    char* instuments = nullptr,
    long long int listeners = 1);
  Music(const Music& p);
  ~Music();

  int GetVoices();
  char* GetInstruments();
  long long int GetListeners();

  void SetVoices(int voices_);
  void SetInstruments(char* instruments_);
  void SetListeners(long long int listeners_);

  friend std::ostream& operator <<(std::ostream& o, Music& b);
  friend std::istream& operator >>(std::istream& i, Music& b);
};
std::ostream& operator <<(std::ostream& o, Music& b);
std::istream& operator >>(std::istream& i, Music& b);