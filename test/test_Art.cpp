#include "TArt.h"
#include "TImage.h"
#include "TLiterature.h"
#include "TSound.h"
#include "TMusic.h"
#include "TPainting.h"
#include "TTheatre.h"

#include <gtest.h>
#include <string>


// Тест конструктора по умолчанию
TEST(TArtTest, DefaultConstructor) {
  TArt art;
  EXPECT_EQ("Unknown", art.GetName());
  EXPECT_EQ("No Author", art.GetAuthor());
  EXPECT_EQ(0, art.GetYear());
  EXPECT_EQ(0, art.GetMood());
  EXPECT_EQ("No Genre", art.GetGenre());
  EXPECT_FALSE(art.GetIsDigital());
}

// Тест параметризованного конструктора
TEST(TArtTest, ParameterizedConstructor) {
  TArt art("Mona Lisa", "Leonardo da Vinci", 1503, 75, "Portrait", false);
  EXPECT_EQ("Mona Lisa", art.GetName());
  EXPECT_EQ("Leonardo da Vinci", art.GetAuthor());
  EXPECT_EQ(1503, art.GetYear());
  EXPECT_EQ(75, art.GetMood());
  EXPECT_EQ("Portrait", art.GetGenre());
  EXPECT_FALSE(art.GetIsDigital());
}

// Тест конструктора с некорректным годом (должно быть исключение)
TEST(TArtTest, InvalidYearConstructor) {
  EXPECT_THROW(TArt("Art", "Author", 2026, 50, "Genre", false), const char*);  // Год больше 2025
  EXPECT_THROW(TArt("Art", "Author", -25001, 50, "Genre", false), const char*); // Год меньше -25000
}

// Тест метода GetMood с корректировкой значений
TEST(TArtTest, GetMoodBoundaries) {
  TArt art("Art", "Author", 2000, 120, "Genre", false);
  EXPECT_EQ(100, art.GetMood());  // mood > 100, должно вернуть 100

  TArt art2("Art", "Author", 2000, -10, "Genre", false);
  EXPECT_EQ(0, art2.GetMood());  // mood < 0, должно вернуть 0
}

// Тест метода SetName
TEST(TArtTest, SetName) {
  TArt art;
  art.SetName("The Scream");
  EXPECT_EQ("The Scream", art.GetName());
  EXPECT_THROW(art.SetName(""), const char*);  // Пустое имя, должно быть исключение
}

// Тест метода SetAuthor
TEST(TArtTest, SetAuthor) {
  TArt art;
  art.SetAuthor("Edvard Munch");
  EXPECT_EQ( "Edvard Munch", art.GetAuthor());
  EXPECT_THROW(art.SetAuthor(""), const char*);  // Пустое имя автора, должно быть исключение
}

// Тест метода SetYear
TEST(TArtTest, SetYear) {
  TArt art;
  art.SetYear(2000);
  EXPECT_EQ(2000, art.GetYear());
  EXPECT_THROW(art.SetYear(2026), const char*);  // Год больше 2025, должно быть исключение
}

// Тест метода SetGenre
TEST(TArtTest, SetGenre) {
  TArt art;
  art.SetGenre("Expressionism");
  EXPECT_EQ("Expressionism", art.GetGenre());
  EXPECT_THROW(art.SetGenre(""), const char*);  // Пустой жанр, должно быть исключение
}

// Тест конструктора по умолчанию
TEST(TImageTest, DefaultConstructor) {
  TImage image;
  EXPECT_EQ("Unknown", image.GetName());
  EXPECT_EQ("No Author", image.GetAuthor());
  EXPECT_EQ(0, image.GetYear());
  EXPECT_EQ(0, image.GetMood());
  EXPECT_EQ("No Genre", image.GetGenre());
  EXPECT_FALSE(image.GetIsDigital());
  EXPECT_EQ(0, image.GetWidth());
  EXPECT_EQ(0, image.GetHeight());
  EXPECT_FALSE(image.GetIsMono());
  EXPECT_FALSE(image.GetIsMoving());
}


