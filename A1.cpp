#include<iostream>
using namespace std;
class node
{
  int data;
  node* lchild;
  node* rchild;
public:
  node()
  {
    data = 0;
    lchild = NULL;
    rchild = NULL;
  }
  node(int x)
  {
    data = x;
    lchild = NULL;
    rchild = NULL;
  }
  friend class tree;
};

class tree
{
  node* root;
public:
  tree()
  {
    root = NULL;
  }
  void create(int x);
  node* insert(node* t, int x);
  void insertNode(int x);
  void Postorder(node* p);
  void displayPostorder();
  void Preorder(node* p);
  void displayPreorder();
  void Inorder(node* p);
  void displayInorder();
  node* mirror(node*);
  void callMirror();
  int calHeight(node* t);
  void height();
  void postNonrecursive();
  void preNonrecursive();
  void inNonrecursive();
  void deleteAll();
  void deleteNode(node* p);
  void countLeaf();
  int returnLeaf(node* p, int cnt);
  void countNode();
  int returnNode(node* p);
  void operator =(tree& obj)
  {
	  root = copy(obj.root);
  }
  node* copy(node* p)
  {
	  if(p == NULL)
	  {
		  return NULL;
	  }
	  node* a = new node();
	  	a->data = p->data;
	  	a->lchild = copy(p->lchild);
	  	a->rchild = copy(p->rchild);
	  	return a;
  }
};
class stack
{
	int top;
	node* t[40];
public:
	stack()
{
		top = -1;
}
	void push(node* a)
	{
		t[++top] = a;
	}
	node* pop()
	{
		return t[top--];
	}
	bool isempty()
	{
		if(top == -1)
			return true;
		else
			return false;
	}
	friend class tree;
};
void tree::postNonrecursive()
{
	stack s;
	node* temp = root;
	node* flag = new node();
	flag->data = -1;
	do
	{
		while(temp!= NULL)
		{
			s.push(temp);
			temp = temp->lchild;
		}
		temp = s.pop();
		while(temp->data == -1 && !s.isempty())
		{
			temp = s.pop();
			cout<<temp->data<<"\t";
			if(s.isempty())
				return;
			temp = s.pop();
		}
		s.push(temp);
		s.push(flag);
		temp = temp->rchild;
	}while(!s.isempty());

}
void tree::preNonrecursive()
{
	stack s;
	node* temp = root;
	while(true)
	{
		while(temp!=NULL)
		{
			s.push(temp);
			cout<<temp->data<<"\t";
			temp = temp->lchild;
		}
		if(s.isempty())
		{
			break;
		}
		temp = s.pop();
		temp = temp->rchild;
	}
	cout<<"\n";
}
void tree::create(int x)
{
  node* p;
  if(root == NULL)
  {
    p = new node(x);
    root = p;
  }
  else
  {
    cout<<"\ntree root is already created\n";
    insert(root, x);
  }
}
void tree::insertNode(int x)
{
	insert(root, x);
}
node* tree::insert(node* t, int x)
{
  node* p;
  char ans;
  if(t == NULL)
  {
    p = new node(x);
    return p;
  }
  else
  {
    cout<<"\ninsert on left or right?\n";
    cout<<"\n l for inserting left and r for inserting right\n"<<t->data<<"\n";
    cin>> ans;
    if(ans == 'l')
    {
      t->lchild = insert(t->lchild, x);
    }
    else{
      t->rchild = insert(t->rchild, x);
    }
  }
  return t;
}
void tree::Postorder( node* p)
{
     if (p == NULL)
        return;
     Postorder(p->lchild);

     Postorder(p->rchild);

     cout<<p->data<<"\t";
}
void tree::displayPostorder()
{
	if(root == NULL)
		cout<<"\nempty tree\n";
  Postorder(root);
}

void tree::deleteAll()
{
	deleteNode(root);
}
void tree::deleteNode(node* p)
{
	if(p == NULL) return;

	deleteNode(p->lchild);

	deleteNode(p->rchild);

	cout<<"\ndeleted node is:"<<p->data<<endl;
	delete p;

	root = NULL;
}
void tree::Preorder(node* p)
{
  if(p == NULL)
  return;
  cout<<p->data<<"\t";

  Preorder(p->lchild);

  Preorder(p->rchild);
}
void tree::displayPreorder()
{
	if(root == NULL)
		cout<<"\nempty tree\n";
  Preorder(root);
}

