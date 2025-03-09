#pragma once
#include <iostream>
#include "Image.h"

class Literature : public Image
{
protected:
  char* language;
  unsigned int parts; // number of books, parts, e.t.c.
  bool ispoetry;
public:
  Literature(char* name = "Unknown",
    char* author = "No Author",
    int year = 0,
    int mood = 0,
    char* genre = "No Genre",
    bool isdigital = false,
    int* resolution = nullptr,
    bool ismono = false,
    bool ismoving = false,
    char* language = "Unknown Language",
    unsigned int parts = 1,
    bool ispoetry = false);
  Literature(const Literature& p);
  ~Literature();

  char* GetLanguage();
  unsigned int GetParts();
  bool GetIsPoetry();

  void SetLanguage(char* language_);
  void SetParts(unsigned int parts_);
  void SetIsPoetry(bool ispoetry_);

  friend std::ostream& operator <<(std::ostream& o, Literature& b);
  friend std::istream& operator >>(std::istream& i, Literature& b);
};
std::ostream& operator <<(std::ostream& o, Literature& b);
std::istream& operator >>(std::istream& i, Literature& b);
