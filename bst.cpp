/*
Prouty Robert
rprouty
bst.cpp
*/
#include "bst.h"
#include <queue>
using namespace std;
bool Bst::insert(string str, Node *&cur_root){
  //if the root is null insert
  //empty tree
  //has reached the end of a branch
  if(cur_root == NULL){
    cur_root = new Node(str);
    return true;
  }
  else if(cur_root->m_value == str){
    return false;
  }
  else{
    //return insert(str, cur_root->m_left);
    //if the alpha numeric value being put in is less than the current m_root
    // go left
    //if larger go right
    //if they are the same they fail to insert
    if(cur_root->m_value > str){
      return insert(str, cur_root->m_left);
    }
    else{
      return insert(str, cur_root->m_right);
    }
  }
}

int Bst::size(Node *&cur_root){
  if(cur_root == NULL){
    return 0;
  }
  //if cur not null return one plus everythingon the left and everything on the right
  return 1 + size(cur_root->m_left) + size(cur_root->m_left);
}

bool Bst::find(string str, Node *&cur_root){
  // the string was not found
  if(cur_root == NULL){
    return false;
  }
  // the root is the string
  else if(cur_root->m_value == str){
    return true;
  }
  else{
    if(str < cur_root->m_value){
      return find(str, cur_root->m_left);
    }
    else{
      return find(str, cur_root->m_right);
    }
  }
}

void Bst::print(Node *&cur_root){
  if(cur_root == NULL){
    return;
  }
  // first go left
  print(cur_root->m_left);
  //print the data
  cout << cur_root->m_value << ", ";
  //then go right
  print(cur_root->m_right);
}

void Bst::breadth(Node *&cur_root){
  //base
  if(cur_root == NULL){
    return;
  }
  //stl queue
  queue<Node *> q;
  q.push(cur_root);
  while(queue.empty() == false){
    Node *q_front = q.front();
    cout << q_front->m_value << ", ";
    q.pop();

    if(q_front->m_left != NULL){
      q.push(q_front->m_left);
    }

    if(q_front->m_right != NULL){
      q.push(q_front->m_right);
    }
  }
}

void Bst::helper(int depth, int &num, int &tot_depth, Node *&cur_root){
  if(cur_root == NULL){
    return;
  }
   helper(depth + 1, num + 1, depth + tot_depth, cur_root->m_left);
   helper(depth + 1, num + 1, depth + tot_depth, cur_root->m_right);
}

void Bst::distance(Node *&cur_root){
  int n = 0;
  int num_1 = 0;
  int num_2 = 0;
  int avg_dist;
  helper(n, num_1, num_2, cur_root);
  avg_dist = (num_2 / num_1);
  cout << avg_dist;
}
