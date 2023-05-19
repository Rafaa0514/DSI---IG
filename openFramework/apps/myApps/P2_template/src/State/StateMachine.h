
#ifndef StateMachine_h
#define StateMachine_h

#include "State.h"
#include <stack>

class StateMachine{
  
    State *current;
    stack<State*> states;

public:
    StateMachine() : current (nullptr) { }

    StateMachine(State* initial) {
        states.push(initial);
        current = states.top();
    }

    virtual ~StateMachine() {
        clearStates();
    }

    void clearStates() {
        State* aux = nullptr;
        int num = states.size();
        for (int i = 0; i < num; i++) {
            aux = states.top();
            delete aux;
            states.pop();
        }
    }

    void setState(State *s){
        clearStates();
        states.push(s);
        current = s;
    }

    void pushState(State* s) {
        states.push(s);
        current = s;
    }

    void popState() {
        State* aux = states.top();
        delete aux;
        states.pop();
        if (states.size() > 0) current = states.top();
        else current = nullptr;
    }

    State *currentState(){
        return current;
    }
};

#endif
