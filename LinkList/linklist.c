#include <stdio.h>
#include <stdlib.h>


typedef struct LinkList{
	int data;
	struct LinkList *next;
}node;


void Push(node **headRef, int newData){
	node *newnode=(node *)malloc(sizeof(node));
	node *temp;
	if(newnode==NULL){
		printf("Error allocating memeory !!!\n");		
		exit(1);
	}
	newnode->next=NULL;
	newnode->data=newData;
	if(*headRef==NULL){
		*headRef=newnode;
	}else{
		temp=*headRef;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=newnode;
	}
}

void RemoveDuplicates(node *head){
	node *temp,*temp1,*del;
	temp=head;
	temp1=NULL;
	del=NULL;
	if(temp->next!=NULL){
		temp1=temp->next;
		while(temp1!=NULL){
			if(temp1->data==temp->data){	
				del=temp1;			
				temp1=temp1->next;
				temp->next=temp1;
				free(del);
				
			}else{
				temp=temp->next;
				temp1=temp1->next;
			}
		}
	}
	
}

void MoveNode(node** destRef, node** sourceRef) {
	node *temp=*sourceRef;
	*sourceRef=(*sourceRef)->next;
	temp->next=*destRef;
	*destRef=temp;
}

int Length(node* head){
	node *temp=head;
	int count;
	count=0;
	while(temp!=NULL){
		count=count+1;
		temp=temp->next;
	}
	return count;
}

node* BuildOneTwoThree(){
	node *head=NULL;
	Push(&head,1);
	Push(&head,2);
	Push(&head,3);	
	return head;
}


int Count(node* head, int searchFor){
	int occur=0;
	node *temp;
	temp=head;
	while(temp!=NULL){
		if(temp->data==searchFor)
			occur++;
		temp=temp->next;	
	}
	return occur;
}


void CountTest() {
	node *myList = BuildOneTwoThree();
	int count = Count(myList, 2);
	fprintf(stdout,"Count:%d\n",count);
}	

int GetNth(node *head,int num){
	node *temp=head;
	int count=1;
	while(temp!=NULL){
		if(count==num){
			return temp->data;
		}
		count++;
		temp=temp->next;
	}
	return -1;
}

void DeleteList(node **head){
	node *temp=*head;
	node *temp1;
	if(*head!=NULL){
		while(temp!=NULL){
			temp1=temp;
			temp=temp->next;
			temp1->next=NULL;
			free(temp1);
		}
		*head=NULL;
	}
}

void GetNthTest() {
	node* myList = BuildOneTwoThree();
	int lastNode = GetNth(myList, 2);
	fprintf(stdout,"value:%d\n",lastNode);
}

void DeleteListTest() {
	int len;
	node* myList = BuildOneTwoThree();
	DeleteList(&myList);
	len=Length(myList);
	fprintf(stdout,"After delete ALL len:%d\n",len);
}

int Pop(node **head){
	node *temp=*head;
	int data;
	if(temp==NULL){
		return -1;
	}else{
		*head=(*head)->next;
		data=temp->data;
		free(temp);
		return data;
	}
	
}

void InsertNth(node **head,int pos,int data){
	node *temp=*head;
	int c_pos=1;
	node *newnode=(node *)malloc(sizeof(node));
	newnode->next=NULL;
	newnode->data=data;
	if(temp==NULL){
		*head=newnode;
	}else{
		while(temp!=NULL){
			if(c_pos==pos){
				newnode->next=temp->next;
				temp->next=newnode;
				return;			
			}
			temp=temp->next;
		}		
	}
}

void PopTest() {
	node* head = BuildOneTwoThree();
	int a = Pop(&head);
	int b = Pop(&head);
	int c = Pop(&head);
	int len = Length(head);
	fprintf(stdout,"Length after three pop:(%d %d %d) %d\n",a,b,c,len);
}

void InsertNthTest() {
	node* head = NULL;
	InsertNth(&head, 0, 13);
	InsertNth(&head, 1, 42);
	InsertNth(&head, 1, 5);
	int len = Length(head);
	fprintf(stdout,"Length after three pop:%d\n",len);
	DeleteList(&head);
}

void SortedInsert(node** headRef, node* newNode) {
	node *temp=*headRef;
	if(temp==NULL){
		*headRef=newNode;
	}else{
		if(temp->data>newNode->data){
			newNode->next=temp;
			*headRef=newNode;
		}else{
			while(temp!=NULL){
				if(temp->next->data > newNode->data){
					newNode->next=temp->next;
					temp->next=newNode;
					break;
				}
			}
		}
	}
}

