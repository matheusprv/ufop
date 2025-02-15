#include "ModelImpl.h"

// Construtores
ModelImpl :: ModelImpl(){
    name = "";
    systems.clear();
    flows.clear();    
}

ModelImpl :: ModelImpl(const string & name) : name(name){}

ModelImpl :: ModelImpl(ModelImpl & model){

    flows.clear();
    systems.clear();

    name = model.getName();
    flows.insert(flows.begin(), model.flows.begin(), model.flows.end());
    systems.insert(systems.begin(), model.systems.begin(), model.systems.end());
}

// Destrutor
ModelImpl :: ~ModelImpl(){}

// Getters e setters
string ModelImpl :: getName() const{
    return name;
}
void ModelImpl :: setName(const string & name){
    this->name = name;
}

// Informações dos containers
ModelImpl :: systemsIterator ModelImpl :: systemBegin(){
    return systems.begin();
}
ModelImpl :: systemsIterator ModelImpl :: systemEnd(){
    return systems.end();
}

ModelImpl :: flowsIterator ModelImpl :: flowsBegin(){
    return flows.begin();
}
ModelImpl :: flowsIterator ModelImpl :: flowsEnd(){
    return flows.end();
}

int ModelImpl :: flowsSize(){
    return flows.size();
}
int ModelImpl :: systemsSize(){
    return systems.size();
}


// Outros métodos
bool ModelImpl :: add(Flow * flow){
    size_t original_size = flows.size();
    flows.push_back(flow);
    return (flows.size() > original_size);
}
bool ModelImpl :: add(System * system){
    size_t original_size = systems.size();
    systems.push_back(system);
    return (systems.size() > original_size);
}

bool ModelImpl :: remove(System* system){
    for(systemsIterator it = systems.begin(); it < systems.end(); it++){
        if(*it == system){
            systems.erase(it);
            return true;
        }
    }
    return false;
}
bool ModelImpl :: remove(Flow* flow){
    for(flowsIterator it = flows.begin(); it < flows.end(); it++){
        if(*it == flow){
            flows.erase(it);
            return true;
        }
    }
    return false;
}

bool ModelImpl :: run(int initial_time, int final_time){

    // Verificando se os tempos são validos
    if(initial_time > final_time || initial_time < 0 || final_time < 0) return false;

    System *source, *target;
    int flows_size = flowsSize();

    vector<double> v;
    for(int i = 0; i < flows_size; i++) 
        v.push_back(0.0);
    
    // Executando o modelo
    flowsIterator flowIt;
    int time;
    for(time = initial_time; time < final_time; time++){
        
        flowIt = flowsBegin();

        for(int i = 0; i  < flows_size; i++){
            v[i] = (*flowIt)->executeEquation();
            flowIt++;
        }

        flowIt = flowsBegin();
        for(int i = 0; i < flows_size; i++){
            source = (*flowIt)->getSource();
            source->setValue(source->getValue() - v[i]);

            target = (*flowIt)->getTarget();
            target->setValue(target->getValue() + v[i]);

            flowIt++;
        }

    }

    return time == final_time;
}

void ModelImpl :: show(){
    systemsIterator it = systemBegin();

    while (it != systemEnd()){
        cout << *it;
    }
}

// Sobrecarga de operadores
ModelImpl& ModelImpl :: operator=(const ModelImpl& model){
    if(this == &model) return *this;

    systems.clear();
    flows.clear();

    name = model.getName();

    systems.insert(systems.begin(), model.systems.begin(), model.systems.end());
    flows.insert(flows.begin(), model.flows.begin(), model.flows.end());
    
    return *this;
}
