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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *head = nullptr;
        ListNode *L = nullptr;
        int count = 0;
        for (int i = 0; i < lists.size(); i++)
        {
            count = i + 1;
            if (lists[i] == nullptr && lists[i + 1] == nullptr)
            {
                continue;
            }
            else if (lists[i] == nullptr && lists[i + 1] != nullptr)
            {
                L = lists[i + 1];
                break;
            }
            else if (lists[i] != nullptr && lists[i + 1] == nullptr)
            {
                L = lists[i];
                break;
            }
            else
            {
                if (lists[i]->val <= lists[i + 1]->val)
                {
                    L = new ListNode(lists[i]->val);
                    lists[i] = lists[i]->next;
                }
                else
                {
                    L = new ListNode(lists[i + 1]->val);
                    lists[i + 1] = lists[i + 1]->next;
                }
                while (lists[i] != nullptr && lists[i + 1] != nullptr)
                {
                    if (lists[i]->val <= lists[i + 1]->val)
                    {
                        L->next = lists[i];
                        lists[i] = lists[i]->next;
                        L = L->next;
                    }
                    else
                    {
                        L->next = lists[i + 1];
                        lists[i + 1] = lists[i + 1]->next;
                        L = L->next;
                    }
                }
                if (lists[i] != nullptr)
                {
                    L->next = lists[i];
                    L = L->next;
                }
                else
                {
                    L->next = lists[i + 1];
                    L = L->next;
                }
                break;
            }
        }
        if (count < lists.size())
        {
            for (int i = count; i < lists.size(); i++)
            {
                if (lists[i] == nullptr && lists[i + 1] == nullptr)
                {
                    continue;
                }
                else if (lists[i] == nullptr && lists[i + 1] != nullptr)
                {
                    L->next = new ListNode(lists[i + 1]->val);
                    L = L->next;
                }
                else if (lists[i] != nullptr && lists[i + 1] == nullptr)
                {
                    L->next = new ListNode(lists[i]->val);
                    L = L->next;
                }
                else
                {
                    if (lists[i]->val <= lists[i + 1]->val)
                    {
                        L->next = new ListNode(lists[i]->val);
                        lists[i] = lists[i]->next;
                        L = L->next;
                    }
                    else
                    {
                        L->next = new ListNode(lists[i + 1]->val);
                        lists[i + 1] = lists[i + 1]->next;
                        L = L->next;
                    }
                    while (lists[i] != nullptr && lists[i + 1] != nullptr)
                    {
                        if (lists[i]->val <= lists[i + 1]->val)
                        {
                            L->next = lists[i];
                            lists[i] = lists[i]->next;
                            L = L->next;
                        }
                        else
                        {
                            L->next = lists[i + 1];
                            lists[i + 1] = lists[i + 1]->next;
                            L = L->next;
                        }
                    }
                    if (lists[i] != nullptr)
                    {
                        L->next = lists[i];
                        L = L->next;
                    }
                    else
                    {
                        L->next = lists[i + 1];
                        L = L->next;
                    }
                }
            }
        }
        return head;
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

        ListNode *ret = Solution().mergeKLists(lists);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}