#pragma once
#include <iostream>
#include "Sound.h"

class Theatre : public Sound
{
protected:
  char* director;
  char* actors;
  char* theatre;
public:
  Theatre(char* name = "Unknown",
    char* author = "No Author",
    int year = 0,
    int mood = 0,
    char* genre = "No Genre",
    bool isdigital = false,
    double duration = 0.0,
    char channels = 0,
    bool isvoice = true,
    char* director = "Unknown Director",
    char* actors = "Unknown Actors",
    char* theatre = "Unknown Theatre");
  Theatre(const Theatre& p);
  ~Theatre();

  char* GetDirector();
  char* GetActors();
  char* GetTheatre();

  void SetDirector(char* director_);
  void SetActors(char* actors_);
  void SetTheatre(char* theatre_);

  friend std::ostream& operator <<(std::ostream& o, Theatre& b);
  friend std::istream& operator >>(std::istream& i, Theatre& b);
};
std::ostream& operator <<(std::ostream& o, Theatre& b);
std::istream& operator >>(std::istream& i, Theatre& b);