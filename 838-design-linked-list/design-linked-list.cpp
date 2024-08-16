class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};

class MyLinkedList
{
public:
    Node *head;
    MyLinkedList() { head = NULL; }

    int get(int index)
    {
        Node *temp = head;
        int i = 0;
        while (temp != NULL)
        {
            if (i == index)
            {
                return temp->data;
            }

            i++;
            temp = temp->next;
        }
        return -1;
    }

    void addAtHead(int val)
    {
        Node *temp = new Node(val);
        temp->next = head;
        head = temp;
    }

    void addAtTail(int val)
    {

        Node *newNode = new Node(val);

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void addAtIndex(int index, int val)
    {
        Node *temp = head;
        if (index == 0)
        {
            addAtHead(val);
            return;
        }

        int count = 0;

        while (temp)
        {
            count++;

            if (count == index)
            {
                Node *newnode = new Node(val);
                newnode->next = temp->next;
                temp->next = newnode;
                break;
            }
            temp = temp->next;
        }
    }

    void deleteAtHead(Node *&head)
{
    if (head == NULL)
        return;

    Node *temp = head;

    head = head->next;

    delete temp;
}

void deleteAtTail(Node *&head)
{
    if (head == NULL)
        return;

    if (head->next == NULL)
    {
        delete head;
        return;
    }

    Node *temp = head;
    Node *p = NULL;

    while (temp->next != NULL)
    {
        p = temp;
        temp = temp->next;
    }

    p->next = NULL;
    delete temp;
}

    void deleteAtIndex(int index)
    {

        if (head == NULL)
            return;

        if (index == 0)
        {
            Node *tem = head;
            head = head->next;
            delete tem;
            return;
        }

        Node *temp = head;
        int count = 1;

        while (temp != NULL && count < index)
        {
            temp = temp->next;
            count++;
        }

        if (temp == nullptr || temp->next == nullptr)
        {
            return; // Handle cases where k is out of bounds or list is too short
        }

        Node *toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    }

};
/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */