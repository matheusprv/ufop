#ifndef FUNCIONAL_TESTS_H
#define FUNCIONAL_TESTS_H

#include <assert.h>
#include <math.h>
#include <iostream>
#include <string>
using namespace std;

#include "../../src/Flows/FlowComplexo.h"
#include "../../src/Flows/FlowLogistico.h"
#include "../../src/Flows/FlowExponencial.h"

#include "../../src/biblioteca/Model.h"

void exponentialFuncionalTest();
void logisticalFuncionalTest();
void complexFuncionalTest();

#endif