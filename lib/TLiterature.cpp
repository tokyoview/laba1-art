#include <iostream>
#include "TLiterature.h"

TLiterature::TLiterature(std::string name_, std::string author_, int year_, int mood_,
  std::string genre_, bool isdigital_, int width_, int height_, bool ismono_,
  bool ismoving_, std::string language_, int parts_,
  bool ispoetry_) : TImage::TImage()
{
  this->width = this->height = 0; // because it's a book! hee hee
  this->language = language_;
  this->parts = parts_;
  this->ispoetry = ispoetry_;
}
  
TLiterature::TLiterature(const TLiterature& p)
{
  this->language = p.language;
  //delete[] p.language;
  this->parts = p.parts;
  this->ispoetry = p.ispoetry;

}

TLiterature::~TLiterature()
{}

std::string TLiterature::GetLanguage()
{
  return language;
}

int TLiterature::GetParts()
{
  return parts;
}

bool TLiterature::GetIsPoetry()
{
  return ispoetry;
}

void TLiterature::SetLanguage(std::string language_)
{
  if (language_ != "")
    this->language = language_;
}

void TLiterature::SetParts(int parts_)
{
  if (parts_ > 0)
    this->parts = parts_;
  else
    throw("Unable to set parts!");
}
void TLiterature::SetIsPoetry(bool ispoetry_)
{
  this->ispoetry = ispoetry_;
}
