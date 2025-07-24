#ifndef DICE_ROLL_SIM_H // name of file in uppercase w/o dot
#define DICE_ROLL_SIM_H

void runSim();
void initializeExpected();
void runExperiment();
void printReport();
size_t randRange(size_t, size_t);
void printHeader();
void printTable();
double roundPrecision(double, size_t);

#endif /*DICE_ROLL_SIM_H*/