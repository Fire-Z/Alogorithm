#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr && list2 == nullptr)
        {
            return nullptr;
        }
        else if (list1 == nullptr && list2 != nullptr)
        {
            return list2;
        }
        else if (list1 != nullptr && list2 == nullptr)
        {
            return list1;
        }
        else
        {
            ListNode *head = nullptr;
            ListNode *L = nullptr;
            if (list1->val <= list2->val)//找出第一个
            {
                L = new ListNode(list1->val);
                head = L;
                list1 = list1->next;
            }
            else
            {
                L = new ListNode(list2->val);
                head = L;
                list2 = list2->next;
            }
            while (list1 != nullptr && list2 != nullptr)
            {
                if (list1->val <= list2->val)
                {
                    L->next = list1;
                    list1 = list1->next;
                    L = L->next;
                }
                else
                {
                    L->next = list2;
                    list2 = list2->next;
                    L = L->next;
                }
            }
            if (list1 != nullptr)
            {
                L->next = list1;
                L = L->next;
            }
            else
            {
                L->next = list2;
                L = L->next;
            }
            return head;
        }
    }
};
void trimLeftTrailingSpaces(string &input)
{
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch)
                                       { return !isspace(ch); }));
}

void trimRightTrailingSpaces(string &input)
{
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch)
                        { return !isspace(ch); })
                    .base(),
                input.end());
}

vector<int> stringToIntegerVector(string input)
{
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim))
    {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode *stringToListNode(string input)
{
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode *dummyRoot = new ListNode(0);
    ListNode *ptr = dummyRoot;
    for (int item : list)
    {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode *node)
{
    if (node == nullptr)
    {
        return "[]";
    }

    string result;
    while (node)
    {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        ListNode *list1 = stringToListNode(line);
        getline(cin, line);
        ListNode *list2 = stringToListNode(line);

        ListNode *ret = Solution().mergeTwoLists(list1, list2);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}