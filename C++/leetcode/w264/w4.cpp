#include <iostream>
#include <vector>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    bool isMaxOrMin(int leftVal, ListNode* p)
    {
        int midVal = p->val;
        int rightVal = p->next->val;
        if (midVal > rightVal && midVal > leftVal) {
            return true;
        } else if (midVal < rightVal && midVal < leftVal) {
            return true;
        } else {
            return false;
        }
    }
    vector<int> nodesBetweenCriticalPoints(ListNode* head)
    {
        vector<int> locations;
        vector<int> rtn;
        ListNode* temp = head->next;
        int location = 2;
        while(temp != nullptr && temp->next != nullptr) {
            // is MAX OR MIN
            if (isMaxOrMin(head->val,temp)) {
                locations.push_back(location);
            }
            locaton++;
            header = header->next;
            temp = temp->next;
        }
        if (locations.size() < 2) {
            rtn = {-1, -1};
            return rtn;
        }
        // all node location
        int minDistance = locations[1] - locations[0];
        for (int i = 1; i < locations.size() - 1; i++) {
            if (locations[i + 1] - locations[i] < minDistance) {
                minDistance = locations[i + 1] - locations[i];
            }
        }
        rtn.push_back(minDistance);
        rtn.push_back(locations[locations.size() - 1] - locations[0]);
        return rtn;
        // get min and max, add to rtn
    }
};