void tree::Inorder(node* p)
{
  if(p == NULL)
  return;
  Inorder(p->lchild);

  cout<<p->data<<"\t";

  Inorder(p->rchild);
}
void tree::displayInorder()
{
	if(root == NULL)
		cout<<"\nempty tree\n";
  Inorder(root);
}
node* tree::mirror(node* t)
{
	if(t == NULL)
	{
		return NULL;
	}
	node* a = new node();
	a->data = t->data;
	a->lchild = mirror(t->rchild);
	a->rchild = mirror(t->lchild);
	return a;
}
void tree::callMirror()
{
	node* m = mirror(root);
	cout<<"\ninorder traversal of mirror image of the binary tree is :\n";
	Inorder(m);
}
int tree::calHeight(node* t)
{
	if(t == NULL)
		return 0;
	if(t->lchild == NULL && t->rchild == NULL)
		return 0;
	int l = calHeight(t->lchild);
	int r = calHeight(t->rchild);
	if(l>r)
		return (l+1);
	else
		return r+1;
}
void tree::height()
{
	int h = calHeight(root);
	cout<<"\nthe height of the binary tree is:\t"<<h;
}
int tree::returnNode(node* t)
{
	if(t == NULL)
			return 0;
		if(t->lchild == NULL && t->rchild == NULL)
			return 1;
		int l = returnNode(t->lchild);
		int r = returnNode(t->rchild);
		return (l+r+1);
}
void tree::countNode()
{
	int count = returnNode(root);
	cout<<"\nno of nodes in the tree is:"<<count<<endl;
}
int tree::returnLeaf(node*p, int cnt)
{
	int cnt1, cnt2;
	if(p == NULL)
		return 0;
	if(p->lchild==NULL && p->rchild==NULL)
	{
		return (cnt+1);
	}
	else
	{
		cnt1 = returnLeaf(p->lchild, cnt1);
		cnt2 = returnLeaf(p->rchild, cnt2);
	}
	return (cnt1+cnt2);

}
void tree::countLeaf()
{
	int count = returnLeaf(root, 0);
	cout<<"\nno of leaf nodes int the tree is:"<<count<<endl;
}
int main()
{
  tree t, r;
  int i, e;
  do
  {
	  cout<<"\n1.create binary tree\n2.insert \n3.postorder traversal\n4.preorder traversal\n5.inorder traversal\n6.mirror image(inorder traversal)\n7.height of tree\n8.postorder traversal(non-recursive)\n9.preorder traversal(non-recursive)\n10.delete tree\n11.copy tree\n12.count leaf node\n";
	  cin>> i;
	  switch (i)
	  {
	  case 1:
		  cout<<"\ninsert data\n";
		  cin>> e;
		  t.create(e);
		  break;
	  case 2:
		  cout<<"\ninsert data\n";
		   cin>> e;
		   t.insertNode(e);
		   break;
	  case 3:
		  t.displayPostorder();
		  break;
	  case 4:
		  t.displayPreorder();
		  break;
	  case 5:
		  t.displayInorder();
		  break;
	  case 6:
		  t.callMirror();
		  break;
	  case 7:
		  t.height();
		  break;
	  case 8:
		  t.postNonrecursive();
		  break;
	  case 9:
		  t.preNonrecursive();
		  break;
	  case 10:
		  t.deleteAll();
		  break;
	  case 11:
		  r = t;
		  cout<<"\ndisplaying copied tree using postorder traversal\n";
		  r.displayPostorder();
		  break;
	  case 12:
		  t.countLeaf();
		  break;
	  }
	  cout<<"\nenter 1 to continue\n";
	  cin>> e;
  }while(e == 1);
  return 0;

}
/*
shreyas@shreyas:~$ cd 2416
shreyas@shreyas:~/2416$ g++ A1.cpp
shreyas@shreyas:~/2416$ ./a.out

1.create binary tree
2.insert 
3.postorder traversal
4.preorder traversal
5.inorder traversal
6.mirror image(inorder traversal)
7.height of tree
8.postorder traversal(non-recursive)
9.preorder traversal(non-recursive)
10.delete tree
11.copy tree
12.count leaf node
1

insert data
2

enter 1 to continue
1

1.create binary tree
2.insert 
3.postorder traversal
4.preorder traversal
5.inorder traversal
6.mirror image(inorder traversal)
7.height of tree
8.postorder traversal(non-recursive)
9.preorder traversal(non-recursive)
10.delete tree
11.copy tree
12.count leaf node
2

insert data
3

insert on left or right?

 l for inserting left and r for inserting right
2
l

enter 1 to continue
1

1.create binary tree
2.insert 
3.postorder traversal
4.preorder traversal
5.inorder traversal
6.mirror image(inorder traversal)
7.height of tree
8.postorder traversal(non-recursive)
9.preorder traversal(non-recursive)
10.delete tree
11.copy tree
12.count leaf node
2

insert data
6

insert on left or right?

 l for inserting left and r for inserting right
2
r

enter 1 to continue
1

1.create binary tree
2.insert 
3.postorder traversal
4.preorder traversal
5.inorder traversal
6.mirror image(inorder traversal)
7.height of tree
8.postorder traversal(non-recursive)
9.preorder traversal(non-recursive)
10.delete tree
11.copy tree
12.count leaf node
2

insert data
8

insert on left or right?

 l for inserting left and r for inserting right
2
l

insert on left or right?

 l for inserting left and r for inserting right
3
l

enter 1 to continue
1

1.create binary tree
2.insert 
3.postorder traversal
4.preorder traversal
5.inorder traversal
6.mirror image(inorder traversal)
7.height of tree
8.postorder traversal(non-recursive)
9.preorder traversal(non-recursive)
10.delete tree
11.copy tree
12.count leaf node
2

insert data
12

insert on left or right?

 l for inserting left and r for inserting right
2
r

insert on left or right?

 l for inserting left and r for inserting right
6
r

enter 1 to continue
1

1.create binary tree
2.insert 
3.postorder traversal
4.preorder traversal
5.inorder traversal
6.mirror image(inorder traversal)
7.height of tree
8.postorder traversal(non-recursive)
9.preorder traversal(non-recursive)
10.delete tree
11.copy tree
12.count leaf node
3
8	3	12	6	2	
enter 1 to continue
1

1.create binary tree
2.insert 
3.postorder traversal
4.preorder traversal
5.inorder traversal
6.mirror image(inorder traversal)
7.height of tree
8.postorder traversal(non-recursive)
9.preorder traversal(non-recursive)
10.delete tree
11.copy tree
12.count leaf node
4
2	3	8	6	12	
enter 1 to continue
1

1.create binary tree
2.insert 
3.postorder traversal
4.preorder traversal
5.inorder traversal
6.mirror image(inorder traversal)
7.height of tree
8.postorder traversal(non-recursive)
9.preorder traversal(non-recursive)
10.delete tree
11.copy tree
12.count leaf node
5
8	3	2	6	12	
enter 1 to continue
1

1.create binary tree
2.insert 
3.postorder traversal
4.preorder traversal
5.inorder traversal
6.mirror image(inorder traversal)
7.height of tree
8.postorder traversal(non-recursive)
9.preorder traversal(non-recursive)
10.delete tree
11.copy tree
12.count leaf node
6

inorder traversal of mirror image of the binary tree is :
12	6	2	3	8	
enter 1 to continue
1

1.create binary tree
2.insert 
3.postorder traversal
4.preorder traversal
5.inorder traversal
6.mirror image(inorder traversal)
7.height of tree
8.postorder traversal(non-recursive)
9.preorder traversal(non-recursive)
10.delete tree
11.copy tree
12.count leaf node
7

the height of the binary tree is:	2
enter 1 to continue
1

1.create binary tree
2.insert 
3.postorder traversal
4.preorder traversal
5.inorder traversal
6.mirror image(inorder traversal)
7.height of tree
8.postorder traversal(non-recursive)
9.preorder traversal(non-recursive)
10.delete tree
11.copy tree
12.count leaf node
12

no of leaf nodes int the tree is:3

enter 1 to continue
2
*/
