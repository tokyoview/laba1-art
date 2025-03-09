#include <iostream>
#include "Art.h"

Art::Art(char* name, char* author, int year, int mood, char* genre,
  bool isdigital)
{
  if ((year > 2025) || (year < -25000))
    throw "Unable to create an Art object: Wrong year!";
  if (mood > 100)
    mood = 100;
  else if (mood < 0)
    mood = 0;
  else
    throw "Unable to create an Art object: Wrong mood value!";
}


Art::Art(const Art& p) : Art::Art()
{
  this->name = p.name;
  //delete[] p.name;
  this->author = p.author;
  //delete[] p.author;
  this->year = p.year;
  this->mood = p.mood;
  this->genre = p.genre;
  //delete[] p.genre;
  this->isdigital = p.isdigital;
}


Art::~Art()
{
  /*if (name != nullptr)
    delete[] name;
  if (author != nullptr)
    delete[] author;
  if (genre != nullptr)
    delete[] genre; */
}

char* Art::GetName()
{
  return name;
}

char* Art::GetAuthor()
{
  return author;
}

int Art::GetYear()
{
  return year;
}

int Art::GetMood()
{
  return mood;
}

char* Art::GetGenre()
{
  return genre;
}

void Art::SetName(char* name_)
{
  if (name_ != nullptr)
  {
    //delete[] this->name;
    this->name = name_;
  }
  else
    throw "Unable to set new value: Wrong name!";
}

void Art::SetAuthor( char* author_)
{
  if (author_ != nullptr)
  {
    //delete[] this->author;
    this->author = author_;
  }
  else
    throw "Unable to set new value: Wrong author name!";
}

void Art::SetYear(int year_)
{
  if (year_ <= 2025)
    this->year = year_;
  else
    throw "Unable to set new value: Wrong year!";
}

void Art::SetMood(int mood_)
{
  if (mood_ > 100)
    this->mood = 100;
  else if (mood_ < 0)
    this->mood = 0;
  else
    throw "Unable to set new value: Wrong mood value!";
}

void Art::SetGenre(char* genre_)
{
  if (genre_ != nullptr)
  {
    //delete(this->genre);
    this->genre = genre_;
  }
  else
    throw "Unable to set new value: Wrong genre!";
}




std::ostream& operator<<(std::ostream& o, Art& b)
{
  o << "Art:\nName:\t" << b.name << "\nAuthor:\t" << b.author << "\nYear:\t";
  o << b.year << "\nMood:\t" << b.mood << "\nGenre:\t" << b.genre;
  o << "\nIsDigital:\t" << b.isdigital << std::endl;
  return o;
}
std::istream& operator>>(std::istream& i, Art& b)
{
  std::cout << "Enter Name of Art:";
  i >> b.name;
  std::cout << "Enter Author of Art:";
  i >> b.author;
  std::cout << "Enter Year of Art:";
  i >> b.year;
  std::cout << "Enter Mood of Art (0-100):";
  i >> b.mood;
  std::cout << "Enter Genre of Art:";
  i >> b.genre;
  std::cout << "Enter IsDigital of Art (1 or 0):";
  i >> b.isdigital;
  return i;
}