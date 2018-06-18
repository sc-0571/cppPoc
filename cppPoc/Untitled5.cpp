 #include<iostream>
#include<string>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

  
    
    TreeNode* buildChildTree(vector<int>& subPreorder, vector<int>& subInorder) {
        vector<int> lp, li;
        vector<int> rp, ri;
        if (subPreorder.size() == 0) {
            return NULL;
        }
        TreeNode* tree = new TreeNode(subPreorder.at(0));
        if(subPreorder.size() == 1) return tree;
        
        int i=0;
        while(subInorder.at(i) != subPreorder.at(0) && i < subInorder.size()) {
            li.push_back(subInorder.at(i));
            i++;
        }
        int j=0;
        while(j<i) {
            lp.push_back(subPreorder.at(j+1));
            j++;
        }
        tree->left = buildChildTree(lp, li);
        i++;
        j= i;
       //  cout << "i=" << i << endl;
        while(i<subPreorder.size()) {
            rp.push_back(subPreorder.at(i++));
        }
        
        while(j<subInorder.size()) {
            ri.push_back(subInorder.at(j++));
        }
        tree->right = buildChildTree(rp, ri);
        return tree;
    }
    
     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildChildTree(preorder, inorder);
    }
    
    void traverse(TreeNode* t) {
    	if (t ==  NULL) {
    		cout <<  "null  ";
    		return;
    	} 
    	if (t != NULL) {
    		cout << t->val << "  ";
    	} 
    	traverse(t->left);
    	traverse(t->right);
    }
    
int main5() {
	vector<int>  p;
	vector<int>  i;
	p.push_back(1);  p.push_back(2); p.push_back(3);
	i.push_back(1);  i.push_back(3); i.push_back(2);
	
	TreeNode* node = buildTree(p, i);
	
    traverse(node);

	
}
