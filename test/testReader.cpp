//#include "LEFDEFReader.h"
#include <iostream>
#include <string>
#include <assert.h>
#include <lefrReader.hpp>

using namespace std;
int test(lefrCallbackType_e type, lefiMacro *pModel, lefiUserData pData) {
    auto & model = *pModel;
    auto & data = *(int *)pData;
    lefiPin tpin;
    int numProps = model.numProperties();
    //std::cout << numProps << std::endl;
    std ::cout<<"Call test"<< std::endl;
    std::cout << "type" << type << std::endl
        <<model.name()<<std::endl
        <<model.macroClass() << std::endl
        <<model.clockType() << std::endl
        <<model.foreignName() << std::endl
        <<model.generator() << std::endl
        <<model.hasSize() << std::endl;
    int i, j =numProps;
    if( numProps == 0)return 0;
    for (i = 0;i < numProps;i++) {
        assert(i < 1);
        std::cout << "[Property Name]" << (model.propName(i)) << std::endl
                  << "[Property Num]" << model.propNum(i) << std::endl
                  << "[Property Type]" << model.propType(i) << std::endl;
    }
    return 0;
}
int PinCBK (lefrCallbackType_e type, 
                                 lefiPin* l, 
                                 lefiUserData data);


int PinCBK(lefrCallbackType_e type, lefiPin *l, void *data) {
    std::cout << "Call Pin\n";
    return 0;
}

int main(){
    const char *Filename = "input1.lef";
    std::cout << "Input file:" << Filename << std::endl;
    FILE *fin = fopen(Filename, "r");
    int testdata;
    lefrSetMacroCbk(test);
    lefrSetPinCbk(PinCBK);
    lefrRead(fin, Filename, &testdata);
    fclose(fin);
}
