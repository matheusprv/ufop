#include "FlowLogistico.h"

FlowLogistico :: FlowLogistico() : FlowImpl(){}

FlowLogistico :: FlowLogistico(const string & name, System * source, System * target) : FlowImpl (name, source, target) {}

FlowLogistico :: FlowLogistico(const string& name) : FlowImpl(name){}

FlowLogistico :: FlowLogistico(System* source, System* target) : FlowImpl (source, target) {}

FlowLogistico :: FlowLogistico(Flow& flow) : FlowImpl(flow){}


double FlowLogistico :: executeEquation(){
    double p2 = getTarget()->getValue();
    return 0.01 * p2 * (1 - p2 / 70);
}