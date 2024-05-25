#include <stdio.h>
#include <stdlib.h>

// MinStack implementation using heap
typedef struct {
    int *stack;
    int *min_heap;
    int size;
} MinStack;

MinStack* createMinStack(int maxSize) {
    MinStack* stack = (MinStack*)malloc(sizeof(MinStack));
    stack->stack = (int*)malloc(sizeof(int) * maxSize);
    stack->min_heap = (int*)malloc(sizeof(int) * maxSize);
    stack->size = 0;
    return stack;
}

void push(MinStack* stack, int x) {
    stack->stack[stack->size] = x;
    stack->size++;

    int i = stack->size - 1;
    while (i > 0 && x < stack->min_heap[(i - 1) / 2]) {
        stack->min_heap[i] = stack->min_heap[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    stack->min_heap[i] = x;
}

int pop(MinStack* stack) {
    if (stack->size == 0)
        return -1;

    int popped = stack->stack[stack->size - 1];
    stack->size--;

    int i = 0;
    while (stack->min_heap[i] != popped && i < stack->size)
        i++;

    for (; i < stack->size; i++) {
        stack->min_heap[i] = stack->min_heap[i + 1];
    }

    return popped;
}

int getMin(MinStack* stack) {
    if (stack->size == 0)
        return -1;
    return stack->min_heap[0];
}

// AvgQueue implementation using array
typedef struct {
    int *queue;
    int front;
    int rear;
    int size;
    int sum;
} AvgQueue;

AvgQueue* createAvgQueue(int maxSize) {
    AvgQueue* queue = (AvgQueue*)malloc(sizeof(AvgQueue));
    queue->queue = (int*)malloc(sizeof(int) * maxSize);
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    queue->sum = 0;
    return queue;
}

void pushAvg(AvgQueue* queue, int x) {
    queue->rear++;
    queue->queue[queue->rear] = x;
    queue->size++;
    queue->sum += x;
}

int popAvg(AvgQueue* queue) {
    if (queue->size == 0)
        return -1;
    
    int popped = queue->queue[queue->front];
    queue->front++;
    queue->size--;
    queue->sum -= popped;
    return popped;
}

int getAvg(AvgQueue* queue) {
    if (queue->size == 0)
        return -1;
    return queue->sum / queue->size;
}

int main() {
    int q;
    scanf("%d", &q);

    MinStack* minStack = createMinStack(q);
    AvgQueue* avgQueue = createAvgQueue(q);

    while (q--) {
        int query;
        scanf("%d", &query);

        if (query == 1) {
            int x;
            scanf("%d", &x);
            push(minStack, x);
            pushAvg(avgQueue, x);
        } else if (query == 2) {
            pop(minStack);
            popAvg(avgQueue);
        } else if (query == 3) {
            printf("%d %d\n", getMin(minStack), getAvg(avgQueue));
        }
    }

    free(minStack->stack);
    free(minStack->min_heap);
    free(minStack);
    free(avgQueue->queue);
    free(avgQueue);

    return 0;
}


