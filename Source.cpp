//CODE TO SHOW A BINARY TREE WITH ITS INORDER, PREORDER, POSTORDER ALONG WITH ITS LEVEL.
//FIND NO. OF LEAF NODE, NODES WITH ONE CHILD, NODES WITH 2 CHILD, MAXIMUM LEVEL, MINIMUM LEVEL.
//FIND WETHER THE TREE IS BALANCED OR NOT.
// NIRAV PARDIWALA
// 10/06-12/06

#include <iostream>
using namespace std;
const int nil = 0;
int level_count = -1;//counter to find the levels of node for inorder, preorder and postorder.
class treenode_type
{
public:
	int info;
	treenode_type *left;
	treenode_type *right;
};
void setleft(int x);
void setright(int x);
void inorder(treenode_type *p);
void preorder(treenode_type *p);
void postorder(treenode_type *p);
int getleaves(treenode_type *p, int& count);
int onechild(treenode_type *p, int& count);
int twochild(treenode_type *p, int& count);
int maxlevel(treenode_type *p);
int minlevel(treenode_type *p);
void balanced(int result);
treenode_type *p, *q, *root;
int number;
int result;
int node_count = 1;
void main()
{
	int count = 0;//count the total number of nodes.
	cout << "Enter new value:\n";
	cin >> number;
	root = new treenode_type;
	(*root).info = number;
	(*root).left = nil;
	(*root).right = nil;
	cout << (*root).info << " is the ROOT.\n";
	cout << "Enter value for other nodes or -999 to end:\n";
	cin >> number;
	while (number != -999)
	{
		node_count++;
		p = root;
		q = p;
		while ((number != (*p).info) && (q != nil))
		{
			p = q;

			if (number < (*p).info)
			{
				q = (*p).left;				
			}
			else
			{
				q = (*p).right;
			}
		}
		if (number == (*p).info)
		{
			node_count--;
			cout << number << "  is already used.\n";
		}
		else if (number < (*p).info)
		{
			setleft(number);
			cout << number << " is a left child of " << (*p).info << endl;
		}
		else
		{
			setright(number);
			cout << number << " is a right child of " << (*p).info << endl;
		}
		cin >> number;
	}
//inorder list of the tree
	cout << "----------\n";
	cout << "INORDER :\n";
	cout << "----------\n";
	p = root;
	inorder(p);
	cout << endl;
//preorder list of the tree
	cout << "----------\n";
	cout << "PRE-ORDER :\n";
	cout << "----------\n";
	p = root;
	preorder(p);
	cout << endl;
//postorder list of the tree
	cout << "----------\n";
	cout << "POST-ORDER :\n";
	cout << "----------\n";
	p = root;
	postorder(p);
	count = 0;
	cout << endl;
//total no. of nodes in the tree.
	cout << "Total No. of nodes = " << node_count << endl;
//no. of leaves or nodes with no children in the tree.
	cout << "Total number of leaves in the tree: " << getleaves(p, count) << endl;
	count = 0;
//no. of leaves with exactly one child.
	cout << "Total number of leaves with one CHILD: " << onechild(p, count) << endl;
	count = 0;
//no. of nodes with two children or Max no. of node in the last level.
	cout << "Total number of leaves with two CHILDREN: " << twochild(p, count) << endl;
	count = 0;
//Maximum level.
	cout << "Maximum Level: " << maxlevel(p) - 1 << endl;
	count = 0;
//Minimum level.
	cout << "Minimum Level: " << minlevel(p) - 1 << endl;
	cout << endl;
//tree is balnced or not.
	balanced(result);

	system("PAUSE");
}
//ALL FUNCTIONS ARE GIVEN BELOW.
void setleft(int x)
{
	treenode_type *q;
	q = new treenode_type;
	(*q).info = x;
	(*q).left = nil;
	(*q).right = nil;
	(*p).left = q;
	  
	}
void setright(int x)
{
	treenode_type *q;
	q = new treenode_type;
	(*q).info = x;
	(*q).left = nil;
	(*q).right = nil;
	(*p).right = q;
}
void inorder(treenode_type *r)
{
	if (r != nil)
	{
		level_count++;
		inorder((*r).left);
		cout << (*r).info << " At level: " << level_count << endl;
		inorder((*r).right);
		level_count--;
	}
}
void preorder(treenode_type *r)
{
	if (r != nil)
	{
		level_count++;
		cout << (*r).info << " At level: " << level_count << endl;
		inorder((*r).left);
		inorder((*r).right);
		level_count--;
	}
}
void postorder(treenode_type *r)
{
	if (r != nil)
	{
		level_count++;
		inorder((*r).left);
		inorder((*r).right);
		cout << (*r).info << " At level: " << level_count << endl;
		level_count--;
	}
}
int getleaves(treenode_type *r, int& count)
{
	if (r != nil)    
	{
		if (((*r).left == nil) && ((*r).right == nil))
		{
			count++;
		}
		getleaves((*r).left, count);
		getleaves((*r).right, count);

	}
	return count;
}
int onechild(treenode_type *r, int& count)
{
	if (r != nil)
	{
		if (((*r).left == nil) || ((*r).right == nil))
		{
			count++;
		}
		if (((*r).left == nil) && ((*r).right == nil))
		{
			count--;
		}
		onechild((*r).left, count);
		onechild((*r).right, count);
	}
	return count;
}
int twochild(treenode_type *r, int& count)
{
	if (r != nil)
	{
		if (((*r).left == nil) && ((*r).right == nil))
		{
			count++;
		}
		twochild((*r).left, count);
		twochild((*r).right, count);
	}
	return count - 1;
}
int maxlevel(treenode_type *r)
{
	if (r == nil)
	{
		return 0;
	}
	else
	{
		int levell, levelr;
		levell = maxlevel((*r).left);
		levelr = maxlevel((*r).right);
		if (levelr > levelr)
		{
			return levell + 1;
		}
		else
		{
			return levelr + 1;
		}
	}
}

int minlevel(treenode_type *r)
{
	if (r == nil)
	{
		return 0;
	}
	if ((*r).left == nil && ((*r).right == nil))
	{
		return 1;
	}

	if ((*r).left == nil)
	{
		return minlevel((*r).right) + 1;
	}
	if ((*r).right == nil)
	{
		return minlevel((*r).left) + 1;
	}
	int levell, levelr;
	levell = minlevel((*r).left);
	levelr = minlevel((*r).right);
	if (levell > levelr)
	{
		return levell + 1;
	}
	else
	{
		return levelr + 1;
	}
}

void balanced(int result)
{
	result = log2(node_count);
	if ((minlevel(p) - 1) == result)
	{
		cout << "It is a BALANCED TREE.\n";
	}
	else
	{
		cout << "It is NOT a BALANCED TREE.\n";
	}
}
// NIRAV PARDIWALA
// 10/06-12/06