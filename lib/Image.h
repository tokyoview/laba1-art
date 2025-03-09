#pragma once
#include <iostream>
#include "Art.h"

class Image : public Art
{
protected:
  int resolution[2]; //there are no resolution if it's not digital
  bool ismono;
  bool ismoving;
public:
  Image(char* name = "Unknown",
    char* author = "No Author",
    int year = 0,
    int mood = 0,
    char* genre = "No Genre",
    bool isdigital = false,
    int* resolution = nullptr,
    bool ismono = false,
    bool ismoving = false);
  Image(const Image& p);
  ~Image();

  int* GetResolution();
  bool GetIsMono();
  bool GetIsMoving();

  void SetResolution(int* resolution_);
  void SetIsMono(bool ismono_);
  void SetIsMoving(bool ismoving_);

  friend std::ostream& operator <<(std::ostream& o, Image& b);
  friend std::istream& operator >>(std::istream& i, Image& b);
};
std::ostream& operator <<(std::ostream& o, Image& b);
std::istream& operator >>(std::istream& i, Image& b);