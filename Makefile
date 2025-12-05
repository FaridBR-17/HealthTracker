# Makefile para HealthTracker
# Autor: FaridBR-17

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
TARGET = healthtracker
SOURCES = src/main.cpp

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

run: $(TARGET)
	./$(TARGET)

clean:
	run -f $(TARGET)

help:
	@echo "Comandos:"
	@echo "  make       - Compilar"
	@echo "  make run   - Compilar y ejecutar"
	@echo "  make clean - Limpiar"
	@echo "  make help  - Mostrar ayuda"

.PHONY: all run clean help
