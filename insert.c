#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
}Node;
void printlist(Node *head);
void insertList(Node **head,int target);
void delNode(Node **head,int key);

int main(){
	printf("==THIS IS PROGRAM==\n");
	Node *head = NULL,*temp = NULL, *tail = NULL;
	int num;
	printf("masukan node yang mau dicetak: \n");
	if(scanf("%d",&num) == 0 || num < 0){
	printf("salah input !\n");
	return 1;
	}
	for(int i = 0;i<num;i++){
	temp = (Node*)malloc(sizeof(Node));
	if(temp == NULL){
	printf("alokasi gagal!");
	free(temp);
	return 1;
	}
	temp->data = i * 3;
	temp->next = NULL;
	if(head == NULL){
	head = temp;
	}else{
	tail->next = temp;
	}
	tail = temp;
	}
	printlist(head);
	printf("\n cetak node yang telah diproses : \n");
	int target;
	printf("masukan node list yang ingin diinsert di head: \n");
	scanf("%d",&target);
	insertList(&head,target);
	printlist(head);
	int key;
	printf("masukan Node yang akan dihapus: \n");
	scanf("%d",&key); 
	delNode(&head,key);
	printlist(head);
	return 0;
	}

	void printlist(Node *head){
	while(head != NULL){
	printf("%d ",head->data);
	head = head->next;
	}
}

	void delNode(Node **head, int key) {
    Node *temp = *head;
    Node *prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    prev->next = temp->next;
    free(temp);
}

	void insertList(Node **head,int target){
		Node *temp = (Node*)malloc(sizeof(Node));
		temp->data = target;
		temp->next = *head;
		*head = temp;
	}

