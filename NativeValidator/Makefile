all: spawner.cpp validator.cpp
	wget -nc https://raw.githubusercontent.com/nlohmann/json/3113a52a7d148d7ad9567cf9d67fa67960beb3f1/src/json.hpp
	g++ -c spawner.cpp -std=c++11 && g++ validator.cpp -std=c++11 spawner.o -lpthread -o validator
clean:
	rm -f validator json.hpp spawner.o
