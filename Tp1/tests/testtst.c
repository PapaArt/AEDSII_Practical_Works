#include "testtst.h"

TSTNode init(tipoTST *raiz)
{
    tipoTST temp = (tipoTST)malloc(sizeof(TSTNode));
    temp->end_of_string = 0;
    temp->left = temp->right = temp->middle = NULL;
}

TSTNode *insert(TSTNode *head, char* str, int idx)
{
    if (idx == strlen(str))
    {
        if (head == NULL)
            *head = init(head);
        head->end_of_string = true;
        return head;
    }
    if (head == NULL)
    {
        *head = init(head);
        head->value = str[idx];
    }
    if (str[idx] == head->value)
        head->middle = insert(head->middle, str, idx + 1);
    else if (str[idx] > head->value)
        head->right = insert(head->right, str, idx);
    else
        head->left = insert(head->left, str, idx);
    return head;
}

bool search(tipoTST* raiz, char* str)
{
    TSTNode *root = raiz;
    int n = strlen(str);
    int i = 0;
    while (i < n)
    {
        if (root == NULL)
            return 0;
        if (root->value == str[i])
        {
            root = root->middle;
            i++;
            continue;
        }
        if (root->value < str[i])
            root = root->right;
        else
            root = root->left;
    }
    return root->end_of_string;
}

char* bfs(tipoTST* raiz, char* str)
{
    char* ret;
    queue<pair<TSTNode *, pair<string, int>>> q;
    TSTNode *cur = raiz;
    q.push({cur, {str, 1}});
    while (!q.empty())
    {
        TSTNode *cur = q.front().first;
        string str = q.front().second.first;
        bool add = q.front().second.second;
        q.pop();
        if (cur->end_of_string == true && add == true)
        {
            ret.push_back(str);
        }
        if (ret.size() == MX_SIZE)
            break;
        if (cur->left != NULL)
            q.push({cur->left, {str, 0}});
        if (cur->middle != NULL)
            q.push({cur->middle, {str + cur->value, 1}});
        if (cur->right != NULL)
            q.push({cur->right, {str, 0}});
    }
    return ret;
}
char* AutoComplete(char* str)
{
    char* ret;
    TSTNode *root = this;
    int n = str.length();
    int i = 0;
    while (i < n)
    {
        if (root == NULL)
            return ret;
        if (root->value == str[i])
        {
            root = root->middle;
            i++;
            continue;
        }
        if (root->value < str[i])
            root = root->right;
        else
            root = root->left;
    }
    return root->bfs(str);
}