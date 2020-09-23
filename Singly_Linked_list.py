# singly linked list
class node:
    def __init__(self,data):
        self.data=data
        self.next=None

class linkedlist:
    def __init__(self):
        self.head=None
    def addend(self,data):
        temp=self.head
        newNode=node(data)
        if(temp==None):
            self.head=newNode
        else:
            while(temp.next!=None):
                temp=temp.next
            temp.next=newNode
    def disp(self):
        temp=self.head
        while(temp!=None):
            print(temp.data,end=" ")
            temp=temp.next
        print()
    def delbeg(self):
        if(self.head==None):
            print('Empty')
        else:
            temp=self.head
            temp=temp.next
            self.head=temp
ll=linkedlist()
ll.addend(5)
ll.addend(6)
ll.disp()
ll.addend(55)
ll.addend(66)
ll.disp()
ll.delbeg()
ll.disp()
ll.delbeg()
ll.disp()




