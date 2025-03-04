CC = g++
CFLAGS = -Wall -Wextra -O2
TARGET = classifier

build: $(TARGET)

$(TARGET): classifier.cpp
	$(CC) $(CFLAGS) -o $(TARGET) classifier.cpp

run:
	./$(TARGET)

clean:
	rm -f $(TARGET)