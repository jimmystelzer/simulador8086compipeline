#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "29";
	static const char MONTH[] = "04";
	static const char YEAR[] = "2009";
	static const double UBUNTU_VERSION_STYLE = 9.04;
	
	//Software Status
	static const char STATUS[] = "Alpha";
	static const char STATUS_SHORT[] = "a";
	
	//Standard Version Type
	static const long MAJOR = 0;
	static const long MINOR = 1;
	static const long BUILD = 2;
	static const long REVISION = 5;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 104;
	#define RC_FILEVERSION 0,1,2,5
	#define RC_FILEVERSION_STRING "0, 1, 2, 5\0"
	static const char FULLVERSION_STRING[] = "0.1.2.5";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 2;
	

}
#endif //VERSION_h