// Тест метода GetWidth
TEST(TImageTest, GetWidth) {
  TImage image("Art", "Author", 2000, 50, "Genre", false, 100, 200, false, false);
  EXPECT_EQ(100, image.GetWidth());
}

// Тест метода GetHeight
TEST(TImageTest, GetHeight) {
  TImage image("Art", "Author", 2000, 50, "Genre", false, 100, 200, false, false);
  EXPECT_EQ(200, image.GetHeight());
}

// Тест метода GetIsMono
TEST(TImageTest, GetIsMono) {
  TImage image("Art", "Author", 2000, 50, "Genre", false, 100, 200, true, false);
  EXPECT_TRUE(image.GetIsMono());
}

// Тест метода GetIsMoving
TEST(TImageTest, GetIsMoving) {
  TImage image("Art", "Author", 2000, 50, "Genre", false, 100, 200, false, true);
  EXPECT_TRUE(image.GetIsMoving());
}

// Тест метода SetWidth
TEST(TImageTest, SetWidth) {
  TImage image;
  image.SetWidth(150);
  EXPECT_EQ(150, image.GetWidth());
  EXPECT_THROW(image.SetWidth(-50), const char*);  // Отрицательная ширина, должно быть исключение
}

// Тест метода SetHeight
TEST(TImageTest, SetHeight) {
  TImage image;
  image.SetHeight(300);
  EXPECT_EQ(300, image.GetHeight());
  EXPECT_THROW(image.SetHeight(-100), const char*);  // Отрицательная высота, должно быть исключение
}

// Тест метода SetIsMono
TEST(TImageTest, SetIsMono) {
  TImage image;
  image.SetIsMono(true);
  EXPECT_TRUE(image.GetIsMono());
  image.SetIsMono(false);
  EXPECT_FALSE(image.GetIsMono());
}

// Тест метода SetIsMoving
TEST(TImageTest, SetIsMoving) {
  TImage image;
  image.SetIsMoving(true);
  EXPECT_TRUE(image.GetIsMoving());
  image.SetIsMoving(false);
  EXPECT_FALSE(image.GetIsMoving());
}


// Тест конструктора для аналогового звука (каналы должны быть 1)
TEST(TSoundTest, AnalogSoundChannels) {
  TSound sound("Analog Sound", "Author", 2000, 50, "Genre", false, 3.0, 2, false);
  EXPECT_EQ(1, sound.GetChannels());  // Для аналогового звука каналы должны быть 1
}

// Тест конструктора с некорректной длительностью или каналами (должно быть исключение)
TEST(TSoundTest, InvalidDurationOrChannelsConstructor) {
  EXPECT_THROW(TSound("Sound", "Author", 2000, 50, "Genre", true, -1.0, 2, true), const char*);  // Отрицательная длительность
  EXPECT_THROW(TSound("Sound", "Author", 2000, 50, "Genre", true, 3.0, 0, true), const char*);  // Нулевые каналы
}


// Тест метода GetDuration
TEST(TSoundTest, GetDuration) {
  TSound sound("Sound", "Author", 2000, 50, "Genre", true, 2.5, 2, true);
  EXPECT_DOUBLE_EQ(2.5, sound.GetDuration());
}


// Тест метода GetChannels для аналогового звука
TEST(TSoundTest, GetChannelsAnalog) {
  TSound sound("Sound", "Author", 2000, 50, "Genre", false, 2.5, 5, true);
  EXPECT_EQ(1, sound.GetChannels());  // Для аналогового звука каналы должны быть 1
}

// Тест метода GetIsVoice
TEST(TSoundTest, GetIsVoice) {
  TSound sound("Sound", "Author", 2000, 50, "Genre", true, 2.5, 2, true);
  EXPECT_TRUE(sound.GetIsVoice());
  sound.SetIsVoice(false);
  EXPECT_FALSE(sound.GetIsVoice());
}

