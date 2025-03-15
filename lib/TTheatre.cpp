#include <iostream>
#include "TTheatre.h"

TTheatre::TTheatre(std::string name_, std::string author_, int year_, int mood_, std::string genre_,
  bool isdigital_, double duration_, int channels_, bool isvoice_, 
  std::string director_, std::string actors_, std::string theatre_) : TSound::TSound()
{
  this->director = director_;
  this->actors = actors_;
  this->theatre = theatre_;
}

TTheatre::TTheatre(const TTheatre& p) : TTheatre::TTheatre()
{
  this->director = p.director;
  this->actors = p.actors;
  this->theatre = p.theatre;
}

TTheatre::~TTheatre()
{}

std::string TTheatre::GetDirector()
{
  return director;
}
std::string TTheatre::GetActors()
{
  return actors;
}
std::string TTheatre::GetTheatre()
{
  return theatre;
}

void TTheatre::SetDirector(std::string director_)
{
  if (director_ != "")
    this->director = director_;
  else
    throw "Unable to set director!";
}

void TTheatre::SetActors(std::string actors_)
{
  if (actors_ != "")
    this->actors = actors_;
  else
    throw "Unable to set actors!";
}

void TTheatre::SetTheatre(std::string theatre_)
{
  if (theatre_ != "")
    this->theatre = theatre_;
  else
    throw "Unable to set TTheatre!";
}
