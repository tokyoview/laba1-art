file(GLOB hdrs "*.h*") #Добавляем в переменную hdrs все файлы с расширением .h
file(GLOB srcs "*.cpp")#Добавляем в переменную srcs все файлы с расширением .cpp

add_library(${library} STATIC ${srcs} ${hdrs}) #Создаем статическую библиотеку