class Solution {
public:
    // Function to perform level order traversal and return nodes as a vector of vectors
    vector<vector<int>> levelOrderTraversal(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result; // Return empty result if the tree is empty
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size(); // Number of nodes at the current level
            vector<int> currentLevel;  // Vector to store current level nodes

            for (int i = 0; i < levelSize; i++) {
                TreeNode* current = q.front();
                q.pop();
                currentLevel.push_back(current->val); // Store the current node's data

                // Push left and right children into the queue
                if (current->left != nullptr) {
                    q.push(current->left);
                }
                if (current->right != nullptr) {
                    q.push(current->right);
                }
            }
            result.push_back(currentLevel); // Add current level to the result
        }
        return result;
    }

    // Function to compare two vectors of vectors
    bool areVectorsEqual(const vector<vector<int>>& vec1, const vector<vector<int>>& vec2) {
        // Check if sizes are equal
        if (vec1.size() != vec2.size()) {
            return false;
        }

        // Compare each inner vector
        for (size_t i = 0; i < vec1.size(); ++i) {
            // Sort both inner vectors to compare their elements regardless of order
            vector<int> sortedVec1 = vec1[i];
            vector<int> sortedVec2 = vec2[i];

            sort(sortedVec1.begin(), sortedVec1.end());
            sort(sortedVec2.begin(), sortedVec2.end());

            // Compare sorted inner vectors
            if (sortedVec1 != sortedVec2) {
                return false; // Return false if any inner vectors do not match
            }
        }

        return true; // Return true if all inner vectors match
    }

    // Function to check if two trees are flip equivalent
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        // Base case: both trees are empty
        if (root1 == nullptr && root2 == nullptr) return true;
        // If one of them is null and the other is not
        if (root1 == nullptr || root2 == nullptr) return false;

        // If values are equal, check both possibilities (flip or not)
        return (root1->val == root2->val) &&
               (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right) || 
                flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
    }
};
