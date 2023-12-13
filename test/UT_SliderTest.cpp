#ifdef ENDOCAM_UT
#include "devlabs_test.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <thread>
#include "SystemSettings.h"
#include "Results.h"
#include "I2CCom.h"
#include "Utility.h"
#include "Logger.h"
#include <unistd.h>

using namespace std;

devLABS_TEST_HEADER(SliderTest);

namespace tut {
struct
SliderTest{
};

template<>
template<>
void testobject::test<1>() {
	SystemSettings* sysStg = &SystemSettings::getInstance();
	uint16_t actual= sysStg->parse2I2C(PIXEL_BAL, 0,
			0, true);
	ensure_equals("Failed",actual, 0xbf81);
}

template<>
template<>
void testobject::test<2>() {
	SystemSettings* sysStg = &SystemSettings::getInstance();
	uint16_t actual= sysStg->parse2I2C(PIXEL_BAL, 0,
			63, true);
	ensure_equals("Failed",actual, 0x0040);
}

template<>
template<>
void testobject::test<3>() {
	SystemSettings* sysStg = &SystemSettings::getInstance();
	uint16_t actual= sysStg->parse2I2C(PIXEL_BAL, 0,
			40, true);
	ensure_equals("Failed",actual, 0x9781);
}
template<>
template<>
void testobject::test<4>() {
	SystemSettings* sysStg = &SystemSettings::getInstance();
	uint16_t actual= sysStg->parse2I2C(ROI, 128,
			0, true);
	ensure_equals("Failed",actual, 0x0080);
}
template<>
template<>
void testobject::test<5>() {
	SystemSettings* sysStg = &SystemSettings::getInstance();
	uint16_t actual= sysStg->parse2I2C(ROI, 64,
			105, true);
	ensure_equals("Failed",actual, 0x6940);
}




template<>
template<>
void testobject::test<6>() {
	SystemSettings* sysStg = &SystemSettings::getInstance();
	string actual= sysStg->getVersion(0x0808);
	ensure_equals("Failed",actual, "8.8");
}

template<>
template<>
void testobject::test<7>() {
	SystemSettings* sysStg = &SystemSettings::getInstance();
	string actual= sysStg->getVersion(0x1A10);
	ensure_equals("Failed",actual, "26.16");
}

}
#endif //ENDOCAM_UT

