int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    //Solve this question again to get proper intutions.
    sort(at,at+n);
    sort(dt,dt+n);
    int current=1;
    int maxi=1;
    int j=0;
    int i=1;
    while(i<n&&j<n){
      if (at[i] <= dt[j]) {
        current++;
        i++;
      } else{
        current--;
        j++;
      }
      maxi=max(maxi,current);
    }
    return maxi;
}
