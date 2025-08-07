#include<stdio.h>
#include<stdlib.h>
struct stack{
int arr[5];
int top;
};
void initialise(struct stack *s){
    s->top=0;
}
void push(struct stack *s,int a){
    s->arr[s->top++]=a;
}
int pop(struct stack *s) {
    int val = s->arr[--s->top];
    s->arr[s->top] = 0;
    return val;
}
void printer(struct stack *s){
    for(int i=0;i<5;i++){
        
        printf("%d ", s->arr[i]);

}
}

int main(){
    struct stack s;
    initialise(&s);
    push(&s,1);
    push(&s,2);
    push(&s,3);
    push(&s,4);
    push(&s,5);
    // printer(&s);
    printf("%d",pop(&s));
    printf("%d",pop(&s));
    printer(&s);

    
}