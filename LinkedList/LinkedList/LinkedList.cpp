#include<iostream>
#include<windows.h>
using namespace std;
typedef struct LinkNode{
	int data;
	LinkNode * next;
}ListNode,*LinkList;

//头插法 按输入逆序
LinkNode * createListHead(){
	ListNode *temp;
	int data = 0;
	//初始化头结点,头结点为空
	LinkNode * head = (LinkList)malloc(sizeof(ListNode));
	head->next = NULL;
	//输入节点值域
	while(cin>>data&&data!=-1){
		//创建新节点
		temp = (ListNode *)malloc(sizeof(ListNode));
		temp->data = data;
		temp->next = head->next;
		head->next = temp;
	}
	return head;
}

//尾插法
LinkNode * createListRear(){
	//创建头空节点
	LinkNode * head = (LinkNode *)malloc(sizeof(LinkNode));
	//构造临时节点,表尾指针
	LinkNode * temp,* r=head;
	int data;
	while(cin>>data&&data!=-1){
		temp = (LinkNode *)malloc(sizeof(LinkNode));
		temp->data = data;
		temp->next = NULL;
		r->next = temp;
		r = temp;
	}
	return head;
}

//遍历链表并获取链表长度
int printList(LinkList L){
	LinkNode * p = L->next;
	int length = 0;
	if(p==NULL){
		cout<<"LinkList is NULL"<<endl;
		return 0;
	}
	while(p!=NULL){
		cout<<p<<"::"<<p->data<<" ";
		p = p->next;
		length++;
	}
	cout<<endl;
	return length;
}

//按序号查找
LinkNode * getItemByIndex(LinkList L,int index){
	LinkNode * p = L->next; 
	int count = 1;
	while(p!=NULL && count<index){
		count++;
		p = p->next;
	}
	return p;
}

//按值查找
LinkNode * getItemByValue(LinkList L,int value){
	LinkNode * p = L->next;
	while(p!=NULL && p->data!=value)
		p = p->next;
	return p;
}

//插入节点 O(n) 前插
LinkList insertFormer(LinkList &L,int index,int data){
	LinkNode * formerNode = getItemByIndex(L,index-1);
	LinkNode * insertNode = (LinkNode *)malloc(sizeof(LinkNode));
	insertNode->data = data;
	insertNode->next = formerNode->next;
	formerNode->next = insertNode;
	return L;
}
//插入节点 O(n) 后插
LinkList insertLater(LinkList &L,int index,int data){
	LinkNode * originalNode = getItemByIndex(L,index);
	LinkNode * insertNode = (LinkNode *)malloc(sizeof(LinkNode));
	insertNode->data = data;
	int temp = insertNode->data;
	insertNode->next = originalNode->next;
	originalNode->next = insertNode;
	insertNode->data = originalNode->data;
	originalNode->data = temp;
	return L;
}

//删除节点 O(n) 利用前驱节点
LinkList deleteByFormer(LinkList &L,int index){
	LinkNode * formerNode = getItemByIndex(L,index-1);
	LinkNode * delNode = formerNode->next;
	formerNode->next = delNode->next;
	free(delNode);
	return L;
}

//删除节点 O(n) 利用后驱节点
LinkList deleteByLater(LinkList &L,int index){
	LinkNode * delNode = getItemByIndex(L,index);
	LinkNode * laterNode = delNode->next;
	delNode->data = laterNode->data;
	delNode->next = laterNode->next;
	free(laterNode);
	return L;
}
//非原链表逆序
ListNode * reverse(ListNode * head){
	if(head==NULL||head->next==NULL)
		return head;
	ListNode * newHead = (ListNode *)malloc(sizeof(ListNode));
	newHead->data = head->data;
	newHead->next = NULL;
	ListNode * p = head->next;
	while(p){
		ListNode * temp = (ListNode *)malloc(sizeof(ListNode));
		temp->data = p->data;
		temp->next = newHead->next;
		newHead->next = temp;
		p = p->next;
	}
	free(head);
	return newHead;
}
//原链表逆序
ListNode * reverseList(ListNode * head){

}

int main(){
	//LinkList headL = createListHead();
	//int lengthHead = printList(headL);
	//cout<<"LinkList length = "<<lengthHead<<endl;
	////创建链表
	LinkList rearL = createListRear();
	//遍历、求表长
	int lengthRear = printList(rearL);
	cout<<"LinkList length = "<<lengthRear<<endl;
	//按位置查找节点
	//LinkNode * indexNode = getItemByIndex(rearL,4);
	//cout<<"the node data is "<<indexNode->data<<endl;
	////按值查找节点
	//LinkNode * valueNode = getItemByValue(rearL,50);
	//if(valueNode)
	//	cout<<"the node data is "<<valueNode->data<<endl;
	//else
	//	cout<<"Not Found"<<endl;
	////前插节点
	//insertFormer(rearL,3,100);
	//printList(rearL);
	////后插节点
	//insertLater(rearL,4,200);
	//printList(rearL);
	////删除 利用前驱
	//deleteByFormer(rearL,4);
	//printList(rearL);
	////删除 利用后驱
	//deleteByLater(rearL,3);
	//printList(rearL);
	//LinkList reverseList = (LinkNode *)malloc(sizeof(LinkNode));
	//reverseByCreateList(rearL,reverseList);
	//printList(reverseList);
	
	LinkList list = reverse(rearL);
	printList(list);
	system("pause");
	return 0;
}

//class Solution {
//public:
//    ListNode* reverseList(ListNode* head) {
//        if(head->next==NULL||head==NULL)
//            return head;
//        else{
//        ListNode * newHead = (ListNode *)malloc(sizeof(ListNode));
//	    newHead->next = NULL;
//	    ListNode * p;
//    	ListNode * temp = head->next;
//    	while(temp){
//		    p = (ListNode *)malloc(sizeof(ListNode));
//		    p->val = temp->val;
//	    	p->next = newHead->next;
//	    	newHead->next = p;
//	    	temp = temp->next;
//    	}
//	    free(head);
//	    return newHead;
//        }
//    }
//};
//ListNode* reverseList(ListNode* head) {
//        if(head==NULL||head->next==NULL)
//		return head;
//	ListNode * newHead = (ListNode *)malloc(sizeof(ListNode));
//	newHead->val = head->val;
//	newHead->next = NULL;
//	ListNode * p = head->next;
//	while(p){
//		ListNode * temp = (ListNode *)malloc(sizeof(ListNode));
//		temp->val = p->val;
//		temp->next = newHead->next;
//		newHead->next = temp;
//		p = p->next;
//	}
//	return newHead;
//    }