#pragma once
#include <iostream>

class TArt
{
protected:
  std::string name;
  std::string author;
  int year; // negative years are b.c., positive years are a.c.
  int mood; // 0-100 value where 0 is sad, 100 is bright and happy
  std::string genre;
  bool isdigital;
public:
  TArt(std::string name = "Unknown",
    std::string author = "No Author",
    int year = 0,
    int mood = 0,
    std::string genre = "No Genre",
    bool isdigital = false);
  TArt(const TArt& p);
  ~TArt();

  std::string GetName();
  std::string GetAuthor();
  int GetYear();
  int GetMood();
  std::string GetGenre();
  bool GetIsDigital();

  void SetName(std::string name_);
  void SetAuthor( std::string author_);
  void SetYear(int year_);
  void SetMood(int mood_);
  void SetGenre(std::string genre_);
  void SetIsDigital(bool isdigital_);

  friend std::ostream& operator <<(std::ostream& o, TArt& b);
  friend std::istream& operator >>(std::istream& i, TArt& b);

  virtual void WhoAmI();
};
std::ostream& operator <<(std::ostream& o, TArt& b);
std::istream& operator >>(std::istream& i, TArt& b);