#pragma once
#pragma once
#include <iostream>

using namespace std;

struct T {
	int id;
};

struct node {
	T data;
	node *left;
	node *right;
};

class Tree
{
public:
	int veiksmai;
private:
	node* root;
	int level;

	void treeDelete(node* _t) {
		if (_t == NULL)
			return;
		if (_t->left != NULL)
			treeDelete(_t->left);
		if (_t->right != NULL)
			treeDelete(_t->right);
		delete _t;
	}

	void add1(T &_data, node* &_root) {
		if (_root != NULL)
			if (_data.id < _root->data.id)
				add1(_data, _root->left);
			else
				add1(_data, _root->right);
		else {
			_root = new node;
			_root->data = _data;
			_root->left = NULL;
			_root->right = NULL;
		}
	}

	void add2(T &_data, node* &_root) {
		node** newnode;
		newnode = &_root;
		while ((*newnode) != NULL) {
			if (_data.id < (*newnode)->data.id)
				newnode = &(*newnode)->left;
			else
				newnode = &(*newnode)->right;
		}
		(*newnode) = new node;
		(*newnode)->data = _data;
		(*newnode)->left = NULL;
		(*newnode)->right = NULL;
	}
	node* find1(int _id, node* _root) {
		if (_root != NULL) {
			veiksmai++;
			if (_id == _root->data.id)
				return _root;
			else {
				veiksmai++;
				if (_id < _root->data.id)
					return find1(_id, _root->left);
				else
					return find1(_id, _root->right);
			}
		}
		return NULL;
	}

	node* find2(int _id, node* _root) {
		while (_root != NULL) {
			if (_id == _root->data.id)
				return _root;
			if (_id < _root->data.id)
				_root = _root->left;
			else
				_root = _root->right;
		}
		return NULL;
	}

	void printPrefix(node* _root) {
		if (_root != NULL) {
			cout << _root->data.id << "(" << level << ") , ";
			++level;
			printPrefix(_root->left);
			printPrefix(_root->right);
			--level;
		}
	}

	void printInfix(node* _root) {
		if (_root != NULL) {
			++level;
			printInfix(_root->left);
			--level;
			cout << _root->data.id << "(" << level << ") , ";
			++level;
			printInfix(_root->right);
			--level;
		}
	}

	void printPostfix(node* _root) {
		if (_root != NULL) {
			++level;
			printPostfix(_root->left);
			printPostfix(_root->right);
			--level;
			cout << _root->data.id << "(" << level << ") , ";
		}
	}

public:
	Tree() {
		root = NULL;
		level = veiksmai = 0;
	}

	~Tree() {
		treeDelete(root);
		root = NULL;
	}

	void insert(T &_data) {
		add1(_data, root);
	}

	node* find(int _id) {
		node *_root = root;
		return find1(_id, _root);
	}

	bool remove(int _id) {
		node** tt = &root;
		while ((*tt) != NULL) {
			if (_id == (*tt)->data.id)
				break;
			if (_id < (*tt)->data.id) {
				tt = &(*tt)->left;
			}
			else {
				tt = &(*tt)->right;
			}
		}
		if ((*tt) == NULL) {
			return false;
		}

		node* q;
		if ((*tt)->left == NULL && (*tt)->right == NULL) {
			q = *tt;
			*tt = NULL;
		}
		else {
			node *t = (*tt);
			if (t->left == NULL) {
				q = t->right;
				*t = *t->right;
			}
			else if (t->right == NULL) {
				q = t->left;
				*t = *t->left;
			}
			else {
				node** _root = &t->right;
				while ((*_root)->left != NULL) {
					_root = &(*_root)->left;
				}
				t->data = (*_root)->data;
				q = (*_root);
				*_root = (*_root)->right;
			}
		}
		delete q;
	}

	void printPrefix() {
		printPrefix(root);
	}

	void printInfix() {
		printInfix(root);
	}

	void printPostfix() {
		printPostfix(root);
	}
};