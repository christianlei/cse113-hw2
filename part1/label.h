#pragma once

using namespace std;

class label {
    public:
    label(){

    };
    label operator=(int value){
        this->value = value;
    }
    bool operator<(const label& l){
        return this->value < l.value;
    }
    bool operator==(const label& l){
        return this->value == l.value;
    }

    private:
    int value;

};