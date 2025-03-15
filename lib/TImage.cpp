#include <iostream>
#include "TImage.h"

TImage::TImage(std::string name_, std::string author_, int year_, int mood_, std::string genre_, 
  bool isdigital_, int width_, int height_, bool ismono_, bool ismoving_) : TArt::TArt()
{
  if (isdigital_ && ((width_ < 1) || (height_ < 1)))
    throw "Unable to create an TImage: It's digital it should have a resolution!!!";
  
  if (width_ < 0)
    this->width = -1*width_;
  else if (width_ > 0)
    this->width = width_;
  else
    this->width = width_;
  
  if (height_ < 0)
    this->height = -1*height_;
  else if (height_ > 0)
    this->height = height_;
  else
    this->height = height_;
  
  this->ismono = ismono_;
  this->ismoving = ismoving_;
}

TImage::TImage(const TImage& p) : TImage::TImage()
{
  this->width = p.width;
  this->height = p.height;
  this->ismono = p.ismono;
  this->ismoving = p.ismoving;
}

TImage::~TImage()
{}

int TImage::GetWidth()
{
  return width;
}
int TImage::GetHeight()
{
  return height;
}
bool TImage::GetIsMono()
{
  return ismono;
}
bool TImage::GetIsMoving()
{
  return ismoving;
}

void TImage::SetWidth(int width_)
{
  if (width_ > 0)
    this->width = width_;
  else
    throw "Unable to set width!";
}
void TImage::SetHeight(int height_)
{
  if (height_ > 0)
    this->height = height_;
  else
    throw "Unable to set height!";
}
void TImage::SetIsMono(bool ismono_)
{
  this->ismono = ismono_;
}

void TImage::SetIsMoving(bool ismoving_)
{
  this->ismoving = ismoving_;
}

std::ostream& operator<<(std::ostream& o, TImage& b)
{
  o << "Width:\t" << b.width << "\nHeight:\t" << b.height;
  o << "\nIsMono:\t" << b.ismono << "\nIsMoving:\t" << b.ismoving << std::endl;
  return o;
}
std::istream& operator>>(std::istream& i, TImage& b)
{
  if (b.isdigital)
  {
    std::cout << "Enter Width and Height of TImage:";
    i >> b.width;
    i >> b.height;
  }
  std::cout << "Enter IsMono of TImage (1 or 0):";
  i >> b.ismono;
  std::cout << "Enter IsMoving of TImage (1 or 0):";
  i >> b.ismoving;
  return i;
}