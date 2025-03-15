#include <iostream>
#include "TArt.h"
#include "TImage.h"
#include "TSound.h"
#include "TMusic.h"
#include "TTheatre.h"
#include "TPainting.h"
#include "TLiterature.h"
#include <vector>

int main()
{
  TArt a("A", "B", 12, 12, "C", true);
  std::cout << a << std::endl;

  TArt aboba("Aboba", "Bebra", 2012, 52, "Peepeepoopoo", true);
  TImage picture("Imagine", "Skibidi", 1984, 15, "Hehe", true, 15, 15, false, false);
  //TMusic zaza("God damn", "Egor Kreed", 123, 88, "Kruto", true, 3.14, 5, true, 4, "Guitar", 150000ll);
  TSound bobo;

  std::vector<TArt*> arts;
  arts.push_back(&aboba);
  arts.push_back(&picture);
  arts.push_back(&bobo);

  for (const auto& art : arts) {
    art->WhoAmI();
  }

  return 0;
}