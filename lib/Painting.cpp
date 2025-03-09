#include <iostream>
#include "Painting.h"

Painting::Painting(char* name, char* author, int year, int mood, char* genre,
  bool isdigital, int* resolution, bool ismono, bool ismoving, 
  char* painttype, int diagonalsize, char* tools) : Image::Image()
{
  if (diagonalsize < 1)
    throw "Unable to create a Painting: bad size!";
}

Painting::Painting(const Painting& p) : Painting::Painting()
{
  this->painttype = p.painttype;
  this->diagonalsize = p.diagonalsize;
  this->tools = p.tools; 
  //delete[] p.tools;
}

Painting::~Painting()
{}

char* Painting::GetPaintType()
{
  return painttype;
}
int Painting::GetDiagonalSize()
{
  return diagonalsize;
}
char* Painting::GetTools()
{
  return tools;
}

void Painting::SetPaintType(char* painttype_)
{
  if (painttype_ != nullptr)
    this->painttype = painttype_;
  else
    throw "Unable to set paint type!";
}

void Painting::SetDiagonalSize(int diagonalsize_)
{
  this->diagonalsize = diagonalsize_;
}

void Painting::SetTools(char* tools_)
{
  if (tools_ != nullptr)
    this->tools = tools_;
  else
    throw "Unable to set paint tools!";
}