void InsertSort(node** headRef){
	node *temp,*temp1;
	temp=*headRef;
	headRef=NULL;
	while(temp!=NULL){
		temp1=temp;
		temp=temp->next;
		SortedInsert(headRef,temp1);
	}
	
}

void Append(node** aRef,node** bRef) {
	node *temp=*aRef;
	if(temp!=NULL){	
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=*bRef;
		*bRef=NULL;
	}else{
		*aRef=*bRef;
		*bRef=NULL;
	}	
}

void FrontBackSplit(node* source,node** frontRef, node** backRef) {
	node *temp,*temp1;
	temp=source;
	temp1=source->next->next;
	*frontRef=source;
	if(temp->next==NULL){
		*frontRef=source;
		backRef=NULL;
	}else{
		if(temp->next->next==NULL){
			*frontRef=source;
			(*frontRef)->next=NULL;
			*backRef=(source->next);
		}else{
			while(temp1!=NULL){
				temp=temp->next;
				if(temp1->next!=NULL){
					if(temp1->next->next!=NULL)
						temp1=temp1->next->next;
					else{
						break;
					}	
				}else{
					break;
				}	
			}			
			*backRef=temp->next;
			temp->next=NULL;
		}
	}	
}

void display(node *temp){
	printf("Data:\n");
	while(temp->next!=NULL){
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("%d\n",temp->data);
}

void FrontBackCheck(){
	node *frontRef;
	node *backRef;
	node *myList = BuildOneTwoThree();
	//Push(&myList,4);
	//Push(&myList,5);
	FrontBackSplit(myList,&frontRef,&backRef);
	display(frontRef);
	display(backRef);
			
}

void AlternatingSplit(node* source,node** aRef, node** bRef) {
	node *temp,*temp1,*temp2;
	temp=source;
	temp1=NULL;
	if(temp->next!=NULL){
		*aRef=temp;
		*bref=temp->next;
		while(temp->next->next!=NULL){
			temp1=temp->next;
			temp->next=temp->next->next;
			temp=temp->next;
			if(temp->next!=NULL)
				temp1->next=temp->next;			
			else
				break;	
		}
	}

}

node* ShuffleMerge(node* a, node* b) {
	node *head;
	node *temp,*temp1,*temp2;
	head=a;
	temp=a;
	temp1=b;
	temp2=a;
	while(temp->next!=NULL && temp1->next!=NULL){
		temp=temp->next;
		temp2->next=temp1;
		temp1=temp1->next;
		temp2=temp2->next;		
		temp2->next=temp;
	}	
	if(temp1->next==NULL){
		temp2->next=temp1;
		if(temp->next!=NULL){
			temp2->next=temp;
		}
	}else{
		temp2->next=temp1;
	}
	return head;
}

node* SortedMerge(struct node* a, struct node* b) {
	node *head,*temp,*temp1,*temp2;
	temp=a;
	temp1=b;
	if(temp->data<=temp1->data){
		head=temp;
		temp=temp->next;		
	}else{
		head=temp1;
		temp1=temp1->next;
	}
	temp2=head;
	while(temp!=NULL && temp1!=NULL)
	{
		if(temp->data<=temp1->data){
			temp2->next=temp;
			temp=temp->next;							
		}else{
			temp2->next=temp1;
			temp1=temp1->next;
		}		
	}
	if(temp!=NULL){
		temp2->next=temp;
	}
	if(temp1!=NULL){
		temp2->next=temp1;
	}
	return head;
}


void MergeSort(node* headRef) {
	if(headRef->next!=NULL){
		node *front,*back;
		FrontBackSplit(node* source,&front, &back);
		MergeSort(front);
		MergeSort(back)
		SortedMerge(front,back)
	}
}

node* SortedIntersect(node* a, node* b) {
	node *head;
	while(a!=NULL && b!=NULL){
		if(a->data < b->data){
			Push(head,a->data);
			a=a->next;
		}else{
			if(a->data==b->data){
				Push(head,a->data);
				a=a->next;
				b=b->next;
			}else{
				Push(head,b->data);
				b=b->next;
			}
		}
	}
	if(a!=NULL){
		while(a!=NULL){
			Push(head,a->data);
			a=a->next;
		}
	}else{
		while(b!=NULL){
			Push(head,a->data);
			a=a->next;
		}
	}
	return head;
}

void RecursiveReverse(node** headRef) {
	if((*headRef)->next!=NULL){
		if((*headRef)->next->next!=NULL){
			RecursiveReverse(&((*headRef)->next)));
		}else{
			(*headRef)->next->next=(*headRef);
		}
	}
}

int main(int argc, char *argv[]){
	CountTest();
	GetNthTest();
	DeleteListTest();
	PopTest();
	InsertNthTest();
	FrontBackCheck();
	return 0;
}
