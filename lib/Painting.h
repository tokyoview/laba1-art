#pragma once
#include <iostream>
#include "Image.h"

class Painting : public Image
{
protected:
  char* painttype;
  int diagonalsize;
  char* tools;
public:
  Painting(char* name = "Unknown",
    char* author = "No Author",
    int year = 0,
    int mood = 0,
    char* genre = "No Genre",
    bool isdigital = false,
    int resolution[2] = nullptr,
    bool ismono = false,
    bool ismoving = false,
    char* painttype = "No Data",
    int diagonalsize = 0,
    char* tools = nullptr);
  Painting(const Painting& p);
  ~Painting();

  char* GetPaintType();
  int GetDiagonalSize();
  char* GetTools();

  void SetPaintType(char* painttype_);
  void SetDiagonalSize(int diagonalsize_);
  void SetTools(char* tools_);

  friend std::ostream& operator <<(std::ostream& o, Painting& b);
  friend std::istream& operator >>(std::istream& i, Painting& b);
};
std::ostream& operator <<(std::ostream& o, Painting& b);
std::istream& operator >>(std::istream& i, Painting& b);