// Тест метода SetDuration
TEST(TSoundTest, SetDuration) {
  TSound sound;
  sound.SetDuration(4.0);
  EXPECT_DOUBLE_EQ(4.0, sound.GetDuration());
  EXPECT_THROW(sound.SetDuration(-1.0), const char*);  // Отрицательная длительность, должно быть исключение
}

// Тест метода SetChannels для аналогового звука
TEST(TSoundTest, SetChannelsAnalog) {
  TSound sound("Sound", "Author", 2000, 50, "Genre", false, 2.5, 2, true);
  sound.SetChannels(4);
  EXPECT_EQ(1, sound.GetChannels());  // Для аналогового звука каналы должны быть 1
}

// Тест метода SetChannels с некорректным значением (должно быть исключение)
TEST(TSoundTest, SetChannelsInvalid) {
  TSound sound;
  EXPECT_THROW(sound.SetChannels(0), const char*);  // Нулевые каналы, должно быть исключение
}

// Тест метода SetIsVoice
TEST(TSoundTest, SetIsVoice) {
  TSound sound;
  sound.SetIsVoice(true);
  EXPECT_TRUE(sound.GetIsVoice());
  sound.SetIsVoice(false);
  EXPECT_FALSE(sound.GetIsVoice());
}


TEST(TLiteratureTest, DefaultConstructor) {
  TLiterature literature;
  EXPECT_EQ("Unknown", literature.GetName());
  EXPECT_EQ("No Author", literature.GetAuthor());
  EXPECT_EQ(0, literature.GetYear());
  EXPECT_EQ(0, literature.GetMood());
  EXPECT_EQ("No Genre", literature.GetGenre());
  EXPECT_FALSE(literature.GetIsDigital());
  EXPECT_EQ(0, literature.GetWidth());
  EXPECT_EQ(0, literature.GetHeight());
  EXPECT_FALSE(literature.GetIsMono());
  EXPECT_FALSE(literature.GetIsMoving());
  EXPECT_EQ("Unknown Language", literature.GetLanguage());
  EXPECT_EQ(1, literature.GetParts());
  EXPECT_FALSE(literature.GetIsPoetry());
}


// Тест метода GetLanguage
TEST(TLiteratureTest, GetLanguage) {
  TLiterature literature("Book", "Author", 2000, 50, "Genre", false, 100, 200, false, false, "English", 1, false);
  EXPECT_EQ("English", literature.GetLanguage());
}

// Тест метода GetParts
TEST(TLiteratureTest, GetParts) {
  TLiterature literature("Book", "Author", 2000, 50, "Genre", false, 100, 200, false, false, "English", 5, false);
  EXPECT_EQ(5, literature.GetParts());
}

// Тест метода GetIsPoetry
TEST(TLiteratureTest, GetIsPoetry) {
  TLiterature literature("Book", "Author", 2000, 50, "Genre", false, 100, 200, false, false, "English", 1, true);
  EXPECT_TRUE(literature.GetIsPoetry());
  literature.SetIsPoetry(false);
  EXPECT_FALSE(literature.GetIsPoetry());
}


// Тест метода SetParts с корректным значением
TEST(TLiteratureTest, SetPartsValid) {
  TLiterature literature;
  literature.SetParts(10);
  EXPECT_EQ(10, literature.GetParts());
}

// Тест метода SetParts с некорректным значением (должно быть исключение)
TEST(TLiteratureTest, SetPartsInvalid) {
  TLiterature literature;
  EXPECT_THROW(literature.SetParts(0), const char*);  // Нулевое количество частей, должно быть исключение
  EXPECT_THROW(literature.SetParts(-5), const char*); // Отрицательное количество частей, должно быть исключение
}

