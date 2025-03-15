#pragma once
#include <iostream>
#include "TSound.h"

class TTheatre : public TSound
{
protected:
  std::string director;
  std::string actors;
  std::string theatre;
public:
  TTheatre(std::string name = "Unknown",
    std::string author = "No Author",
    int year = 0,
    int mood = 0,
    std::string genre = "No Genre",
    bool isdigital = false,
    double duration = 0.0,
    int channels = 0,
    bool isvoice = true,
    std::string director = "Unknown Director",
    std::string actors = "Unknown Actors",
    std::string theatre = "Unknown Theatre");
  TTheatre(const TTheatre& p);
  ~TTheatre();

  std::string GetDirector();
  std::string GetActors();
  std::string GetTheatre();

  void SetDirector(std::string director_);
  void SetActors(std::string actors_);
  void SetTheatre(std::string theatre_);

  friend std::ostream& operator <<(std::ostream& o, TTheatre& b);
  friend std::istream& operator >>(std::istream& i, TTheatre& b);
};
std::ostream& operator <<(std::ostream& o, TTheatre& b);
std::istream& operator >>(std::istream& i, TTheatre& b);