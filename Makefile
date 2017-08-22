


all:
	g++ -L/usr/local/lib -lfltk -lXext -lX11 -lm  "fldata.cxx"  -o  fldata 