// Тест метода SetIsPoetry
TEST(TLiteratureTest, SetIsPoetry) {
  TLiterature literature;
  literature.SetIsPoetry(true);
  EXPECT_TRUE(literature.GetIsPoetry());
  literature.SetIsPoetry(false);
  EXPECT_FALSE(literature.GetIsPoetry());
}


// Тест конструктора с некорректными значениями голосов или слушателей (должно быть исключение)
TEST(TMusicTest, InvalidVoicesOrListenersConstructor) {
  EXPECT_THROW(TMusic("Song", "Artist", 2000, 50, "Genre", true, 3.0, 2, true, 0, "Guitar", 1000), const char*);  // Нулевые голоса
  EXPECT_THROW(TMusic("Song", "Artist", 2000, 50, "Genre", true, 3.0, 2, true, 4, "Guitar", 0), const char*);    // Нулевые слушатели
  EXPECT_THROW(TMusic("Song", "Artist", 2000, 50, "Genre", true, 3.0, 2, true, -1, "Guitar", 1000), const char*); // Отрицательные голоса
  EXPECT_THROW(TMusic("Song", "Artist", 2000, 50, "Genre", true, 3.0, 2, true, 4, "Guitar", -1000), const char*);  // Отрицательные слушатели
}


// Тест метода GetVoices
TEST(TMusicTest, GetVoices) {
  TMusic music("Song", "Artist", 2000, 50, "Genre", true, 3.0, 2, true, 4, "Guitar", 1000);
  EXPECT_EQ(4, music.GetVoices());
}

// Тест метода GetInstruments
TEST(TMusicTest, GetInstruments) {
  TMusic music("Song", "Artist", 2000, 50, "Genre", true, 3.0, 2, true, 4, "Guitar, Piano", 1000);
  EXPECT_EQ("Guitar, Piano", music.GetInstruments());
}

// Тест метода GetListeners
TEST(TMusicTest, GetListeners) {
  TMusic music("Song", "Artist", 2000, 50, "Genre", true, 3.0, 2, true, 4, "Guitar", 1000000);
  EXPECT_EQ(1000000, music.GetListeners());
}

// Тест метода SetVoices с корректным значением
TEST(TMusicTest, SetVoicesValid) {
  TMusic music;
  music.SetVoices(6);
  EXPECT_EQ(6, music.GetVoices());
}

// Тест метода SetVoices с некорректным значением (должно быть исключение)
TEST(TMusicTest, SetVoicesInvalid) {
  TMusic music;
  EXPECT_THROW(music.SetVoices(0), const char*);  // Нулевые голоса, должно быть исключение
  EXPECT_THROW(music.SetVoices(-1), const char*); // Отрицательные голоса, должно быть исключение
}

// Тест метода SetInstruments с корректным значением
TEST(TMusicTest, SetInstrumentsValid) {
  TMusic music;
  music.SetInstruments("Violin, Cello");
  EXPECT_EQ("Violin, Cello", music.GetInstruments());
}

// Тест метода SetInstruments с некорректным значением (должно быть исключение)
TEST(TMusicTest, SetInstrumentsInvalid) {
  TMusic music;
  EXPECT_THROW(music.SetInstruments(""), const char*);  // Пустые инструменты, должно быть исключение
}

// Тест метода SetListeners с корректным значением
TEST(TMusicTest, SetListenersValid) {
  TMusic music;
  music.SetListeners(2000000);
  EXPECT_EQ(2000000, music.GetListeners());
}

// Тест метода SetListeners с некорректным значением (должно быть исключение)
TEST(TMusicTest, SetListenersInvalid) {
  TMusic music;
  EXPECT_THROW(music.SetListeners(0), const char*);  // Нулевые слушатели, должно быть исключение
  EXPECT_THROW(music.SetListeners(-1000), const char*); // Отрицательные слушатели, должно быть исключение
}

