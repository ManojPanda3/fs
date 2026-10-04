all:
	cmake -B build -S . && cmake --build build

clean:
	rm -rf build

.PHONY: all clean