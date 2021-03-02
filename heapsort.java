class Solution
{
    void buildHeap(int arr[], int n)
    {
        // Your code here
        

    }
 
    // To heapify a subtree rooted with node i which is
    // an index in arr[]. n is size of heap
    void heapify(int arr[], int n, int i)
    {
        // Your code here
        for(; i < n; i++){
        //left node larger than the parent swap
        if(arr[i] > arr[2*i+1]){
            int temp = arr[i];
            arr[i] = arr[2*i+1];
            arr[2*i+1] = temp;
        }
        if(arr[i] > arr[2*i+2])
        {
            int temp = arr[i];
            arr[i] = arr[2*i+2];
            arr[2*i+2] = temp;
        }
        }        
    }
    
    public void heapSort(int arr[], int n)
    {
        //code here
    }
 }
