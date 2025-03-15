#pragma once
#include <iostream>
#include "TArt.h"

class TImage : public TArt
{
protected:
  int width; //there are no resolution if it's not digital
  int height;
  bool ismono;
  bool ismoving;
public:
  TImage(std::string name = "Unknown",
    std::string author = "No Author",
    int year = 0,
    int mood = 0,
    std::string genre = "No Genre",
    bool isdigital = false,
    int width = 0,
    int height = 0,
    bool ismono = false,
    bool ismoving = false);
  TImage(const TImage& p);
  ~TImage();

  int GetWidth();
  int GetHeight();
  bool GetIsMono();
  bool GetIsMoving();

  void SetWidth(int width_);
  void SetHeight(int height_);
  void SetIsMono(bool ismono_);
  void SetIsMoving(bool ismoving_);

  friend std::ostream& operator <<(std::ostream& o, TImage& b);
  friend std::istream& operator >>(std::istream& i, TImage& b);

  void WhoAmI() override
  {
    std::cout << "I am TImage!" << std::endl;
  }
};
std::ostream& operator <<(std::ostream& o, TImage& b);
std::istream& operator >>(std::istream& i, TImage& b);