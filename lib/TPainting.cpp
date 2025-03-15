#include <iostream>
#include "TPainting.h"

TPainting::TPainting(std::string name_, std::string author_, int year_, int mood_, std::string genre_,
  bool isdigital_, int width_, int height_, bool ismono_, bool ismoving_, 
  std::string painttype_, int diagonalsize_, std::string tools_) : TImage::TImage()
{
  if (diagonalsize_ < 1)
    throw "Unable to create a TPainting: bad size!";
  else
    this->diagonalsize = diagonalsize_;
  this->painttype = painttype_;
  this->tools = tools_;
}

TPainting::TPainting(const TPainting& p) : TPainting::TPainting()
{
  this->painttype = p.painttype;
  this->diagonalsize = p.diagonalsize;
  this->tools = p.tools; 
}

TPainting::~TPainting()
{}

std::string TPainting::GetPaintType()
{
  return painttype;
}
int TPainting::GetDiagonalSize()
{
  return diagonalsize;
}
std::string TPainting::GetTools()
{
  return tools;
}

void TPainting::SetPaintType(std::string painttype_)
{
  if (painttype_ != "")
    this->painttype = painttype_;
  else
    throw "Unable to set paint type!";
}

void TPainting::SetDiagonalSize(int diagonalsize_)
{
  this->diagonalsize = diagonalsize_;
}

void TPainting::SetTools(std::string tools_)
{
  if (tools_ != "")
    this->tools = tools_;
  else
    throw "Unable to set paint tools!";
}
