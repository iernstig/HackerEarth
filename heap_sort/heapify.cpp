void heapify()
{
    int max=0,max1=0;
    // check if list is less 3 and cout << -1
    int i,par;
    i=ptr;
    par=(i-1)/2;
    while(par>=0&&heap[par]<heap[i])
    {
        swap(i,par);
        i=par;
        par=(i-1)/2;
    }
    max=heap[1]>heap[2]?heap[1]:heap[2];
    max1=heap[1]^heap[2]^max;
    for(i=3;i<7&&i<ptr+1;i++)
    if(heap[i]>max1)
    max1=heap[i];
    cout<<heap[0]<<" "<<max<<" "<<max1<<"\n";
}
