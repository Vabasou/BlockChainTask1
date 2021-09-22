run:
	g++ -o main main.cpp hash.cpp test.cpp sha1.cpp md5.cpp sha256.cpp
clear:
	del *.o *.exe hashedPairs.txt