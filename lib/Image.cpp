#include <iostream>
#include "Image.h"

Image::Image(char* name, char* author, int year, int mood, char* genre, 
  bool isdigital, int* resolution, bool ismono, bool ismoving) : Art::Art()
{
  if (isdigital)
    resolution = new int(2);
  if (isdigital && (resolution == nullptr))
    throw "Unable to create an Image: It's digital it should have a resolution!!!";
}

Image::Image(const Image& p) : Image::Image()
{
  if (p.resolution != nullptr)
  {
    this->resolution[0] = p.resolution[0];
    this->resolution[1] = p.resolution[1];
    delete[] p.resolution;
  }
}

Image::~Image()
{
  if (resolution != nullptr)
    delete[] resolution;
}

int* Image::GetResolution()
{
  return resolution;
}
bool Image::GetIsMono()
{
  return ismono;
}
bool Image::GetIsMoving()
{
  return ismoving;
}

void Image::SetResolution(int* resolution_)
{
  if (isdigital && (resolution_ != nullptr))
  {
    if (this->resolution != nullptr)
      delete[] resolution;
    this->resolution[0] = resolution_[0];
    this->resolution[1] = resolution_[1];
    delete[] resolution_;
  }
  else
    throw "Unable to set resolution!";
}

void Image::SetIsMono(bool ismono_)
{
  this->ismono = ismono_;
}

void Image::SetIsMoving(bool ismoving_)
{
  this->ismoving = ismoving_;
}

std::ostream& operator<<(std::ostream& o, Image& b)
{
  o << "Resolution:\t" << b.resolution[0] << "\t" << b.resolution[1];
  o << "\nIsMono:\t" << b.ismono << "\nIsMoving:\t" << b.ismoving << std::endl;
  return o;
}
std::istream& operator>>(std::istream& i, Image& b)
{
  std::cout << "Enter Resolution of Image:";
  i >> b.resolution[0];
  i >> b.resolution[1];
  std::cout << "Enter IsMono of Image (1 or 0):";
  i >> b.ismono;
  std::cout << "Enter IsMoving of Image (1 or 0):";
  i >> b.ismoving;
  return i;
}