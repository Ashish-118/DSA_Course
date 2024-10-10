 if (head == NULL)
        {
            cout << "Stack is empty\n";
            return;
        }
        Stack *temp = head;
        head = head->next;
        delete temp;