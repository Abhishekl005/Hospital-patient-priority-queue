#include <stdio.h>
#include <string.h>

#define MAX 100

struct Patient {
    char name[20];
    int priority;
};

struct Patient heap[MAX];
int size = 0;

void swap(struct Patient *a, struct Patient *b) {
    struct Patient temp = *a;
    *a = *b;
    *b = temp;
}

void addPatient(char name[], int priority) {
    int i;

    size++;
    i = size - 1;

    strcpy(heap[i].name, name);
    heap[i].priority = priority;

    while (i > 0) {
        int parent = (i - 1) / 2;

        if (heap[parent].priority <= heap[i].priority)
            break;

        swap(&heap[parent], &heap[i]);
        i = parent;
    }

    printf("Added: %s (Priority %d)\n", name, priority);
}

void treatNext() {
    struct Patient next;
    int i = 0;

    if (size == 0) {
        printf("No patients waiting.\n");
        return;
    }

    next = heap[0];

    heap[0] = heap[size - 1];
    size--;

    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < size && heap[left].priority < heap[smallest].priority)
            smallest = left;

        if (right < size && heap[right].priority < heap[smallest].priority)
            smallest = right;

        if (smallest == i)
            break;

        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }

    printf("Treating: %s (Priority %d)\n", next.name, next.priority);
}

int main() {
    addPatient("P1", 3);
    addPatient("P2", 1);
    addPatient("P3", 2);
    addPatient("P4", 1);
    addPatient("P5", 3);
    addPatient("P6", 2);

    printf("\n--- Treatment Order ---\n");

    treatNext();
    treatNext();
    treatNext();

    printf("\n--- New Emergency Patient ---\n");

    addPatient("P7", 1);

    printf("\n--- Remaining Treatment Order ---\n");

    treatNext();
    treatNext();
    treatNext();
    treatNext();

    return 0;
}
