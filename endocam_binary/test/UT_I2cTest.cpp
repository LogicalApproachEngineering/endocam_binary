#ifdef ENDOCAM_UT

#include "devlabs_test.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include "SystemSettings.h"
#include "Results.h"
#include "I2CCom.h"
#include "Utility.h"
#include <unistd.h>

using namespace std;

devLABS_TEST_HEADER(SettingsTest);

namespace tut {
struct SettingsTest{
	SettingsTest(){
		Utility::exec("rm -rf ./test/tmp");	
	}

};

template<>
template<>
void testobject::test<1>() {
//
	SystemSettings* sysStg = &SystemSettings::getInstance();
	std::map<I2C_SETTINGS, uint16_t> config = DEFAULTS::I2CValue();
	sysStg->applyPreset(config);
	
	std::map<I2C_SETTINGS, uint16_t> m = sysStg->ReadFromI2C();
	std::map<I2C_SETTINGS, uint16_t> :: iterator itr;
    for (itr = m.begin(); itr != m.end(); ++itr)
    {
		printf("%s -> %02x <-> %02x\n",ENUM::STR(itr->first).c_str(),itr->second, config[itr->first]);
		ensure_equals(ENUM::STR(itr->first)+" : Should be ZERO", itr->second, config[itr->first]);
    }
}

}
#endif //ENDOCAM_UT
