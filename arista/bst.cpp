#include <bits/stdc++.h>

template<typename T,typename V>
struct Pair {
    T first;
    V second;
};

template<typename T>
class Bst {
    public:
        using value_type = T;
    private:
        value_type value{};
        Bst* left = nullptr;
        Bst* right = nullptr;
    public:
        Bst() {}
        Bst(value_type val) : value{val} {}
        Bst(value_type val,Bst* lft,Bst& rht) : value{val},left{lft},right{rht}{}
        
        bool Insert(value_type val) {
            bool ret = false;
            Bst* temp = this;
            while(nullptr != temp) {
                if(temp->value == val) return ret | false;
                if(val < temp->value) {
                    if(ret |= temp->left == nullptr)
                        temp->left = new Bst(val);
                    temp = temp->left;
                }else {
                    if(ret |= temp->right == nullptr)
                        temp->right = new Bst(val);
                    temp = temp->right;
                }
            }
        }

        bool Insert(value_type val) {
            if(val == value) return false;
            if(val < value && this->left != nullptr) 
                return this->left->Insert(val);
            if(val > value  && this->right != nullptr)
                return this->right->Insert(val);

            if(val < value) {
                this->left = new Bst(val);
                return true;
            }
            this->right = new Bst(val);
            return true;
        }
    
};

int main() {

}