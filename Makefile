CXX=g++
CXXFLAGS += -g -Wall -Wextra -pthread
CPPFLAGS += -isystem src -std=c++14

MKDIR_P = mkdir -p
OBJ_DIR = obj

OBJS = obj/main.o obj/BoundedBuffer.o obj/ProducerConsumer.o

all: prodcon queue_tests submission

prodcon : $(OBJS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $^

submission:
	zip -r queue-submission.zip src

${OBJ_DIR}:
	${MKDIR_P} ${OBJ_DIR}

obj/%.o: src/%.cpp ${OBJ_DIR}
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

obj/queue_tests.o: test/queue_tests.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

queue_tests: obj/BoundedBuffer.o obj/ProducerConsumer.o obj/queue_tests.o /usr/lib/libgtest.a /usr/lib/libgtest_main.a
		$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ -o $@

clean:
	rm -f prodcon queue_tests output.txt
	rm -f *~ *.zip
	rm -rf obj
