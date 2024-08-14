/* 參考（引用）的教學如下：
[C語言] 使用陣列(Array) 實作資料結構的佇列(Queue)
https://everythingcheapcheaper.blogspot.com/2020/06/c-array-queue.html?m=1
[C語言] 以鏈結串列(Linked List) 實作資料結構的佇列(Queue)
https://everythingcheapcheaper.blogspot.com/2020/06/c-linked-list-queue.html?m=1
[軟體工程師雜談] 輕鬆搞懂資料結構: 佇列(Queue)
https://youtu.be/JSKtJqj2pwc */

#include <stdio.h>
#include <stdlib.h>

/*定義鏈結串列節點的資料結構*/
struct Node{
int data;
struct Node *next;
};

typedef struct Node Queue_Node;	//定義實作佇列用的節點之別名
Queue_Node *First = NULL;	//指向佇列前端(第一筆)的指標變數
Queue_Node *Last = NULL;	//指向佇列尾端(最後一筆)的指標變數
int Size = 0;			//佇列目前的大小

void Enqueue(int a);		//從佇列尾端存入資料，在main函數之後定義
int Dequeue();			//從佇列前端移除資料，在main函數之後定義
int getFirst();			//回傳佇列前端(第一筆)的資料，在main函數之後定義
int getLast();			//回傳佇列尾端(最後一筆)的資料，在main函數之後定義
int getSize();			//回傳佇列目前的大小，在main函數之後定義
int isEmpty();			//檢查佇列是否為空，在main函數之後定義

int main() {

	for(int i =0; i<8;i++){
		Enqueue(rand()%16);
	}
  
	if(isEmpty())
    {
		printf("佇列前端(第一筆)資料為:NULL\n");
		printf("佇列尾端(最後一筆)資料為:NULL\n");
	}
    else
    {
		printf("佇列前端(第一筆)資料為:%d\n",getFirst());
		printf("佇列尾端(最後一筆)資料為:%d\n",getLast());
	}
	printf("佇列的總數為:%d\n\n",getSize());
  
	while( !isEmpty() ){
		printf("佇列移除的資料為:%d\n", Dequeue());
	}
	Dequeue();
	return 0;
}

void Enqueue(int a) {
	Queue_Node *new_add_node;	//新加入節點的指標變數

	new_add_node = (Queue_Node*)malloc(sizeof(struct Node));	//配置新節點的記憶體

	new_add_node->data = a;		//將傳入的值設為新節點的內容
	new_add_node->next = NULL;	//將新節點指向NULL
  
	if(isEmpty())
		First = new_add_node;	//若佇列為空，則新節點成為佇列的前端(第一筆)，新節點也將會是佇列的尾端(最後一筆)
	else
		Last->next = new_add_node;	//若佇列不為空，則將Last指向新節點
    
	Last = new_add_node;		//新節點成為佇列的尾端(最後一筆)
	Size += 1;			//佇列的大小變大(增加一筆資料)
}

int Dequeue() {
	if(isEmpty())
    {
		printf("佇列為空\n");
	}
    else
    { 
		Queue_Node *ptr = First;	//指向佇列前端(第一筆)的指標變數
		int temp = First->data;		//被Dequeue的資料
		First = First->next;		//將佇列前端(第一筆)的指標指向下一個節點  
		free(ptr);			//將節點占用的記憶體釋放
		Size -= 1;			//佇列的大小變小(減少一筆資料)
		return temp;			//回傳被Dequeue的資料
	}  
}

int getFirst() {
	if(!isEmpty()){return First->data;}
}

int getLast() {
	if(!isEmpty()){return Last->data;}
}

int getSize() {
	return Size;
}

int isEmpty() {
	if (Size == 0)
    {
		First = NULL;
		Last = NULL;
		return 1;
	}
    else
    {
		return 0;
	}
}