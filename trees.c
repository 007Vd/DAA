
#include<stdio.h>
#include<stdlib.h>

struct trees {
    int val;
    struct trees * right;
    struct trees *left;

};
void initialize(struct trees *b,int val){
    // b=malloc(sizeof(struct trees));
    b->right=NULL;
    b->left=NULL;
    b->val=val;


}
int main(){
    struct trees b;
    struct trees a;
    struct trees c,cl,cr;
    // struct trees
    initialize(&b,10);
    initialize(&a,5);
    initialize(&c,20);
    initialize(&cl,15);
    initialize(&cr,25);
    

    b.right=&c;
    b.left=&a;
    c.left=&cl;
    c.right=&cr;

    printf("Root: %d\n",b.val);
    printf("Left Child: %d\n",b.left->val);
    printf("Right Child: %d\n",b.right->val);
    printf("c's Left Child: %d\n",c.left->val);
    printf("c's Right Child: %d\n",c.right->val);



}