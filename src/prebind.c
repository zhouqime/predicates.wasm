#include <emscripten.h>
#include "predicates.h"

double 
EMSCRIPTEN_KEEPALIVE
orient2dex(double pax,double pay,double pbx,double pby,double pcx,double pcy){
    double pa[] = {pax,pay};
    double pb[] = {pbx,pby};
    double pc[] = {pcx,pcy};
    return orient2d(pa,pb,pc);
}

double
EMSCRIPTEN_KEEPALIVE
incirclex(double pax,double pay,double pbx,double pby,double pcx,double pcy,double pdx,double pdy){
    double pa[] = {pax,pay};
    double pb[] = {pbx,pby};
    double pc[] = {pcx,pcy};
    double pd[] = {pdx,pdy};
    return incircle(pa,pb,pc,pd);
}

int main(){
    EM_ASM(
        window.orient2d = _orient2dex;
        window.incircle = _incirclex;
    );
    return 0;
}