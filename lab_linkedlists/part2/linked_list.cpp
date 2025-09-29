// linked_list.cc -- functions for linked_list lab (cs221)

#include "linked_list.h"

/**
 * Inserts a new Node (with key=newKey) at the head of the linked_list.
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty)
 * PRE: newKey is the value for the key in the new Node
 * POST: the new Node is now the head of the linked_list
 */
void insert(Node *&head, int newKey)
{
    Node *curr = new Node(newKey, head);
    head = curr;
}

/**
 * Print the keys of a linked_list in order, from head to tail
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty)
 */
void print(Node *head)
{
    std::cout << "[";
    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        std::cout << curr->key;
        if (curr->next != NULL)
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

/**
 * Returns the size (number of Nodes) of the linked_list
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty)
 */
int size(Node *head)
{
    if (!head) return 0;
    return 1 + size(head->next);
}

/**
 * Copies the keys in a linked list to a vector.
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty)
 * POST: a new vector<int> containing the keys in the correct order has been returned.
 */
std::vector<int> to_vector(Node *head)
{
    std::vector<int> result;
    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        result.push_back(curr->key);
    }
    return result;
}

/**
 * Delete the last Node in the linked_list
 * PRE: head is the first Node in a linked_list (if NULL, linked_list is empty)
 * POST: the last Node of the linked_list has been removed
 * POST: if the linked_list is now empty, head has been changed
 * POST: else head remains the first Node in the linked_list
 */
void delete_last_element(Node *&head)
{
    // ******** WRITE YOUR CODE HERE ********
    Node *current = head;
    if (current == NULL)
      return;
    if (current->next == NULL) {
      delete head;
      head = nullptr;
      return;
    }
    Node *last_node = current->next;
    while (last_node->next != NULL) {
      current = last_node;
      last_node = last_node->next;
    }
    current->next = nullptr;
    delete last_node;
    return;
}

/**
 * Removes an existing Node (with key=oldKey) from the linked_list.
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty)
 * PRE: oldKey is the value of the key in the Node to be removed
 * PRE: if no Node with key=oldKey exists, the linked_list has not changed
 * POST: if a Node with key=oldKey was found, then it was deleted
 * POST: other Nodes with key=oldKey might still be in the linked_list
 * POST: head is the new first Node of the linked_list, if updated
 */
void remove(Node *&head, int oldKey)
{
  Node *current = head;
  if (head == NULL)
    return;
  if (head->key == oldKey) {
    if (head->next != NULL) {
      head = head->next;
    } else {
      head = nullptr;
    }
    delete current;
    return;
  }
  Node* node_after_curr = current->next;
  while (node_after_curr != NULL) {
    if (node_after_curr->key == oldKey) {
      current->next = node_after_curr->next;
      delete node_after_curr;
      return;
    }
    current = node_after_curr;
    node_after_curr = node_after_curr->next;
  }
  return;
}

/**
 * Insert a new Node (with key=newKey) after an existing Node (with key=oldKey)
 * If there is no existing Node with key=oldKey, then no action.
 * PRE: head is the first Node in a linked_list (if NULL, linked_list is empty)
 * PRE: oldKey is the value to look for (in the key of an existing Node)
 * PRE: newKey is the value of the key in the new Node (that might be inserted)
 * POST: if no Node with key=oldKey was found, then the linked_list has not changed
 * POST: else a new Node (with key=newKey) is right after the Node with key = oldKey.
 */
void insert_after(Node *head, int oldKey, int newKey)
{
  Node *current = head;
  while (current != NULL) {
    if (current->key == oldKey) {
      Node* newNode = new Node(newKey, current->next);
      current->next = newNode;
      return;
    }
    current = current->next;
  }
  return;
}

/**
 * Create a new linked_list by merging two existing linked_lists.
 * PRE: list1 is the first Node in a linked_list (if NULL, then it is empty)
 * PRE: list2 is the first Node in another linked_list (if NULL, then it is empty)
 * POST: A new linked_list is returned that contains new Nodes with the keys from
 * the Nodes in list1 and list2, starting with the key of the first Node of list1,
 * then the key of the first Node of list2, etc.
 * When one list is exhausted, the remaining keys come from the other list.
 * For example: [1, 2] and [3, 4, 5] would return [1, 3, 2, 4, 5]
 */
Node *interleave(Node *list1, Node *list2)
{
  int list_to_add_from = 1;
  Node* heads[2] = {list1, list2};
  Node* newHead;
  Node* appendTo;
  if (list1 == NULL && list2 == NULL) {
    return nullptr;
  }
  if (list1 == NULL && list2 != NULL) {
    newHead = new Node(list2->key, nullptr);
    heads[1] = heads[1]->next;
    list_to_add_from = 1;
  } else {
    newHead = new Node(list1->key, nullptr);
    heads[0] = heads[0]->next;
    list_to_add_from = 1;
  }
  appendTo = newHead;
  while (heads[0] || heads[1]) {
    Node *&working_head = heads[list_to_add_from];
    if (!working_head) {
      list_to_add_from = !list_to_add_from;
      continue;
    }
    Node *newNode = new Node(working_head->key, NULL);
    appendTo->next = newNode;
    appendTo = newNode;
    working_head = working_head->next;
    list_to_add_from = !list_to_add_from;
  }
  return newHead;
}