// Тест конструктора с некорректным размером диагонали (должно быть исключение)
TEST(TPaintingTest, InvalidDiagonalSizeConstructor) {
  EXPECT_THROW(TPainting("Painting", "Artist", 2000, 50, "Genre", false, 100, 200, false, false, "Oil", 0, "Brush"), const char*);  // Нулевой размер диагонали
  EXPECT_THROW(TPainting("Painting", "Artist", 2000, 50, "Genre", false, 100, 200, false, false, "Oil", -10, "Brush"), const char*); // Отрицательный размер диагонали
}


// Тест метода GetPaintType
TEST(TPaintingTest, GetPaintType) {
  TPainting painting("Painting", "Artist", 2000, 50, "Genre", false, 100, 200, false, false, "Watercolor", 50, "Brush");
  EXPECT_EQ("Watercolor", painting.GetPaintType());
}

// Тест метода GetDiagonalSize
TEST(TPaintingTest, GetDiagonalSize) {
  TPainting painting("Painting", "Artist", 2000, 50, "Genre", false, 100, 200, false, false, "Oil", 80, "Brush");
  EXPECT_EQ(80, painting.GetDiagonalSize());
}

// Тест метода GetTools
TEST(TPaintingTest, GetTools) {
  TPainting painting("Painting", "Artist", 2000, 50, "Genre", false, 100, 200, false, false, "Oil", 80, "Brush, Palette");
  EXPECT_EQ("Brush, Palette", painting.GetTools());
}


// Тест метода GetDirector
TEST(TTheatreTest, GetDirector) {
  TTheatre theatre("Play", "Author", 2000, 50, "Genre", false, 2.0, 2, true, "Director", "Actors", "Theatre");
  EXPECT_EQ("Director", theatre.GetDirector());
}

// Тест метода GetActors
TEST(TTheatreTest, GetActors) {
  TTheatre theatre("Play", "Author", 2000, 50, "Genre", false, 2.0, 2, true, "Director", "Actor1, Actor2", "Theatre");
  EXPECT_EQ("Actor1, Actor2", theatre.GetActors());
}

// Тест метода GetTheatre
TEST(TTheatreTest, GetTheatre) {
  TTheatre theatre("Play", "Author", 2000, 50, "Genre", false, 2.0, 2, true, "Director", "Actors", "Theatre");
  EXPECT_EQ("Theatre", theatre.GetTheatre());
}

// Тест метода SetDirector с корректным значением
TEST(TTheatreTest, SetDirectorValid) {
  TTheatre theatre;
  theatre.SetDirector("New Director");
  EXPECT_EQ("New Director", theatre.GetDirector());
}

// Тест метода SetDirector с некорректным значением (должно быть исключение)
TEST(TTheatreTest, SetDirectorInvalid) {
  TTheatre theatre;
  EXPECT_THROW(theatre.SetDirector(""), const char*);  // Пустой режиссер, должно быть исключение
}

// Тест метода SetActors с корректным значением
TEST(TTheatreTest, SetActorsValid) {
  TTheatre theatre;
  theatre.SetActors("New Actor1, New Actor2");
  EXPECT_EQ("New Actor1, New Actor2", theatre.GetActors());
}

// Тест метода SetActors с некорректным значением (должно быть исключение)
TEST(TTheatreTest, SetActorsInvalid) {
  TTheatre theatre;
  EXPECT_THROW(theatre.SetActors(""), const char*);  // Пустые актеры, должно быть исключение
}

// Тест метода SetTheatre с корректным значением
TEST(TTheatreTest, SetTheatreValid) {
  TTheatre theatre;
  theatre.SetTheatre("New Theatre");
  EXPECT_EQ("New Theatre", theatre.GetTheatre());
}

// Тест метода SetTheatre с некорректным значением (должно быть исключение)
TEST(TTheatreTest, SetTheatreInvalid) {
  TTheatre theatre;
  EXPECT_THROW(theatre.SetTheatre(""), const char*);  // Пустой театр, должно быть исключение
}