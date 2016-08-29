#include<stdio.h> 
int maze[10][10] = { 
        {1,1,1,1,1,1,1,1,1,1}, 
        {1,0,0,1,0,0,0,1,0,1}, 
        {1,0,0,1,0,0,0,1,0,1}, 
        {1,0,0,0,0,1,1,0,0,1}, 
        {1,0,1,1,1,0,0,0,0,1}, 
        {1,0,0,0,1,0,0,0,0,1}, 
        {1,0,1,0,0,0,1,0,0,1}, 
        {1,0,1,1,1,0,1,1,0,1}, 
        {1,1,1,0,0,0,0,0,0,1}, 
        {1,1,1,1,1,1,1,1,1,1}}; 
int mark[10][10] = {0};		/*初始化标志位,0代表没走过,1代表走过*/ 

/*方向*/ 
typedef struct{ 
    short int vert; 
    short int horiz; 
}offsets; 

offsets move[4] = {{0,1},{1,0},{0,-1},{-1,0}};/*北,东,南,西*/ 


/*迷宫类型*/ 
typedef struct element{ 
    short int row; 
    short int col; 
    short int dir; 
}element; 

element stack[100]; 


void path(void); 
  element del(int* top); 
void add(int* top,element item); 


element del(int* top)/*出栈,top指向栈顶元素*/ 
{ 
    if(*top == -1) 
    { 
        printf("stack is empty!\n"); 
    } 
    return stack[(*top)--]; 
} 



void add(int* top,element item)/*入栈*/ 
{ 
    if(*top >= 100) 
    { 
        printf("stack is full!\n"); 
        return; 
    } 
    stack[++*top] = item; 
} 


void path(void)/*迷宫函数*/ 
{ 
    element position; 
    int i,row,col,next_row,next_col,dir,top; 
    int found = 0; 
    mark[1][8] = 1,top = 0;/*初始化标志数组元素以及栈*/ 
    stack[0].row = 1,stack[0].col = 8,stack[0].dir = 0; 
    while(top > -1 && !found) 
    { 
       	position= del(&top);  /*将栈顶元素取出,*/ 
        row = position.row;            /*利用中间变量row,col,dir等候判断*/ 
        col = position.col; 
        dir = position.dir; 
        while(dir < 4 && !found) 
        { 
            next_row = row + move[dir].vert; 
            next_col = col + move[dir].horiz; 
            if(row == 7 && col == 1) 
                found = 1; 
            else if(!maze[next_row][next_col] && !mark[next_row][next_col])/*判断下一步可走并且没走过,则入栈*/ 
                   { 
                        mark[next_row][next_col] = 1; 
                        position.row = row; 
                        position.col = col; 
                        position.dir = ++dir; 
                        add(&top,position);	/*合理则入栈*/ 
                        row = next_row;		/*继续向下走*/ 
                        col = next_col;dir = 0; 
                    } 
                    else 
                        dir++;/*dir<4时,改变方向*/ 
       
        } 
        if(found)/*判断是否有出口*/ 
        { 
            printf("the path is:\n"); 
            printf("row col\n"); 
            for(i = 0;i <= top;++i) 
                printf("(%2d,%5d)",stack[i].row,stack[i].col);
                printf("(%2d,%5d)\n",7,1);
            
            
        } 
         
            
    }
    if(found==0)
        printf("没有路径\n");
}


int main(void) 
{   
    path(); 
     
return 0; 
}
