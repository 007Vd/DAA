#include<stdio.h>
#include<stdlib.h>
struct queue {
    int front;
    int rear;
    int arr[5];

};
void initialize(struct queue *q){
    q->front=0;
    q->rear=0;

}
 void enque(struct queue *q,int a){
    q->arr[q->rear++]=a;
 }
 int deque(struct queue*q){
    int val=q->arr[q->front];
    q->front++;
    return val;

 }
 void printer(struct queue *q){
    for (int i=q->front;i<q->rear;i++){
        printf("%d\n",q->arr[i]);
    }
 }


int main(){
    struct queue q;
    initialize(&q);
    enque(&q,1);
enque(&q,2);
enque(&q,3);
enque(&q,4);
enque(&q,5);
// enque(&q,1)
// printer(&q);
printf("dqueued elemt %d\n",deque(&q));
printer(&q);
 }