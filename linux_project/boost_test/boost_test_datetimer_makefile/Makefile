INCLUDES+=/usr/local/include
INCLUDES_DIR=$(patsubst %,-I%,$(INCLUDES))
all:test
test:test.cpp
	g++ -o test -L/usr/local/lib -lboost_date_time test.cpp

clean:
	rm test