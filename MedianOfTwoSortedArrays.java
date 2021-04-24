class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        
        if(nums1.length <= nums2.length)
            return search(nums1, nums2, 0, nums1.length-1);
        
        return search(nums2, nums1, 0, nums2.length-1);
    }
    
    int val(int[] a, int i) { //for handling out of bound index also
        if(i < 0)           return Integer.MIN_VALUE;
        if(i >= a.length)   return Integer.MAX_VALUE;
        else                return a[i];
    }


    double search(int a[], int b[], int l, int r) { // Modified Binary Search
        
        int x = l + (r-l)/2; // mid of binary search
        int y = ((a.length + b.length + 1) / 2) - x;


        if(val(a, x-1) <= val(b, y) && val(b, y-1) <= val(a, x))  {
            
            if((a.length + b.length) % 2 == 0)
                return (double) (Math.min(val(a, x), val(b, y)) + Math.max(val(a, x-1), val(b, y-1))) / 2;

            return  Math.max(val(a, x-1), val(b, y-1));
        }
        else if(val(a, x-1) > val(b, y)) 
            r = x-1;
        else 
            l = x+1;


        return search(a, b, l, r);
    }
}
