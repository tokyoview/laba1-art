#pragma once
#include <iostream>
#include "TImage.h"

class TPainting : public TImage
{
protected:
  std::string painttype;
  int diagonalsize;
  std::string tools;
public:
  TPainting(std::string name = "Unknown",
    std::string author = "No Author",
    int year = 0,
    int mood = 0,
    std::string genre = "No Genre",
    bool isdigital = false,
    int width = 0,
    int height = 0,
    bool ismono = false,
    bool ismoving = false,
    std::string painttype = "No Data",
    int diagonalsize = 0,
    std::string tools = nullptr);
  TPainting(const TPainting& p);
  ~TPainting();

  std::string GetPaintType();
  int GetDiagonalSize();
  std::string GetTools();

  void SetPaintType(std::string painttype_);
  void SetDiagonalSize(int diagonalsize_);
  void SetTools(std::string tools_);

  friend std::ostream& operator <<(std::ostream& o, TPainting& b);
  friend std::istream& operator >>(std::istream& i, TPainting& b);
};
std::ostream& operator <<(std::ostream& o, TPainting& b);
std::istream& operator >>(std::istream& i, TPainting& b);