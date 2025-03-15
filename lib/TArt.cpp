#include <iostream>
#include "TArt.h"


TArt::TArt(std::string name_, std::string author_,
  int year_, int mood_, std::string genre_,
  bool isdigital_)
{
  if ((year_ > 2025) || (year_ < -25000))
    throw "Unable to create an TArt object: Wrong year!";
  this->name = name_;
  this->author = author_;
  this->year = year_;
  this->mood = mood_;
  this->genre = genre_;
  this->isdigital = isdigital_;
}


TArt::TArt(const TArt& p) : TArt::TArt()
{
  this->name = p.name;
  this->author = p.author;
  this->year = p.year;
  this->mood = p.mood;
  this->genre = p.genre;
  this->isdigital = p.isdigital;
}


TArt::~TArt()
{}

std::string TArt::GetName()
{
  return name;
}

std::string TArt::GetAuthor()
{
  return author;
}

int TArt::GetYear()
{
  return year;
}

int TArt::GetMood()
{
  if (mood > 100)
    return 100;
  else if (mood < 0)
    return  0;
  return mood;
}

std::string TArt::GetGenre()
{
  return genre;
}

bool TArt::GetIsDigital()
{
  return isdigital;
}

void TArt::SetName(std::string name_)
{
  if (name_ != "")
  {
    this->name = name_;
  }
  else
    throw "Unable to set new value: Wrong name!";
}

void TArt::SetAuthor(std::string author_)
{
  if (author_ != "")
  {
    this->author = author_;
  }
  else
    throw "Unable to set new value: Wrong author name!";
}

void TArt::SetYear(int year_)
{
  if (year_ <= 2025)
    this->year = year_;
  else
    throw "Unable to set new value: Wrong year!";
}

void TArt::SetMood(int mood_)
{
  if (mood_ > 100)
    this->mood = 100;
  else if (mood_ < 0)
    this->mood = 0;
  else
    throw "Unable to set new value: Wrong mood value!";
}

void TArt::SetGenre(std::string genre_)
{
  if (genre_ != "")
  {
    this->genre = genre_;
  }
  else
    throw "Unable to set new value: Wrong genre!";
}

void TArt::SetIsDigital(bool isdigital_)
{
  this->isdigital = isdigital_;
}


std::ostream& operator<<(std::ostream& o, TArt& b)
{
  o << "TArt:\nName:\t" << b.name << "\nAuthor:\t" << b.author << "\nYear:\t";
  o << b.year << "\nMood:\t" << b.mood << "\nGenre:\t" << b.genre;
  o << "\nIsDigital:\t" << b.isdigital << std::endl;
  return o;
}

std::istream& operator>>(std::istream& i, TArt& b)
{
  std::cout << "Enter Name of TArt:";
  i >> b.name;
  std::cout << "Enter Author of TArt:";
  i >> b.author;
  std::cout << "Enter Year of TArt:";
  i >> b.year;
  std::cout << "Enter Mood of TArt (0-100):";
  i >> b.mood;
  std::cout << "Enter Genre of TArt:";
  i >> b.genre;
  std::cout << "Enter IsDigital of TArt (1 or 0):";
  i >> b.isdigital;
  return i;
}

void TArt::WhoAmI()
{
  std::cout << "I am TArt!" << std::endl;
}