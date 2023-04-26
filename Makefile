CXX = g++
CXXFLAGS_COMPILE =\
	-Wall\
	-std=c++11\
	-stdlib=libc++\
	-g\
	-I/Users/aaron/boost/\
	-I/opt/homebrew/opt/openssl@3/include

CXXFLAGS_FINAL =\
	-Wall\
	-std=c++11\
	-stdlib=libc++\
	-g\
	-lssl\
	-lcrypto\
	-I/Users/aaron/boost/\
	-I/opt/homebrew/opt/openssl@3/include\
	-L/opt/homebrew/opt/openssl@3/lib\

TARGET = python_cpp
SRCS = connection/connection.cpp\
	crawler/webcrawler.cpp\
	crawler/crawler_utils.cpp\
	crawler/crawlerfactory.cpp\
	run.cpp
	
# SRCS = connection_metadata.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS_FINAL) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS_COMPILE) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)