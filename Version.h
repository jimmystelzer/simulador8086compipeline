#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "27";
	static const char MONTH[] = "05";
	static const char YEAR[] = "2009";
	static const double UBUNTU_VERSION_STYLE = 9.05;
	
	//Software Status
	static const char STATUS[] = "Release Candidate";
	static const char STATUS_SHORT[] = "rc";
	
	//Standard Version Type
	static const long MAJOR = 1;
	static const long MINOR = 0;
	static const long BUILD = 0;
	static const long REVISION = 5;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 0;
	#define RC_FILEVERSION 1,0,0,5
	#define RC_FILEVERSION_STRING "1, 0, 0, 5\0"
	static const char FULLVERSION_STRING[] = "1.0.0.5";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 2;
	

}
#endif //VERSION_h
