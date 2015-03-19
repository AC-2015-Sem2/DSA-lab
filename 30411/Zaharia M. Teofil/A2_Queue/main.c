#include "Queue.h"

#include <stdio.h>
#include <string.h>

int main() {
    Queue* customers = newQueue();
    Queue* times = newQueue();

    FILE *in = fopen("input.dat", "r"),
        *out = fopen("output.dat", "w");

    int t;
    while (fscanf(in, "%d ", &t)) {
        enqueue(times, 0, t);
    }

    int newVal, newTime;
    char line[50], *pch;

    while(fgets(line, 50, in)) {
        pch = strtok(line, " ");

        pch = strtok(NULL, " ");
        newVal = atoi(pch);

        pch = strtok(NULL, " \n");
        newTime = atoi(pch);

        enqueue(customers, newVal, newTime);
    }

    int currentT = 0, totalSum = 0;
    while (!isEmpty(times)) {

        t = peek(times)->time;
        while (!isEmpty(customers) && t >= currentT + peek(customers)->time) {
            totalSum += peek(customers)->val;
            currentT += peek(customers)->time;
            dequeue(customers);
        }
        fprintf(out, "After %d seconds: %d\n", t, totalSum);
        dequeue(times);
    }

    freeQueue(customers);
    freeQueue(times);
    return 0;
}
