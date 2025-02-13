#ifndef FLOWLOGISTICO_H
#define FLOWLOGISTICO_H

#include "../../../src/Flow.h"

/**
* @brief   Definition of class FlowLogistico, which extends the class Flow and implements the executeEquation
*/
class FlowLogistico : public Flow{
public:
    /**
     * @brief   Constructor for the FlowLogistico class with parameters.
     * @param   name Name of the flow.
     * @param   source Pointer to the source system.
     * @param   target Pointer to the target system.
    */
    FlowLogistico(const string & name, System * source, System * target);

    /**
     * @brief   Execute the equation of the flow
     * @return  double value of the result of the equation
    */
    virtual double executeEquation();
};

#endif