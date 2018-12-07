/*
Prouty Robert
rprouty
bst.h
*/
#ifndef BST_H
#define BST_H
#include <iostream>
#include <vector>
#include <string>
class Bst{
  private:
    class Node{
      public:
        Node* m_left;
        Node* m_right;
        string m_value;
        Node(string value, Node* left = NULL, Node* right = NULL){
          m_left = left;
          m_right = right;
          m_value = vale;
        }
    };
    Node* m_root = NULL;
    bool insert(string str, Node *&cur_root);
    int size(Node *&cur_root);
    bool find(string str, Node *&cur_root);
    void print(Node *&cur_root);
    void breadth(Node *&cur_root);
    void helper(int depth, int &num, int &tot_depth, Node *&cur_root);
    void distance(Node *&cur_root);


  public:
    bool insert(string str){return insert(str, m_root);}
    int size(){return size(m_root);}
    bool find(string str){return find(str, m_root);}
    void print(){return print(m_root);}
    void breadth(){return breadth(m_root);}
    void helper(int depth, int &num, int &tot_depth){return helper(depth, num, tot_depth, m_root);}
    void distance(){return distance(m_root);}


};
#endif
