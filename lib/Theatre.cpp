#include <iostream>
#include "Theatre.h"

Theatre::Theatre(char* name, char* author, int year, int mood, char* genre,
  bool isdigital, double duration, char channels, bool isvoice, 
  char* director, char* actors, char* theatre) : Sound::Sound()
{}

Theatre::Theatre(const Theatre& p) : Theatre::Theatre()
{
  this->director = p.director;
  this->actors = p.actors;
  this->theatre = p.theatre;
}

Theatre::~Theatre()
{}

char* Theatre::GetDirector()
{
  return director;
}
char* Theatre::GetActors()
{
  return actors;
}
char* Theatre::GetTheatre()
{
  return theatre;
}

void Theatre::SetDirector(char* director_)
{
  if (director_ != nullptr)
    this->director = director_;
  else
    throw "Unable to set director!";
}

void Theatre::SetActors(char* actors_)
{
  if (actors_ != nullptr)
    this->actors = actors_;
  else
    throw "Unable to set actors!";
}

void Theatre::SetTheatre(char* theatre_)
{
  if (theatre_ != nullptr)
    this->theatre = theatre_;
  else
    throw "Unable to set theatre!";
}
