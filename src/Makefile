BASEDIR =  ~/code/password-auth/src

CXX=g++
CXXFLAGS= -Wall

SRC = driver.cpp md5.cpp pw_man.cpp rtable.cpp
HEADER = md5.h pw_man.h rtable.h
OBJ = driver.o md5.o pw_man.o rtable.o

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<
auth: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)
debug:$(OBJ)
	$(CXX) $(CXXFLAGS) -g -o $@ $(OBJ)
clean:
	rm -f *.o

depend:
	makedepend $(CXXFLAGS) $(SRC)
# DO NOT DELETE

driver.o: md5.h pw_man.h
md5.o: md5.h
pw_man.o: pw_man.h md5.h
rtable.o: rtable.h md5.h
