
#ifdef ENDOCAM_UT
#include "devlabs_test.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>
extern "C"{
#include "fatattr/fatattr.h"
}
/*#include "fatattr/fatattr.h"*/

using namespace std;

devLABS_TEST_HEADER(HideFileTest);

namespace tut {
struct
HideFileTest{
};
template<>
template<>
void testobject::test<1>() {
	hideFile("/media/developer/BC57-F162/it.txt");
	hideFile("/media/developer/BC57-F162/itsme");
	hideFile("/media/developer/BC57-F162/itsme1");
	
}

}
#endif //ENDOCAM_UT

