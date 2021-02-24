#INCLUDES+=/usr/local/include
#INCLUDES_DIR=$(patsubst %,-I%,$(INCLUDES))
all:test
test:main.cpp
	g++ -o test main.cpp -L. -lapi

clean:
	rm test