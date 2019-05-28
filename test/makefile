CC	= clang++

CFLAGS	= -O3 -Wno-deprecated -DNDEBUG  -pthread -g

SRCS	= testReader.cpp
#testReader.cpp

OBJS = $(SRCS:.cpp=.o)

INCLUDES = -I../../include/ \
		   -I../../include/def \
		   -I../../include/lef  \

LIBDIR = -L../../lib \
		 -L../../lib/def \
		 -L../../lib/lef \

LIBS = -ldef -llef

EXE	= test 

.SUFFIXES: .cc .cpp .o .x

.FAKE_ALL: all

all: test rw

rw : lefrw.cpp
	clang++ $(CFLAGS) $(INCLUDES)  lefrw.cpp -c lefrw.o 
	clang++ $(CFLAGS)  $(LIBDIR) lefrw.o -o rw $(LIBS)

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) $(LIBDIR) $(OBJS) -o $@ $(LIBS)

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<

.cc.o:
	$(CC) $(OFLAGS) -c $<

clean:
	rm -f $(OBJS) *~ $(EXE) core

copy:
	cp ../br_ispd07_64bit/*.cpp .
	cp ../br_ispd07_64bit/*.h .

dmp2res:
	$(CC) -O3 -o dmp2res.x dmp2res.cpp

res2dmp:
	$(CC) -O3 -o res2dmp.x res2dmp.cpp

