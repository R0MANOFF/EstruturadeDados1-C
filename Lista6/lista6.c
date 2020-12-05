int sllInsertBeforeSpec(SLList *list, void *key, int(*cmp)(void*, void*), void *data){
    SLNode *spec = NULL, *ant = NULL, *newNode = NULL;
    if(list!=NULL){
        if(list->first!=NULL){
            spec = list->first;
            while(spec->next!=NULL && !cmp(key, spec->data)){
                ant = spec;
                spec = spec->next;
            }
            if(cmp(key, spec->data)){
                newNode = (SLNode*)malloc(sizeof(SLNode));
                if(newNode!=NULL){
                    newNode->data = data;
                    if(ant==NULL){
                        newNode->next = spec;
                        list->first = newNode;
                    }else{
                        ant->next = newNode;
                        newNode->next = spec;
                    }
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

void *sllRemoveAfterSpec(SLList *list, void *key, int(*cmp)(void*, void*)){
    SLNode *spec = NULL, *newNode = NULL;
    if(list!=NULL){
        if(list->first!=NULL){
            spec = list->first;
            while(spec->next!=NULL && !cmp(key, spec->data)){
                spec = spec->next;
            }
            if(cmp(key, spec->data)){
                if(spec->next==NULL)
                    return NULL;
                SLNode *temp = spec->next;
                spec->next = temp->next;
                void *returnData = temp->data;
                free(temp);
                return returnData;
            }
        }
    }
    return NULL;
}