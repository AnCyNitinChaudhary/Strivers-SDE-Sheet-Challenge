//  int largestRectangle(vector < int > & heights) {
//    // Write your code here.
//    int ans=0;
//    int n=heights.size();
//    if(n<=0)return 0;
//    for(int i=0;i<n;i++){
//      int counti=0;
//      int j=i;
//      while(j<n&&heights[j]>=heights[i]){
//        counti++;
//        j++;
//      }
//       ans=max(ans,counti*heights[i]);
//    }
//    return ans;
//  }
int divideAndConquer(vector < int > & heights, int l, int r) {

    if (l == r) {
        return heights[l];
    }

    int mid = (l + r) / 2;
    int lscore = divideAndConquer(heights, l, mid);
    int rscore = divideAndConquer(heights, mid + 1, r);
    int lptr = mid, rptr = mid;
    int maxArea = 0;
    int minimum = heights[mid];
    while (lptr >= l && rptr <= r) {
        minimum = min(minimum, min(heights[lptr], heights[rptr]));
        maxArea = max(maxArea, minimum * (rptr - lptr + 1));
        if (lptr > l && rptr < r) {
            if (heights[rptr + 1] >= heights[lptr - 1]) {
                rptr++;
            } else {
                lptr--;
            }
        } else if (lptr > l) {
            lptr--;
        } else if (rptr < r) {
            rptr++;
        } else {
            rptr++;
            lptr--;
        }
    }
    return max(maxArea, max(lscore, rscore));
}

int largestRectangle(vector < int > & heights) {
    if (heights.size() == 0) {
        return 0;
    }
    return divideAndConquer(heights, 0, heights.size() - 1);
}
