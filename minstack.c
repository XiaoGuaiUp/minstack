#include <stdio.h>
#include "seqstack.h"

typedef struct MinStack{
    SeqStack stack;
} MinStack;

//初始化
void MinStackInit( MinStack* min_stack ){
    if(min_stack==NULL){
        return ;
    }
    SeqStackInit(&min_stack->stack);
}

//入栈
//思路：要保证每次取栈顶元素取到的是最小值，要一次入栈两个元素
//      一个是本次需要入栈的元素，一次是经过比较的此时栈中元素的最小值
//      此时，入栈两个元素的先后顺序必须保证先入value,再入min
void MinStackPush(MinStack* min_stack,SeqStackType value){
    if(min_stack==NULL){
        return;
    }
    SeqStackType min=value;
    SeqStackType top;
    int ret=SeqStackTop(&min_stack->stack,&top);
    if(ret==0){
        //空栈,啥也不做，此时min=value
    }
    else{
        //如果非空，就证明栈中有元素，此时要判断栈顶元素与要插入元素的大小关系
        //给min赋入正确的值，也就是最小值
        min=top<value? top:value;
    }
    //此时进行入栈，先插入value,后插入min，保证栈顶元素是当前栈的最小值
    SeqStackPush(&min_stack->stack,value);
    SeqStackPush(&min_stack->stack,min);
    return;
}

//出栈
//一次出两个，第一个为最小值，第二个为最后进入栈的元素
void MinStackPop(MinStack* min_stack){
    if(min_stack==NULL){
        return;
    }
    //连出两个
    SeqStackPop(&min_stack->stack);
    SeqStackPop(&min_stack->stack);
}

//取栈顶元素
int MinStackTop(MinStack* min_stack,SeqStackType* value){
    if(min_stack==NULL){
        return 0;
    }
    return SeqStackTop(&min_stack->stack,value);
}

//////////////////////////////////////////////////////////////////////////////
//以下为测试函数
////////////////////////////////////////////////////////////////////////////
void MinStackPrint(MinStack* min_stack,const char* msg){
    if(min_stack==NULL){
        return;
    }
    SeqStackPrint(&min_stack->stack,msg);
}

void Test(){
    printf("=================%s================\n",__FUNCTION__);
    MinStack min_stack;
    MinStackInit(&min_stack);

    MinStackPush(&min_stack,'a');
    MinStackPush(&min_stack,'b');
    MinStackPush(&min_stack,'c');
    MinStackPush(&min_stack,'d');
    MinStackPrint(&min_stack,"测试入栈4个元素");

    MinStackPop(&min_stack);
    MinStackPrint(&min_stack,"测试出栈1个元素");

    MinStackPrint(&min_stack,"出栈一个元素后的栈");

    char top;
    int ret=MinStackTop(&min_stack,&top);
    printf("[测试取栈顶元素]\n");
    printf("ret期望值为1，实际值为：%d\n",ret);
    printf("栈顶元素为：%c\n",top);
}

void main()
{
    Test();
}
