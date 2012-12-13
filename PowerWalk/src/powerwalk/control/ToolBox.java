package powerwalk.control;

/**
 * Utility class providing shortcuts to standard commonly used tasks
 * @author P.Kramer
 */
public abstract class ToolBox {
    
    /**
     * returns the first index i was found in arr, or -1 if arr does not contain i
     * @param i the element to look for
     * @param arr the array to search in
     * @return the index of i in arr
     */
    public static int arrayIndexOf(int i, int[] arr) {
        for (int k=0;k<arr.length;k++) {
            if (arr[k] == i) return k;
        }
        return -1;
    }
    
    /**
     * returns the first index i was found in arr, or -1 if arr does not contain i.
     * <p>This method is faster than arrayIndexOf(), but requires the elements of 
     * the array to be sorted in ascending order.</p>
     * 
     * <p>Note that his method does not guarantee to give the index of the first 
     * matching element. The index of any matching element may be returned.</p>
     * 
     * <p>Please be aware that this method may not give the right answer when 
     * the array is not sorted. Only calls to this method with sorted arrays are 
     * guaranteed to return the right answer.</p>
     * @param i the element to look for
     * @param arr the array to search in
     * @return the index of i in arr
     */
    public static int sortedArrayIndexOf(int i,int[] arr) {
        int start=0, end=arr.length-1;
        int mid = (start+end) /2;
        
        while (start < end) {
            if (arr[mid] == i) return mid;
            if (arr[mid] < i) {
                start = mid;
                mid = (start+end)/2;
            } else {
                end = mid;
                mid = (start+end)/2;
            }
        }
        if (arr[start] == i) return start;
        else return -1;
    }
    
}
