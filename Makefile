CXX = g++
# -MMD manually looks at #include statements and generates dependency files
# based on the included header files
CXXFLAGS = -Wall -g -MMD

# common source files (no main())
COMMON_SRCS = ChessGame.cpp Position.cpp Piece.cpp \
Pawn.cpp Rook.cpp Knight.cpp Bishop.cpp Queen.cpp King.cpp

# generating object file names from source files (.cpp -> .o)
COMMON_OBJS = $(COMMON_SRCS:.cpp=.o)

# target-specific object lists
CHESS_OBJS = ChessMain.o $(COMMON_OBJS)
TEST_OBJS = ChessTest.o $(COMMON_OBJS)

# $@ - target name
# $^ - all prerequisites
# chess is the default target so listed before test.
chess: $(CHESS_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

test: $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# compiling source files to object files
# $< - first prerequisite (source file)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# automatically imports the dependencies (the included header files)
# creates .d dependency files from the object file names
-include $(COMMON_OBJS:.o=.d) ChessMain.d ChessTest.d

clean:
	rm -f *.o *.d chess test

.PHONY: clean