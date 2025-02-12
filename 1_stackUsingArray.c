#include <stdio.h>
#define MAX 5
typedef enum{FALSE,TRUE} boolean;
typedef int itemtype;
typedef enum{SUCCESS, FAILURE} StatusCode;


typedef struct stack{
    int top;
    itemtype items[MAX];
}Stack;

void init(Stack *s){s->top = -1;}

boolean isEmpty(Stack *s) {return (s->top == -1) ? TRUE : FALSE;}

boolean isFull(Stack *s) {return (s->top == MAX-1) ? TRUE : FALSE;}

StatusCode push(Stack *s, itemtype item){
    StatusCode status;
    if(isFull(s)) status = FAILURE;
    else{
        s->top++;
        s->items[s->top] = item;
        status = SUCCESS;
    }
    return status;
}

StatusCode pop(Stack *s, itemtype *item){
    StatusCode status;
    if(isEmpty(s)) status = FAILURE;
    else{
        *item = s->items[s->top];
        s->top--;
        status = SUCCESS;
    }
    return status;
}

//boilerplate code
int main(){
    Stack s;
    init(&s);
   for(int i=0;i<5;i++) push(&s,i);
    itemtype item;
    while(!isEmpty(&s)){
        pop(&s,&item);
        printf("%d\n",item);
    }
    return 0;
}