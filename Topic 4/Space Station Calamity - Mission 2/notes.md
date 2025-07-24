# Notes for Project

## How to store wormhole and radiation data
1. Use 2 arrays
```c++
int wormholeLoc[]{1,3,7};
bool radiated[]{true,false,true};
```

2. Combine it into one array
```c++
int roomDat[]{1,3,7};
// to set it
roomDat[0] |= 0x80000000; // set radiated
// to get it
if ((roomDat |= '') > 0) // if true, then radiated
```

## Breadcrumbs
```c++
"(playerpos*)(wormhole W||' ')(radiated R||' ')"
```

## Enums
Types of stuff
1. Modules
2. Wormhole
3. Radiation
```c++
enum Artifact
{
    wormhole = 1;
    radiation = 2;
    memmodule = 4;
};
```