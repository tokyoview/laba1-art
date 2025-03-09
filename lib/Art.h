#pragma once
#include <iostream>

class Art
{
protected:
  char* name;
  char* author;
  int year; // negative years are b.c., positive years are a.c.
  int mood; // 0-100 value where 0 is sad, 100 is bright and happy
  char* genre;
  bool isdigital;
public:
  Art(char* name = "Unknown",
    char* author = "No Author",
    int year = 0,
    int mood = 0,
    char* genre = "No Genre",
    bool isdigital = false);
  Art(const Art& p);
  ~Art();

  char* GetName();
  char* GetAuthor();
  int GetYear();
  int GetMood();
  char* GetGenre();
  bool GetIsDigital();

  void SetName(char* name_);
  void SetAuthor( char* author_);
  void SetYear(int year_);
  void SetMood(int mood_);
  void SetGenre(char* genre_);
  void SetIsDigital(bool isdigital_);

  friend std::ostream& operator <<(std::ostream& o, Art& b);
  friend std::istream& operator >>(std::istream& i, Art& b);
};
std::ostream& operator <<(std::ostream& o, Art& b);
std::istream& operator >>(std::istream& i, Art& b);