CXX = g++
# -MMD manually looks at #include statements and generates dependency files
# based on the included header files
CXXFLAGS = -Wall -g -MMD
TARGET = chess

# source files
SRCS = ChessMain.cpp ChessGame.cpp Position.cpp Piece.cpp Pawn.cpp \
       Rook.cpp Knight.cpp Bishop.cpp Queen.cpp King.cpp

# generating object file names from source files (.cpp -> .o)
OBJS = $(SRCS:.cpp=.o)

# $@ - target name
# $^ - all prerequisites
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# compiling source files to object files
# $< - first prerequisite (source file)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# automatically imports the dependencies (the included header files)
-include $(OBJS:.o=.d)

clean:
	rm -f *.o *.d chess

.PHONY: clean