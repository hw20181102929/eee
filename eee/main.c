void BFS ( LGraph Graph, Vertex S, void (*Visit)(Vertex) )
{
    Visit(S);
    Visited[S]=true;
    int p[100];
    int front=0;
    int rear=0;
    p[rear++]=S;
    while(front!=rear)
    {
        int h=p[front++];
        struct AdjVNode * w;
        for(w=Graph->G[h].FirstEdge;w;w=w->Next)
        {
            if(Visited[w->AdjV]==false)
            {
                Visit(w->AdjV);
                Visited[w->AdjV]=true;
                p[rear++]=w->AdjV;
            }
        }
    }
}
void DFS( MGraph Graph, Vertex V, void (*Visit)(Vertex) )
{
    Visit(V);
    Visited[V]=true;
    for(int i=0;i<Graph->Nv;i++)
    {
        if(Graph->G[V][i]<MaxVertexNum&&Visited[i]==false)
        {
            DFS(Graph,i,Visit);
        }
    }
}
bool Delete( HashTable H, ElementType Key )
{
    int index;
    index=Hash(Key,H->TableSize);
    if(H->Heads[index].Next==NULL)
    {
        return false;
    }
    while(H->Heads[index].Next&&strcmp(Key,H->Heads[index].Next->Data)!=0)
    {
        H->Heads[index].Next=H->Heads[index].Next->Next;
    }
    if(H->Heads[index].Next)
    {
        List p;
        p=H->Heads[index].Next;
        H->Heads[index].Next=p->Next;
        printf("%s is deleted from list Heads[%d]\n",p->Data,index);
        free(p);
        return true;
    }
    else
    {
        return false;
    }
}
Position Find( HashTable H, ElementType Key )
{
    int index,tmp;
    index=tmp=Hash(Key,H->TableSize);
    while(H->Cells[index].Info!=Empty&&H->Cells[index].Data!=Key)
    {
        index++;
        if(index>=H->TableSize)
        {
            index%=H->TableSize;
        }
        if(index==tmp)
        {
            break;
        }
    }
    if(H->Cells[index].Info==Empty||H->Cells[index].Data==Key)
    {
        return index;
    }
    else
    {
        return ERROR;
    }
}
int rear;
int p[100];
bool IsBST ( BinTree T )
{
    if(T)
    {
        IsBST ( T->Left );
        p[rear++]=T->Data;
        IsBST ( T->Right );
        for(int i=0;i<rear;i++)
        {
            for(int j=i+1;j<rear;j++)
            {
                if(p[i]>p[j])
                {
                    return false;
                }
            }
        }
    }
    return true;
}
