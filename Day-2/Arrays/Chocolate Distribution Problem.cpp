/* We can generate subsets. and then find the difference between the highest element and lowest element. Then we will choose the subset with lowest difference.
It will be better if we sort the array and then we choose consecutive elements and find the difference between highest and lowest element*/

// n->packets , m->students
int findMinDif(int arr[], int n, int m){
  
  if(m==0||n==0){ 
    return -1;
    
  if(n<m){
    return -1;
  
  sort(arr, arr+n);
  int min_diff = INT_MAX;
    
  for(int i=0; i+m-1<n; i++){
    int diff = arr[i+m-1] - arr[i];
    if(diff < min_diff){
      min_diff = diff;
    }
  }
  return min_diff;    
}    
