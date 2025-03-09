#include <iostream>
#include "Literature.h"

Literature::Literature(char* name, char* author, int year, int mood,
  char* genre, bool isdigital, int* resolution, bool ismono,
  bool ismoving, char* language, unsigned int parts,
  bool ispoetry) : Image::Image()
{
  if (resolution != nullptr)
  {
    delete[] resolution;
    resolution = nullptr; // because it's a book! hee hee
  }
}
  
Literature::Literature(const Literature& p)
{
  this->language = p.language;
  //delete[] p.language;
  this->parts = p.parts;
  this->ispoetry = p.ispoetry;

}

Literature::~Literature()
{}

char* Literature::GetLanguage()
{
  return language;
}

unsigned int Literature::GetParts()
{
  return parts;
}

bool Literature::GetIsPoetry()
{
  return ispoetry;
}

void Literature::SetLanguage(char* language_)
{
  if (language_ != nullptr)
    //delete(language);
    this->language = language_;
    //delete(language_);
}

void Literature::SetParts(unsigned int parts_)
{
  if (parts_ > 0)
    this->parts = parts_;
  else
    throw("Unable to set parts!");
}
void Literature::SetIsPoetry(bool ispoetry_)
{
  this->ispoetry = ispoetry_;
}
