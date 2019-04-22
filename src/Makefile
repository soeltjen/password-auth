BASEDIR =  ~/code/password-auth/src

CXX=g++
CXXFLAGS= -Wall

SRC = driver.cpp md5.cpp pw_man.cpp
HEADER = md5.h pw_man.h
OBJ = $(SRC)

%.o: %.cpp $(HEADER)
	$(CXX) $(CXXFLAGS) -c -o $@ $<
auth: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^
debug:
	$(CXX) -o auth -g $(SRC)

depend:
	makedepend $(CXXFLAGS) $(SRC)
# DO NOT DELETE

driver.o: md5.h pw_man.h
md5.o: md5.h
pw_man.o: pw_man.h md5.h
