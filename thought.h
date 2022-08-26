#ifndef THOUGHT_H_
#define THOUGHT_H_

#include <cstdlib>
#include <ctime>

void Thought(int n){
    int random;
    for (int i = 0; i < n; i++) {
        srand(time(NULL));
        do {
            random = (std::rand() % 1000000);
        } while (random != 1);
    }
}

#endif