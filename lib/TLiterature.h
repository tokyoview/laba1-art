#pragma once
#include <iostream>
#include "TImage.h"

class TLiterature : public TImage
{
protected:
  std::string language;
  int parts; // number of books, parts, e.t.c.
  bool ispoetry;
public:
  TLiterature(std::string name = "Unknown",
    std::string author = "No Author",
    int year = 0,
    int mood = 0,
    std::string genre = "No Genre",
    bool isdigital = false,
    int width = 0,
    int height = 0,
    bool ismono = false,
    bool ismoving = false,
    std::string language = "Unknown Language",
    int parts = 1,
    bool ispoetry = false);
  TLiterature(const TLiterature& p);
  ~TLiterature();

  std::string GetLanguage();
  int GetParts();
  bool GetIsPoetry();

  void SetLanguage(std::string language_);
  void SetParts(int parts_);
  void SetIsPoetry(bool ispoetry_);

  friend std::ostream& operator <<(std::ostream& o, TLiterature& b);
  friend std::istream& operator >>(std::istream& i, TLiterature& b);
};
std::ostream& operator <<(std::ostream& o, TLiterature& b);
std::istream& operator >>(std::istream& i, TLiterature& b);
