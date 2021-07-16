#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Codec {
public:
    Codec() {
        commands['('] = [this](const std::string& input,TreeNode*& root){
            decodeIdx++; // read '('
            
            // allocate a new node
            root = new TreeNode(0);
            // decode the value
            commands[input[decodeIdx]](input,root);

            // decode left and right
            commands[input[decodeIdx]](input,root->left);
            commands[input[decodeIdx]](input,root->right);
            commands[input[decodeIdx]](input,root);

            return 0;
        };

        commands['n'] = [this](const std::string& input,TreeNode*& root){
            decodeIdx++; // read ')'
            root = nullptr;
            return 0;
        };

        commands[')'] = [this](const std::string& input,TreeNode*& root){
            decodeIdx++; // read ')'
            // nothing more to do here
            return 0;
        };
        
        auto decodeDigit = [this](const std::string& input,TreeNode*& root) {
            std::string value;
            int sign = 1;
            if(input[decodeIdx] == '-') {
                sign = -1;
                decodeIdx++;
            }
            while(decodeIdx < input.size()) {
                char c = input[decodeIdx];
                bool notDigit = (c < 48 || c > 57);
                if(notDigit) {
                    break;
                }
                value.push_back(c);
                decodeIdx++;
            }
            root->val = std::stoi(value) * sign;
            return 0;
        };

        vector<char> v = {'-','0','1','2','3','4','5','6','7','8','9'};
        for(auto c : v) commands[c] = decodeDigit;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        std::string ans;
        if(root == nullptr) return std::string("n"); 
        ans += "(";
        ans += std::to_string(root->val);
        ans += serialize(root->left);
        ans += serialize(root->right);
        ans += ")";
        std::cout <<"serialize = "<<ans << std::endl;
        return ans;
    }

    TreeNode* __parse(const std::string& input) {
        TreeNode* root = nullptr;
        commands[input[decodeIdx]](input,root);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;
        decodeIdx = 0;
        TreeNode *root = __parse(data);
        return root;
    }

    int decodeIdx = 0;
    std::map<char,std::function<int(const std::string&,TreeNode*&)>> commands;
};


// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

#include <thread>
#include <mutex>

int main() {
    TreeNode root(1);
    root.left = nullptr;
    root.right = new TreeNode(2);


    Codec ser, deser;
    TreeNode* ans = deser.deserialize(ser.serialize(&root));

    std::cout << ans->val << std::endl;
    // std::cout << ans->left->val << std::endl;
    std::cout << ans->right->val << std::endl;
    // std::cout << ans->right->left->val << std::endl;

    std::unique_lock<mutex> locker();
    
}