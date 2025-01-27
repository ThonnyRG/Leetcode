class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adjacencyList(numCourses, vector<int>(0, 0));
        int sizeOfprerequisites = prerequisites.size();

        for(int i = 0; i < sizeOfprerequisites; i++) {
            adjacencyList[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<bool> answer;
        int sizeOfqueries = queries.size();

        for(int i = 0; i < sizeOfqueries; i++) {
            int courseInQuestion = queries[i][1], potentialPrerequisite = queries[i][0];
            vector<bool> visited(numCourses, false);
            queue<int> bfs;
            bfs.push(courseInQuestion);
            visited[courseInQuestion] = true;
            bool prerequisiteFound = false;

            while(bfs.size()) {
                int currentCourse = bfs.front();
                bfs.pop();

                for(int prerequisiteCourse: adjacencyList[currentCourse]) {
                    if(prerequisiteCourse == potentialPrerequisite) {
                        prerequisiteFound = true;
                        break;
                    }
                    if(!visited[prerequisiteCourse]) {
                        visited[prerequisiteCourse] = true;
                        bfs.push(prerequisiteCourse);
                    }
                }
            }

            answer.push_back(prerequisiteFound);
        }

        return answer;
    }
};