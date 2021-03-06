#include<iostream>

using namespace std;


struct node{
	int data;
	struct node* left;
	struct node* right;
	struct node* next;
};

node* createNode(int data){
	node* node1=new node;
	node1->data=data;
	node1->left=NULL;
	node1->right=NULL;
	node1->next=NULL;
	return node1;
}

node * insert(node *curNode,node *newNode){
	if(curNode==NULL){
		curNode=newNode;		
	}else{
		if(curNode->data>newNode->data){
			curNode->left=insert(curNode->left,newNode);
		}else{
			curNode->right=insert(curNode->right,newNode);
		}
	}
	return curNode;
}

void display(node *curNode){
	if(curNode!=NULL){
		cout<<curNode->data<<" ";
		display(curNode->left);
		display(curNode->right);
	}
}

void size(node *curNode,int *size1){
	if(curNode!=NULL){
		*size1=*size1+1;
		size(curNode->left,size1);
		size(curNode->right,size1);
	}
}

int maxDepth(node* curNode,int depth){	
	if(curNode!=NULL){
		int depth1,depth2;
		depth=depth+1;
		depth1=maxDepth(curNode->left,depth);
		depth2=maxDepth(curNode->right,depth);		
		if(depth1>depth2){
			depth=depth1;
		}else{
			depth=depth2;
		}
	}
	return depth;
}

int minValue(node* curNode,int value){
	if(curNode!=NULL){
		value=curNode->data;
		if(curNode->left->data<curNode->right->data)
			value=minValue(curNode->left,value);	
		else
			value=minValue(curNode->right,value);	
	}
	return value;
}

int hasPathSum(node *curNode,int value,int sum){
	if(curNode!=NULL){
		sum=sum+curNode->data;
		if(hasPathSum(curNode->left,value,sum)){
			return 1;
		}else{
			return hasPathSum(curNode->left,value,sum);
		}
	}else{
		if(sum==value){
			return 1;
		}else{
			return 0;
		}
	}
	
}

void printPaths(node *curNode,int *path,int size){
	if(curNode!=NULL){
		path[size]=curNode->data;
		if(curNode->left==NULL && curNode->right==NULL){
			int i=0;
			while(i<=size){
				cout<<path[i]<<" ";
				i++;
			}
			cout<<endl;	
			return;
		}
		if(curNode->left!=NULL)
			printPaths(curNode->left,path,size+1);
		if(curNode->right!=NULL)	
			printPaths(curNode->right,path,size+1);
	}
}

void mirror(node *curNode){
	if(curNode!=NULL){
		node *temp;
		temp=curNode->left;
		curNode->left=curNode->right;
		curNode->right=temp;
		mirror(curNode->left);
		mirror(curNode->right);
	}
}


node* doubleTree(node *curNode){
	if(curNode!=NULL){
		if(curNode->left==NULL){
			curNode->left=createNode(curNode->data);
			return curNode;
		}else{
			curNode->left=doubleTree(curNode->left);
			node *temp;
			temp=curNode->left;
			curNode->left=createNode(curNode->data);
			curNode->left->left=temp;
			return curNode;
		}
	}
}

node *inOrder(node *curNode){
	if(curNode!=NULL){
		if(curNode->left!=NULL){
			inOrder(curNode->left);			
			cout<<curNode->data;
			if(curNode->right!=NULL){
				inOrder(curNode->right);
			}else{
				return NULL;
			}
		}
		else{
			cout<<curNode->data;
			if(curNode->right!=NULL){
				inOrder(curNode->right);
			}else{
				return NULL;
			}
		}
			
	}
	return curNode;
}

int checkBalance(node *curNode,int currentLevel,int level){
	if(curNode!=NULL && (curNode->right!=NULL || curNode->left!=NULL)){
		if(curNode->left!=NULL)
			currentLevel=checkBalance(curNode->left,currentLevel,level+1);
		if(currentLevel==0){
			return 0;
		}else{
			if(curNode->right!=NULL)
				currentLevel=checkBalance(curNode->right,currentLevel,level+1);
			if(currentLevel!=0){
				return currentLevel;
			}else{
				return 0;
			}
		}
	}else{
		cout<<"cur leaf data:"<<curNode->data<<"level and currentLevel:"<<level<<" "<<currentLevel<<endl;
		if(currentLevel==-1){
			currentLevel=level;
			return level;
		}else{
			if(currentLevel!=level){
				return 0;
			}else{
				return currentLevel;
			}
		}
	}
}


node *createMinimalTree(node *root,int *path,int start,int end){
	int middle;
	if(end<start)
		return root;
	middle=(start+end)/2;	
	node *temp=createNode(path[middle]);
	root=insert(root,temp);
	display(root);
	cout<<endl;
	root=createMinimalTree(root,path,start,middle-1);	
	root=createMinimalTree(root,path,middle+1,end);
	return root;	
}

node *insertLink(node *head,node *temp1){
	node *temp=NULL;
	if(head==NULL){
		head=temp1;
		head->next=NULL;
	}else{
		temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=temp1;
	}
	return head;
}

node ** createLinkList(node* curNode,node* head[],int level){
	if(curNode!=NULL){
		head[level]=insertLink(head[0],curNode);
		head=createLinkList(curNode->left,head,level+1);
		head=createLinkList(curNode->right,head,level+1);
	}
	return head;
}


int main(int argc,char *argv[]){
	node *root=NULL,**head=NULL;
	int size1=0;
	int path[]={1,2,3,4,5,6,7};
	node *temp=createNode(2);
	root=insert(root,temp);
	temp=createNode(3);
	root=insert(root,temp);
	temp=createNode(1);	
	root=insert(root,temp);
	temp=createNode(8);	
	root=insert(root,temp);
	temp=createNode(6);	
	root=insert(root,temp);
	//display(root);
	/*cout<<endl;
	size(root,&size1);
	cout<<"Size of tree is:"<<size1<<endl;
	cout<<"Depth of tree is:"<<maxDepth(root,0)<<endl;
	if(hasPathSum(root,4,0))
		cout<<"Yeps it Has the sum!!!"<<endl;	
	printPaths(root,path,0);*/
	mirror(root);
	display(root);
	cout<<endl;
	mirror(root);
	display(root);
	/*cout<<endl;
	doubleTree(root);	
	display(root);
	printPaths(root,path,0);*/
	/*head=inOrder(root);
	if(checkBalance(root,-1,0)){
		cout<<"Same Level"<<endl;
	}else{
		cout<<"Not same level"<<endl;
	}
	root=createMinimalTree(root,path,0,6);
	display(root);
	cout<<endl;
	int d=maxDepth(root,0);
	head=new node *[d];
	head=createLinkList(root,head,0);*/
}
