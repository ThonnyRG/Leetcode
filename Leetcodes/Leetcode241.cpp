class Solution {
public:
    // Memoization map to store already computed results
    unordered_map<string, vector<int>> map;

    vector<int> diffWaysToCompute(string expression) {
        // Step 1: Check if the result for the current expression is already computed
        if (map.find(expression) != map.end()) {
            return map[expression];  // Return cached result
        }

        vector<int> result;

        // Step 2: Traverse the expression to find operators (+, -, *)
        for (int i = 0; i < expression.length(); i++) {
            char ch = expression[i];

            // Step 3: If the character is an operator, split the expression into left and right parts
            if (ch == '*' || ch == '+' || ch == '-') {
                // Recursive call to compute the result for the left sub-expression
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                
                // Recursive call to compute the result for the right sub-expression
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));

                // Step 4: Combine the results from left and right sub-expressions
                for (int l : left) {
                    for (int r : right) {
                        if (ch == '+') {
                            result.push_back(l + r);  // Add the results
                        } else if (ch == '-') {
                            result.push_back(l - r);  // Subtract the results
                        } else if (ch == '*') {
                            result.push_back(l * r);  // Multiply the results
                        }
                    }
                }
            }
        }

        // Step 5: Base case - If there were no operators, it means the expression is a single number
        if (result.empty()) {
            result.push_back(stoi(expression));  // Convert string to integer
        }

        // Step 6: Store the result in the map to avoid redundant computation
        map[expression] = result;

        // Step 7: Return the final computed result
        return result;
    }
};