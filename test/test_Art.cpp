#include "Art.h"
#include "Image.h"
#include "Literature.h"
#include "Sound.h"
#include "Music.h"

#include <gtest.h>

TEST(Image, can_create_non_digital_image_without_resolution)
{
  ASSERT_NO_THROW(Image im("Aboba", "Amogus", 2000, 88, "Cool", false, nullptr, false, false));
}

TEST(Art, mood_limits_by_100)
{
  Art a("Lol", "Rizzler", 2014, 500, "Wow", true);

  EXPECT_EQ(100, a.GetMood());
}

TEST(Literature, throws_when_literature_change_parts_to_negative)
{
  Literature lt("Skibidi", "Ohio", 2017, 15, "Fanum tax", false, 0, false, false, "Bri'ish", 3, true);

  ASSERT_ANY_THROW(lt.SetParts(-228));
}

TEST(Sound, non_digital_sound_cant_have_more_than_1_channel)
{
  Sound snd("AA", "BB", 1234, 12, "CC", false, 15.0, 5, false);

  EXPECT_EQ(1, snd.GetChannels());
}


TEST(Music, can_copy_music)
{
  Music ms("Budil'nik", "Egor Kreed", 2015, 100, "Pop", true, 3.14, 2, true, 1, "nu tam norm krch", 1500000ll);

  ASSERT_NO_THROW(Music ms2(ms));
}
