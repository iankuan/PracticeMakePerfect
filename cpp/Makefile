EXECUTE = constexpr explicit

all: ${EXECUTE}

%: %.cpp
	g++ -std=c++11 -O0 -o $@ $^ -Wall

.PHONY: clean all
clean:
	rm -f ${EXECUTE}
