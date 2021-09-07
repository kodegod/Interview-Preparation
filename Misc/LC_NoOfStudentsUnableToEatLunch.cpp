//https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/

class Solution {
public:
    void rotatebyleft(vector<int>&v)
    {
        int x = v[0];
        for(int i=0; i<v.size()-1; i++)
            v[i] = v[i+1];
        v[v.size()-1] = x;
    }
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        while(1)
        {
            int cnt = 0;
            while(students[0] != sandwiches[0])
            {
                rotatebyleft(students);
                cnt++;
                if(cnt == students.size())
                    return students.size();
            }
            students.erase(students.begin());
            sandwiches.erase(sandwiches.begin());
            if(students.size() == 0)
                return 0;
        }
        return 0;
    }
};

