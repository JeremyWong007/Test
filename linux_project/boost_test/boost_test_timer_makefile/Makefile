INCLUDES+=/usr/local/include
INCLUDES_DIR=$(patsubst %,-I%,$(INCLUDES))
all:test
test:test.cpp
	g++ $(INCLUDES_DIR) -o test -lboost_date_time test.cpp

clean:
	rm test