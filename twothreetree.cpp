#include "twothreetree.h"
#include <iostream>
TwoThreeTree::TwoThreeTree()
{
root=nullptr;
}

TwoThreeNode* TwoThreeTree::split(TwoThreeNode* item){
 if (item->getSize() < 3) return item;

TwoThreeNode *x = new TwoThreeNode(item->key[0], item->first, item->second, nullptr, nullptr, item->parent);
TwoThreeNode *y = new TwoThreeNode(item->key[2], item->third, item->fourth, nullptr, nullptr, item->parent);
if (x->first){
    x->first->parent = x;
}
if (x->second){
x->second->parent = x;
    }
if (y->first){
y->first->parent = y;
    }
if (y->second){
y->second->parent = y;
}

if (item->parent) {
    item->parent->insert(item->key[1]);
    if (item->parent->first == item) item->parent->first = nullptr;
        else if (item->parent->second == item) item->parent->second = nullptr;
        else if (item->parent->third == item) item->parent->third = nullptr;

        if (item->parent->first == nullptr) {
            item->parent->fourth = item->parent->third;
            item->parent->third = item->parent->second;
            item->parent->second = y;
            item->parent->first = x;
        } else if (item->parent->second == nullptr) {
            item->parent->fourth = item->parent->third;
            item->parent->third = y;
            item->parent->second = x;
        } else {
            item->parent->fourth = y;
            item->parent->third = x;
        }

        TwoThreeNode *tmp = item->parent;
        delete item;
        return tmp;
    } else {
        x->parent = item;
        y->parent = item;
        item->Convert2TwoThreeNode(item->key[1], x, y);
        return item;
    }
}
TwoThreeNode* TwoThreeTree::insert(TwoThreeNode* r,int elem){
if(!root){
    return new TwoThreeNode(elem);
}
if(r->is_leaf()){
    r->insert(elem);
}
else if((elem==r->key[0])||(elem<r->key[0])){
    this->insert(r->first,elem);
}
else if ((r->getSize()==1)||((r->getSize()==2) && (elem < r->key[1])||(elem==r->key[1]))) {
        insert(r->second, elem);
}
else {
    insert(r->third, elem);
}
return split(r);
}
void  TwoThreeTree::insert(int elem){
this->root=this->insert(this->root,elem);
}
TwoThreeNode* TwoThreeTree::search(TwoThreeNode* r,int k){
    if (!r)
    {
    return nullptr;
    }

    if (r->find(k)) {
return r;
    }
    else if (k < r->key[0]) {
return search(r->first, k);
}
    else if ((r->getSize() == 2) && (k < r->key[1]) || (r->getSize() == 1)) {
return search(r->second, k);
    }
    else if (r->getSize() == 2){
return search(r->third, k);
    }
}
TwoThreeNode * TwoThreeTree::search_min(TwoThreeNode *p) {
    if (!p) return p;
    if (!(p->first)) return p;
    else return search_min(p->first);
}
TwoThreeNode* TwoThreeTree::redistribute(TwoThreeNode *leaf) {
    TwoThreeNode *parent = leaf->parent;
    TwoThreeNode *first = parent->first;
    TwoThreeNode *second = parent->second;
    TwoThreeNode *third = parent->third;

    if ((parent->getSize() == 2) && (first->getSize() < 2) && (second->getSize() < 2) && (third->getSize() < 2)) {
        if (first == leaf) {
            parent->first=parent->second;
            parent->second=parent->third;
            parent->third=nullptr;
            parent->first->insert(parent->key[0]);
            parent->first->third = parent->first->second;
            parent->first->second = parent->first->first;

            if (leaf->first!=nullptr) {
    parent->first->first = leaf->first;
            }
            else if (leaf->second!=nullptr) {
        parent->first->first = leaf->second;
            }

            if (parent->first->first!=nullptr){
            parent->first->first->parent = parent->first;
            }
            parent->remove(parent->key[0]);
            delete first;
        }
        else if (second==leaf) {
            first->insert(parent->key[0]);
            parent->remove(parent->key[0]);
            if (leaf->first != nullptr) {
            first->third = leaf->first;
            }
            else if (leaf->second != nullptr) {
            first->third = leaf->second;
            }
            if (first->third != nullptr) {
            first->third->parent = first;
            }
            parent->second = parent->third;
            parent->third = nullptr;

            delete second;
        } else if (third == leaf) {
            second->insert(parent->key[1]);
            parent->third=nullptr;
            parent->remove(parent->key[1]);
            if (leaf->first != nullptr) second->third = leaf->first;
            else if (leaf->second != nullptr) second->third = leaf->second;

            if (second->third != nullptr)  second->third->parent = second;

            delete third;
        }
    } else if ((parent->getSize() == 2) && ((first->getSize() == 2) || (second->getSize() == 2) || (third->getSize() == 2))) {
        if (third == leaf) {
            if (leaf->first != nullptr) {
                leaf->second = leaf->first;
                leaf->first = nullptr;
            }

            leaf->insert(parent->key[1]);
            if (second->getSize() == 2) {
                parent->key[1] = second->key[1];
                second->remove(second->key[1]);
                leaf->first = second->third;
                second->third = nullptr;
                if (leaf->first != nullptr) leaf->first->parent = leaf;
            } else if (first->getSize() == 2) {
                parent->key[1] = second->key[0];
                leaf->first = second->second;
                second->second = second->first;
                if (leaf->first != nullptr) leaf->first->parent = leaf;

                second->key[0] = parent->key[0];
                parent->key[0] = first->key[1];
                first->remove(first->key[1]);
                second->first = first->third;
                if (second->first != nullptr) second->first->parent = second;
                first->third = nullptr;
            }
        } else if (second == leaf) {
            if (third->getSize() == 2) {
                if (leaf->first == nullptr) {
                    leaf->first = leaf->second;
                    leaf->second = nullptr;
                }
                second->insert(parent->key[1]);
                parent->key[1] = third->key[0];
                third->remove(third->key[0]);
                second->second = third->first;
                if (second->second != nullptr) second->second->parent = second;
                third->first = third->second;
                third->second = third->third;
                third->third = nullptr;
            } else if (first->getSize() == 2) {
                if (leaf->second == nullptr) {
                    leaf->second = leaf->first;
                    leaf->first = nullptr;
                }
                second->insert(parent->key[0]);
                parent->key[0] = first->key[1];
                first->remove(first->key[1]);
                second->first = first->third;
                if (second->first != nullptr) second->first->parent = second;
                first->third = nullptr;
            }
        } else if (first == leaf) {
            if (leaf->first == nullptr) {
                leaf->first = leaf->second;
                leaf->second = nullptr;
            }
            first->insert(parent->key[0]);
            if (second->getSize() == 2) {
                parent->key[0] = second->key[0];
                second->remove(second->key[0]);
                first->second = second->first;
                if (first->second != nullptr) first->second->parent = first;
                second->first = second->second;
                second->second = second->third;
                second->third = nullptr;
            } else if (third->getSize() == 2) {
                parent->key[0] = second->key[0];
                second->key[0] = parent->key[1];
                parent->key[1] = third->key[0];
                third->remove(third->key[0]);
                first->second = second->first;
                if (first->second != nullptr) first->second->parent = first;
                second->first = second->second;
                second->second = third->first;
                if (second->second != nullptr) second->second->parent = second;
                third->first = third->second;
                third->second = third->third;
                third->third = nullptr;
            }
        }
    } else if (parent->getSize() == 1) {
        leaf->insert(parent->key[0]);

        if (first == leaf && second->getSize() == 2) {
            parent->key[0] = second->key[0];
            second->remove(second->key[0]);

            if (leaf->first == nullptr) leaf->first = leaf->second;

            leaf->second = second->first;
            second->first = second->second;
            second->second = second->third;
            second->third = nullptr;
            if (leaf->second != nullptr) leaf->second->parent = leaf;
        } else if (second == leaf && first->getSize() == 2) {
            parent->key[0] = first->key[1];
            first->remove(first->key[1]);

            if (leaf->second == nullptr) leaf->second = leaf->first;

            leaf->first = first->third;
            first->third = nullptr;
            if (leaf->first != nullptr) leaf->first->parent = leaf;
        }
    }
    return parent;
}
TwoThreeNode* TwoThreeTree::merge(TwoThreeNode *leaf) {
TwoThreeNode *parent = leaf->parent;

    if (parent->first == leaf) {
        parent->second->insert(parent->key[0]);
        parent->second->third = parent->second->second;
        parent->second->second = parent->second->first;

        if (leaf->first != nullptr) {
        parent->second->first = leaf->first;
        }
        else if (leaf->second != nullptr) {
        parent->second->first = leaf->second;
        }
        if (parent->second->first != nullptr){
        parent->second->first->parent = parent->second;
        }
        parent->remove(parent->key[0]);
        delete parent->first;
        parent->first = nullptr;
    } else if (parent->second == leaf) {
        parent->first->insert(parent->key[0]);

        if (leaf->first != nullptr){
        parent->first->third = leaf->first;
        }
        else if (leaf->second != nullptr){
        parent->first->third = leaf->second;
        }
        if (parent->first->third != nullptr){
        parent->first->third->parent = parent->first;
        }
        parent->remove(parent->key[0]);
        delete parent->second;
        parent->second = nullptr;
    }

    if (parent->parent == nullptr) {
        TwoThreeNode *tmp = nullptr;
        if (parent->first != nullptr) {
        tmp = parent->first;
        }
        else{
        tmp = parent->second;
        }
        tmp->parent = nullptr;
        delete parent;
        return tmp;
    }
    return parent;
}
TwoThreeNode* TwoThreeTree::fix(TwoThreeNode* leaf){
  if (leaf->getSize() == 0&&leaf->parent==nullptr) {
        delete leaf;
        return nullptr;
    }
    if (leaf->getSize()!=0) {
        if (leaf->parent) return fix(leaf->parent);
        else return leaf;
    }

    TwoThreeNode *parent = leaf->parent;
    if (parent->first->getSize() == 2 || parent->second->getSize() == 2 || parent->getSize() == 2) {
leaf = redistribute(leaf);
    }
    else if ((parent->getSize() == 2)&&(parent->third->getSize() == 2)) {
leaf=redistribute(leaf);
}
    else {
leaf=merge(leaf);
}

    return fix(leaf);
}
TwoThreeNode* TwoThreeTree::remove(TwoThreeNode* r,int elem){
TwoThreeNode* temp=this->search(r,elem);
if(!temp){
    return r;
}
TwoThreeNode* min=nullptr;
if(temp->key[0]==elem){
    min=this->search_min(temp->second);
}
else{
    min=this->search_min(temp->third);
}
int z;
if(min){
    if(elem==temp->key[0]){
        int &z=temp->key[0];
    }
    else{
        int &z=temp->key[1];
    }
    std::swap(z,min->key[0]);
    temp=min;
}
temp->remove(elem);
return fix(temp);
}
void TwoThreeTree::remove(int elem){
this->remove(this->root,elem);
}

TwoThreeNode* TwoThreeTree::search(int k){
return this->search(this->root,k);
}

