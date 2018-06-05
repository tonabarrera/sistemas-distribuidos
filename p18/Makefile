prueba_display_ascii:  prueba_display_ascii.o gfxModified.o
	g++ -std=c++11 prueba_display_ascii.o gfxModified.o -o prueba_display_ascii -lX11
prueba_display_ascii.o: prueba_display_ascii.cpp gfxModified.o
	g++ -Wall -std=c++11 prueba_display_ascii.cpp -c
gfxModified.o: gfxModified.c gfxModified.h
	gcc gfxModified.c -c