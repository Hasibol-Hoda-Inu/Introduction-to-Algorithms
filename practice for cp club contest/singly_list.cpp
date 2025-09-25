#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int value;
        Node* next;
    Node(int value){
        this->value = value;
        this->next = NULL;
    }
};

void input(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

int size(Node* head, int cnt){
    Node* temp = head;
    if(head == NULL)
        return cnt;
    while (temp!=NULL)
    {
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    while (true)
    {
        int val; cin >> val;
        if(val == -1)
            break;
        input(head, tail, val);
    }
    
    size(head, 0);

    return 0;
}