BASEDIR =  ~/code/password-auth/src

CXX=g++
CXXFLAGS= -O -I./ < $(HEADER)

SRC = driver.cpp md5.cpp pw_man.cpp
HEADER = md5.h pw_man.h
OBJ = $(SRC:%.cpp=%.o)

build: 
	$(CXX) -o auth $(SRC)
debug:
	$(CXX) -o auth -g $(SRC)

depend:
	makedepend $(CXXFLAGS) $(SRC)
# DO NOT DELETE

driver.o: md5.h pw_man.h
md5.o: md5.h
pw_man.o: pw_man.h md5.h
