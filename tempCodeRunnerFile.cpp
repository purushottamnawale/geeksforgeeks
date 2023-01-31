    {
        Node* prevptr;
        Node* currptr;
        Node* nextptr;

        while(currptr!=NULL){
            nextptr=currptr->next;
            currptr->next=prevptr;

            prevptr=currptr;
            currptr=nextptr;
        }
        return prevptr;
    }