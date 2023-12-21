using namespace std;

map<string, float> planetSize{
    {"sun"      ,1391400/10000},
    {"jupiter"  ,142984/10000},
    {"saturne"  ,120536/10000},
    {"uranus"   ,51118/1000},
    {"neptune"  ,49528/1000},
    {"earth"    ,12756/1000},
    {"venus"    ,12104/1000},
    {"mars"     ,6792/1000},
    {"mercure"  ,487/100}
};

map<string, int> planetDistance{
    {"neptune",   4495100000/500000},
    {"uranus",    2872500000/500000},
    {"saturne",   1433500000/500000},
    {"jupiter",   778600000/500000},
    {"mars",      227900000/500000},
    {"earth",     149600000/500000},
    {"venus",     108200000/500000},
    {"mercure",   57900000/500000}
};

map<string, int> orbitDistance{
{"neptune",170},
{"uranus",225},
{"saturne",300},
{"jupiter",400},
{"mars",500},
{"earth",600},
{"venus",700},
{"mercure",900},
};
